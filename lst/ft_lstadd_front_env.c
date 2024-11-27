/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:09:11 by haghouli          #+#    #+#             */
/*   Updated: 2023/03/04 15:21:24 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lstadd_front_env(t_env **lst, t_env *new)
{
	if (new == 0)
		return ;
	new->next = *lst;
	*lst = new;
}