/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:55:06 by haghouli          #+#    #+#             */
/*   Updated: 2023/03/04 15:21:39 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*ft_lstlast_env(t_env *lst)
{
	t_env	*t;

	if (lst == NULL)
		return (NULL);
	t = lst;
	while (t->next != NULL)
		t = t->next;
	return (t);
}
