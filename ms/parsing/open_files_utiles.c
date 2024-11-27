/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files_utiles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:05:38 by mtadlaou          #+#    #+#             */
/*   Updated: 2023/03/29 16:46:50 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void	do_while(char *s, int *i)
{
	if (s[*i] == '"' || s[*i] == '\'')
	{
		(*i)++;
		while (s[*i] != '\'' && s[*i] != '"')
			(*i)++;
	}
	while (s[*i] && s[*i] != '<' && s[*i] != '>' && s[*i] != '|' && s[*i] != ' '
		&& s[*i] != '\\')
		(*i)++;
}

int	ambiguous(t_split **p, t_split *tmp, t_list *head)
{
	print_error("ambiguous redirect\n");
	ft_lstremove(p, tmp->str);
	ft_lstremove(p, tmp->next->str);
	head->error = -1;
	return (1);
}

void	in_trunc_fun(t_list *head, char *s1)
{
	if (!ft_strcmp(s1, "/dev/stdin"))
		head->infile = 0;
	else if (!ft_strcmp(s1, "/dev/stderr"))
		head->infile = 2;
	else if (!ft_strcmp(s1, "/dev/stdout"))
		head->infile = 1;
	else
		head->infile = open(s1, O_RDONLY, 0644);
}

void	out_trunc_fun(t_list *head, char *s1)
{
	if (!ft_strcmp(s1, "/dev/stdin"))
		head->outfile = 0;
	else if (!ft_strcmp(s1, "/dev/stderr"))
		head->outfile = 2;
	else if (!ft_strcmp(s1, "/dev/stdout"))
		head->outfile = 1;
	else
		head->outfile = open(s1, O_WRONLY | O_TRUNC | O_CREAT, 0644);
}

void	out_append_fun(t_list *head, char *s1)
{
	if (!ft_strcmp(s1, "/dev/stdin"))
		head->infile = 0;
	else if (!ft_strcmp(s1, "/dev/stderr"))
		head->infile = 2;
	else if (!ft_strcmp(s1, "/dev/stdout"))
		head->infile = 1;
	else
		head->outfile = open(s1, O_WRONLY | O_APPEND | O_CREAT, 0644);
}
