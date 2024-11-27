/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove_if_env.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 09:03:08 by haghouli          #+#    #+#             */
/*   Updated: 2023/03/28 16:00:20 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	ft_lstremove_if_env(t_env *env, char *to_delete)
{
	char	*cmd;
	t_env	*tmp;

	if (!ft_strcmp(env->var, to_delete))
		tmp = env;
	else
	{
		while (env->next)
		{
			if (!ft_strcmp(env->next->var, to_delete))
			{
				tmp = env->next;
				env->next = env->next->next;
				ft_lstdelone(tmp, free);
			}
			env = env->next;
		}
	}
}
