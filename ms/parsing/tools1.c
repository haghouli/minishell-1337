/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtadlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:11:10 by mtadlaou          #+#    #+#             */
/*   Updated: 2023/03/29 14:05:00 by mtadlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

int	check_the_list(t_split *p, int i)
{
	while (p)
	{
		if (i == 0 && p->type == 'r')
			return (1);
		else if (i == 1 && !ft_strcmp(p->str, "$"))
			return (1);
		p = p->next;
	}
	return (0);
}

int	check_str(char *s)
{
	if (!ft_strcmp(s, "<") || !ft_strcmp(s, "<<")
		|| !ft_strcmp(s, ">") || !ft_strcmp(s, ">>"))
		return (1);
	return (0);
}

int	check_redection(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if ((s[i] == '<' && s[i + 1] == '<') || (s[i] == '>' && s[i + 1] == '>')
			|| s[i] == '<' || s[i] == '>')
			return (1);
	}
	return (0);
}

void	doc_to_redection(t_split *p)
{
	while (p)
	{
		if (!ft_strcmp(p->str, "<<") && p->type == 'r')
		{
			free(p->str);
			p->str = ft_strdup("<");
		}
		p = p->next;
	}
}

void	get_the_type(t_split *p)
{
	while (p)
	{
		if (!ft_strcmp(p->str, "<<"))
			p->next->doc = 0;
		if (check_str(p->str))
			p->type = 'r';
		else
			p->type = 's';
		p = p->next;
	}
}
