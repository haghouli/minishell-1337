/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtadlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:12:16 by mtadlaou          #+#    #+#             */
/*   Updated: 2023/03/29 13:23:07 by mtadlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

int	check_argument(char **s)
{
	DIR	*dir;

	if (!s)
		return (1);
	dir = opendir(s[0]);
	if (dir == NULL)
		return (1);
	else
	{
		if (!ft_strcmp(".", s[0]))
		{
			g_status = 2;
			print_error("minishell: ");
			print_error(".: filename argument required\n");
			print_error(".: usage: . filename [arguments]\n");
			return (0);
		}
		g_status = 126;
		print_error("minishell: ");
		print_error(s[0]);
		print_error(": is a directory\n");
		closedir(dir);
		return (0);
	}
}

void	ft_lstadd_syntax(t_syntax **lst, t_syntax *new)
{
	t_syntax	*p;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	p = *lst;
	while (p->next != NULL)
		p = p->next;
	p->next = new;
}

t_syntax	*ft_newlist(char c, int *i, int d)
{
	t_syntax	*head;

	head = (t_syntax *)malloc(sizeof(t_syntax));
	if (head == NULL)
		return (NULL);
	head->c = c;
	head->next = NULL;
	if (d == 1)
		*i = *i + 2;
	else if (d != 2)
		*i = *i + 1;
	return (head);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1)
		return (-1);
	else if (!s2)
		return (1);
	while ((s1[i] == s2[i]) && (s1[i] || s2[i]))
		i++;
	return (s1[i] - s2[i]);
}
