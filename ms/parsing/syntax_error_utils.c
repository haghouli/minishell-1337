/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtadlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:09:41 by mtadlaou          #+#    #+#             */
/*   Updated: 2023/03/29 13:24:00 by mtadlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void	ft_skeep_space(char *s, int *i)
{
	while (s[*i] == ' ')
		(*i)++;
}

char	*all_cases(t_syntax *p)
{
	if (!check_newline(p))
		return (ft_strdup("syntax error near unexpected token `newline'\n"));
	else if (!check_append(p))
		return (ft_strdup("syntax error near unexpected token `>>'\n"));
	else if ((p->c == 'p' && p->next->c == 'p') || (p->c == 'i'
			&& p->next->c == 'o' && p->next->next->c == 'p'))
		return (ft_strdup("syntax error near unexpected token `|'\n"));
	else if (!check_out(p))
		return (ft_strdup("syntax error near unexpected token `>'\n"));
	else if (!check_in(p))
		return (ft_strdup("syntax error near unexpected token `<'\n"));
	else if ((p->c == 'h' && p->next->c == 'b') || (p->c == 'a'
			&& p->next->c == 'b') || (p->c == 'i' && p->next->c == 'b')
		|| (p->c == 'o' && p->next->c == 'b'))
		return (ft_strdup("syntax error near unexpected token `\\'\n"));
	else if ((p->c == 's' && p->next && p->next->c == 'b'))
		return (ft_strdup("syntax error near unexpected token `\\'\n"));
	else if (!check_herdoc(p))
		return (ft_strdup("syntax error near unexpected token `>>'\n"));
	return (NULL);
}

void	max_herdoc(t_syntax *p, int *c)
{
	if (p->c == 'h')
		(*c)++;
	if (*c > 16)
	{
		print_error("minishell: ");
		print_error("maximum here-document count exceeded\n");
		exit(2);
	}
}

t_syntax	*get_last(t_syntax *p)
{
	while (p->next)
		p = p->next;
	return (p);
}

void	free_syntax_list(t_syntax **lst)
{
	t_syntax	*p;
	t_syntax	*t;

	if (lst == NULL || *lst == NULL)
		return ;
	t = *lst;
	p = *lst;
	while (p != NULL)
	{
		p = p->next;
		free(t);
		t = p;
	}
	*lst = NULL;
}
