/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtadlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:01:24 by mtadlaou          #+#    #+#             */
/*   Updated: 2023/03/28 13:19:35 by mtadlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void	ft_lstdelone3(t_herdoc *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	(*del)(lst->doc);
	free(lst);
}

void	ft_lstdelone2(t_split *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	(*del)(lst->str);
	free(lst);
}

void	ft_lstclear2(t_split **lst)
{
	t_split	*p;
	t_split	*t;

	if (lst == NULL || *lst == NULL)
		return ;
	t = *lst;
	p = *lst;
	while (p != NULL)
	{
		p = p->next;
		free(t->str);
		free(t);
		t = p;
	}
	*lst = NULL;
}

void	free_list(t_list **lst)
{
	t_list	*p;
	t_list	*t;

	if (lst == NULL || *lst == NULL)
		return ;
	t = *lst;
	p = *lst;
	while (p != NULL)
	{
		p = p->next;
		free_2d_table(t->cmd);
		free(t);
		t = p;
	}
	*lst = NULL;
}

void	ft_lstremove(t_split **p, char *to_delete)
{
	t_split	*tmp;
	t_split	*tmp1;

	tmp = *p;
	tmp1 = tmp->next;
	if ((*p)->str == to_delete)
	{
		*p = (*p)->next;
		ft_lstdelone2(tmp, &free);
		return ;
	}
	while (tmp)
	{
		if (tmp1->str == to_delete)
		{
			tmp->next = tmp1->next;
			ft_lstdelone2(tmp1, &free);
			return ;
		}
		tmp = tmp->next;
		tmp1 = tmp->next;
	}
}
