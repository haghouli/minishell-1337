/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtadlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:09:32 by mtadlaou          #+#    #+#             */
/*   Updated: 2023/03/29 14:06:28 by mtadlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void	fill_syntax_list(t_syntax **p, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_skeep_space(s, &i);
		if (s[i] == '<' && s[i + 1] != '\0' && s[i + 1] == '<')
			ft_lstadd_syntax(p, ft_newlist('h', &i, 1));
		else if (s[i] == '>' && s[i + 1] != '\0' && s[i + 1] == '>')
			ft_lstadd_syntax(p, ft_newlist('a', &i, 1));
		else if (s[i] == '>')
			ft_lstadd_syntax(p, ft_newlist('o', &i, 0));
		else if (s[i] == '<')
			ft_lstadd_syntax(p, ft_newlist('i', &i, 0));
		else if (s[i] == '|')
			ft_lstadd_syntax(p, ft_newlist('p', &i, 0));
		else if (s[i] == '\\')
			ft_lstadd_syntax(p, ft_newlist('b', &i, 0));
		else if (s[i] && s[i] != ' ')
		{
			ft_lstadd_syntax(p, ft_newlist('s', &i, 2));
			do_while(s, &i);
		}
	}
}

char	*check_syntax(t_syntax *p)
{
	int		c;
	char	*str;

	c = 0;
	if (p && (p->c == 'p' || get_last(p)->c == 'p'))
		return (ft_strdup("syntax error near unexpected token `|'\n"));
	while (p)
	{
		str = all_cases(p);
		if (str != NULL)
			return (str);
		max_herdoc(p, &c);
		p = p->next;
	}
	return (ft_strdup("1"));
}

char	*check_string(char *s)
{
	t_syntax	*p;
	char		*str;

	p = NULL;
	fill_syntax_list(&p, s);
	str = check_syntax(p);
	free_syntax_list(&p);
	return (str);
}

int	check_quote(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == '"')
		{
			i++;
			while (s[i] && s[i] != '"')
				i++;
			if (!s[i])
				return (0);
		}
		if (s[i] == '\'')
		{
			i++;
			while (s[i] && s[i] != '\'')
				i++;
			if (!s[i])
				return (0);
		}
	}
	return (1);
}

int	syntax_error(char *s)
{
	char	*str;

	if (!check_quote(s))
	{
		g_status = 258;
		print_error("minishell: ");
		print_error("syntax error : quote not close \n");
		return (0);
	}
	str = check_string(s);
	if (ft_strcmp(str, "1"))
	{
		g_status = 258;
		print_error("minishell: ");
		print_error(str);
		free(str);
		return (0);
	}
	free(str);
	return (1);
}
