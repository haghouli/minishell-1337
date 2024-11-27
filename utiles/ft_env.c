/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 08:36:37 by haghouli          #+#    #+#             */
/*   Updated: 2023/03/27 11:14:22 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_env(t_env *env, t_list *lst)
{
	if (arr_size(lst->cmd) > 1)
		file_not_found("env", lst->cmd[1]);
	else
	{
		while (env)
		{
			if (env->value != NULL)
				printf("%s=%s\n", env->var, env->value);
			env = env->next;
		}
		g_status = 0;
	}
}
