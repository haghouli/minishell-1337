/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:06:32 by haghouli          #+#    #+#             */
/*   Updated: 2023/03/04 15:21:31 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lstdelone_env(t_env *lst, void (*del)(void *))
{
	if (del == NULL || lst == NULL)
		return ;
	del(lst->var);
	del(lst->value);
	free(lst);
}
