/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtadlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:00:46 by mtadlaou          #+#    #+#             */
/*   Updated: 2023/03/28 13:19:27 by mtadlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void	_string_to_list_(t_split **p, int *i, char *str, int d)
{
	int	start;
	int	end;

	if (d == 1)
	{
		start = *i;
		while (str[*i] && !ft_isalpha(str[*i]) && !ft_isdigit(str[*i])
			&& str[*i] != '$')
			(*i)++;
		end = *i;
		ft_lstadd_back2(p, ft_lstnew2(ft_substr(str, start, end - start)));
	}
	else
	{
		start = *i;
		while (str[*i] && (ft_isalpha(str[*i]) || ft_isdigit(str[*i]))
			&& str[*i] != '$')
			(*i)++;
		end = *i;
		ft_lstadd_back2(p, ft_lstnew2(ft_substr(str, start, end - start)));
	}
}

t_split	*_turn_string_to_list_(char *str)
{
	int		i;
	t_split	*p;

	i = 0;
	p = NULL;
	while (str[i])
	{
		if (str[i] == '$')
		{
			ft_lstadd_back2(&p, ft_lstnew2(ft_strdup("$")));
			i++;
		}
		if (str[i] && !ft_isalpha(str[i]) && !ft_isdigit(str[i])
			&& str[i] != '$')
		{
			_string_to_list_(&p, &i, str, 1);
		}
		else if (str[i] && str[i] != '$')
		{
			_string_to_list_(&p, &i, str, 0);
		}
	}
	free(str);
	return (p);
}

char	*strat_the_expend(char *s, t_env *env)
{
	char	*tmp;

	if (!ft_strcmp(s, "?"))
		return (free(s), ft_itoa(g_status));
	if (!ft_isalpha(s[0]) && !ft_isdigit(s[0]) && s[0] != '$')
	{
		tmp = ft_strjoin("$", s);
		return (free(s), tmp);
	}
	while (env)
	{
		if (!ft_strcmp(s, env->var))
		{
			free(s);
			return (ft_strdup(env->value));
		}
		env = env->next;
	}
	return (free(s), ft_strdup(""));
}

char	*helper(t_split *p)
{
	t_split	*tmp2;
	char	*new;
	char	*str;

	new = NULL;
	tmp2 = p;
	while (p)
	{
		str = ft_strjoin(new, p->str);
		free(new);
		new = str;
		p = p->next;
	}
	ft_lstclear2(&tmp2);
	return (new);
}

char	*do_expanding(char *s, t_env *env)
{
	t_split	*p;
	t_split	*tmp;

	if (!ft_strcmp(s, "$"))
		return (free(s), ft_strdup(""));
	p = _turn_string_to_list_(s);
	tmp = p;
	while (check_the_list(p, 1))
	{
		tmp = p;
		while (tmp)
		{
			if (!ft_strcmp(tmp->str, "$"))
			{
				if (!tmp->next)
					return (ft_lstclear2(&p), ft_strdup("$"));
				tmp->next->str = strat_the_expend(tmp->next->str, env);
				ft_lstremove(&p, tmp->str);
			}
			tmp = tmp->next;
		}
	}
	return (helper(p));
}
