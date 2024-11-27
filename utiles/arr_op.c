/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:05:21 by haghouli          #+#    #+#             */
/*   Updated: 2023/03/24 14:43:15 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	arr_size(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

char	**copy_lst_to_array(t_env *env)
{
	char	**arr;
	char	*tmp;
	int		i;

	i = 0;
	arr = malloc((ft_lstsize_env(env) + 1) * sizeof(char *));
	while (env)
	{
		tmp = ft_strjoin(env->var, "=");
		arr[i++] = ft_strjoin(tmp, env->value);
		env = env->next;
		free(tmp);
	}
	arr[i] = NULL;
	return (arr);
}
