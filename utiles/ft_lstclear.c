/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:38:30 by haghouli          #+#    #+#             */
/*   Updated: 2023/03/29 11:35:31 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lstclear_env(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (*lst == NULL || del == NULL)
		return ;
	while (lst)
	{
		tmp = *lst;
		lst = (*lst)->next;
		ft_free(tmp->cmd);
		free(lst);
	}
	lst = NULL;
}
