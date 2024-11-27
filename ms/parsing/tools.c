/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtadlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:10:56 by mtadlaou          #+#    #+#             */
/*   Updated: 2023/03/28 13:20:21 by mtadlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void	ft_lstadd_back2(t_split **lst, t_split *new)
{
	t_split	*p;

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

void	ft_lstadd_back3(t_herdoc **lst, t_herdoc *new)
{
	t_herdoc	*p;

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

t_split	*ft_lstnew2(char *s)
{
	t_split	*head;

	head = (t_split *)malloc(sizeof(t_split));
	if (head == NULL)
		return (NULL);
	head->str = s;
	head->am = 0;
	head->doc = 1;
	head->next = NULL;
	return (head);
}

t_herdoc	*ft_lstnew3(char *s)
{
	t_herdoc	*head;

	head = (t_herdoc *)malloc(sizeof(t_herdoc));
	if (head == NULL)
		return (NULL);
	head->doc = s;
	head->next = NULL;
	return (head);
}

t_list	*ft_new(t_split **p, t_env *env)
{
	t_list	*head;

	head = (t_list *)malloc(sizeof(t_list));
	if (head == NULL)
		return (NULL);
	head->infile = 0;
	head->outfile = 1;
	head->error = 1;
	*p = open_and_remove(head, *p, env);
	head->cmd = get_cmd(p);
	if (check_argument(head->cmd) == 0)
	{
		free_2d_table(head->cmd);
		head->cmd = NULL;
	}
	head->next = NULL;
	return (head);
}
