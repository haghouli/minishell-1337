/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtadlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:05:50 by mtadlaou          #+#    #+#             */
/*   Updated: 2023/03/28 13:20:03 by mtadlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void	file_descriptor(t_list *head, int fd, char *s1)
{
	if (fd == -1)
	{
		write(2, s1, ft_strlen(s1));
		perror(" ");
		g_status = 1;
		head->error = -1;
	}
}

void	close_fd(int fd)
{
	if (fd != 0 && fd != 1)
		close(fd);
	else
		return ;
}

void	ft_open(t_list *head, char *s1, char *s2)
{
	if (!ft_strcmp(s2, "<"))
	{
		close_fd(head->infile);
		in_trunc_fun(head, s1);
		file_descriptor(head, head->infile, s1);
	}
	else if (!ft_strcmp(s2, ">"))
	{
		close_fd(head->outfile);
		out_trunc_fun(head, s1);
		file_descriptor(head, head->outfile, s1);
	}
	else if (!ft_strcmp(s2, ">>"))
	{
		close_fd(head->outfile);
		out_append_fun(head, s1);
		file_descriptor(head, head->outfile, s1);
	}
}

int	check_open(t_list *head, t_split *tmp, t_split **p)
{
	if (tmp->next->am == 1 && ft_strchr(tmp->next->str, ' '))
		return (ambiguous(p, tmp, head));
	else if (ft_strcmp(tmp->str, "<") == 0 && tmp->type == 'r')
	{
		ft_open(head, tmp->next->str, "<");
		ft_lstremove(p, tmp->str);
		ft_lstremove(p, tmp->next->str);
		return (1);
	}
	else if (ft_strcmp(tmp->str, ">") == 0 && tmp->type == 'r')
	{
		ft_open(head, tmp->next->str, ">");
		ft_lstremove(p, tmp->str);
		ft_lstremove(p, tmp->next->str);
		return (1);
	}
	else if (ft_strcmp(tmp->str, ">>") == 0 && tmp->type == 'r')
	{
		ft_open(head, tmp->next->str, ">>");
		ft_lstremove(p, tmp->str);
		ft_lstremove(p, tmp->next->str);
		return (1);
	}
	return (0);
}

t_split	*open_and_remove(t_list *head, t_split *p, t_env *env)
{
	t_split	*tmp;

	get_the_type(p);
	qoute_handling(p, env);
	doc_to_redection(p);
	while (head->error == 1 && check_the_list(p, 0) != 0)
	{
		tmp = p;
		while (tmp)
		{
			if (tmp->type == 'r' && check_open(head, tmp, &p) == 1)
				break ;
			tmp = tmp->next;
		}
	}
	if (head->error != 1)
	{
		ft_lstclear2(&p);
		return (NULL);
	}
	return (p);
}
