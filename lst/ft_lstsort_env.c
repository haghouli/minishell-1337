/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:40:16 by haghouli          #+#    #+#             */
/*   Updated: 2023/03/28 16:00:47 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	ft_swap(t_env *env)
{
	char	*tmp;
	char	*tmp2;

	tmp = env->var;
	tmp2 = env->value;
	env->var = env->next->var;
	env->value = env->next->value;
	env->next->var = tmp;
	env->next->value = tmp2;
}

void	ft_lstsort_env(t_env **env)
{
	t_env	*tmp;
	int		i;

	i = 0;
	while (i < ft_lstsize_env(*env))
	{
		tmp = *env;
		while (tmp->next)
		{
			if (ft_strcmp(tmp->var, tmp->next->var) > 0)
				ft_swap(tmp);
			tmp = tmp->next;
		}
		i++;
	}
}
