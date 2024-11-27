/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc_utiles1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtadlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:02:40 by mtadlaou          #+#    #+#             */
/*   Updated: 2023/03/28 13:19:47 by mtadlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void	free_saver(t_save **lst)
{
	t_save	*p;
	t_save	*t;

	if (lst == NULL || *lst == NULL)
		return ;
	t = *lst;
	p = *lst;
	while (p != NULL)
	{
		p = p->next;
		ft_lstclear2(&t->list);
		free(t);
		t = p;
	}
	*lst = NULL;
}

void	free_herdoc(t_herdoc **lst)
{
	t_herdoc	*p;
	t_herdoc	*t;

	if (lst == NULL || *lst == NULL)
		return ;
	t = *lst;
	p = *lst;
	while (p != NULL)
	{
		p = p->next;
		free(t->doc);
		free(t);
		t = p;
	}
	*lst = NULL;
}

int	remove_herdoc_files(t_herdoc **doc)
{
	t_herdoc	*tmp;

	tmp = *doc;
	while (tmp)
	{
		unlink(tmp->doc);
		tmp = tmp->next;
	}
	free_herdoc(doc);
	return (0);
}

t_save	*fill_list(t_split *p)
{
	t_save	*head;

	head = (t_save *)malloc(sizeof(t_save));
	if (head == NULL)
		return (NULL);
	head->list = p;
	head->next = NULL;
	return (head);
}

void	generate_list(t_save **save, t_save *new)
{
	t_save	*p;

	if (save == NULL || new == NULL)
		return ;
	if (*save == NULL)
	{
		*save = new;
		return ;
	}
	p = *save;
	while (p->next != NULL)
		p = p->next;
	p->next = new;
}
