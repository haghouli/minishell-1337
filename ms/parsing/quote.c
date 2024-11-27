/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtadlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:06:08 by mtadlaou          #+#    #+#             */
/*   Updated: 2023/03/29 13:29:55 by mtadlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

char	*no_quote(char *s, int *j, t_env *env)
{
	char	*str;
	int		start;
	int		end;

	start = *j;
	while (s[*j] && s[*j] != '\"' && s[*j] != '\'')
		(*j)++;
	end = *j;
	str = ft_substr(s, start, end - start);
	if (s[*j])
		(*j)--;
	if (ft_strchr(s, '$') && ft_strcmp(s, "$"))
	{
		free(str);
		return (do_expanding(ft_substr(s, start, end - start), env));
	}
	return (str);
}

char	*keep_handling_quote(char *s, int *j, char c, t_env *env)
{
	char	*str;
	int		start;
	int		end;

	if (c == '0')
		return (no_quote(s, j, env));
	else
	{
		(*j)++;
		start = *j;
		while (s[*j] != c)
			(*j)++;
		end = (*j);
		str = ft_substr(s, start, end - start);
		if (ft_strchr(str, '$') && c != '\'' && ft_strcmp(str, "$"))
			str = do_expanding(str, env);
		return (str);
	}
}

void	ft_put(char **s1, char **s2, int i, t_split **p)
{
	if (i != 0)
	{
		free(*s1);
		*s1 = *s2;
		*s2 = NULL;
	}
	*p = (*p)->next;
}

void	qoute_handling(t_split *p, t_env *env)
{
	t_norn	n;

	while (p)
	{
		n.i = -1;
		n.str = NULL;
		while (p->doc != 0 && p->str[++(n.i)])
		{
			if (p->str[n.i] == '\"')
				n.s2 = keep_handling_quote(p->str, &n.i, '\"', env);
			else if (p->str[n.i] == '\'')
				n.s2 = keep_handling_quote(p->str, &n.i, '\'', env);
			else
			{
				n.s2 = keep_handling_quote(p->str, &n.i, '0', env);
				p->am = 1;
			}
			n.tmp1 = ft_strjoin(n.str, n.s2);
			(free(n.str), free(n.s2));
			n.str = n.tmp1;
		}
		ft_put(&p->str, &n.str, p->doc, &p);
	}
}
