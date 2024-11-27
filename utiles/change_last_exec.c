/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_last_exec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtadlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:21:05 by haghouli          #+#    #+#             */
/*   Updated: 2023/03/29 15:21:52 by mtadlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	change_exec(t_env *env, char *str)
{
	while (env)
	{
		if (!ft_strcmp("_", env->var))
		{
			free(env->value);
			env->value = str;
		}
		env = env->next;
	}
}

void	inset_path(char **str, char **paths)
{
	char	*tmp;

	tmp = *str;
	*str = get_true_path(paths, *str);
	if (*str)
		free(tmp);
	else
		*str = tmp;
}

void	change_last_exec(t_env *env, char *str)
{
	char	**paths;

	paths = NULL;
	if (!is_built_in(str) && !is_path_command(str))
	{
		if (!ft_strcmp("env", str))
		{
			free(str);
			str = ft_strdup("/usr/bin/env");
		}
		else
		{
			paths = get_paths(env);
			if (paths != NULL)
			{
				inset_path(&str, paths);
				ft_free(paths);
			}
		}
	}
	change_exec(env, str);
}
