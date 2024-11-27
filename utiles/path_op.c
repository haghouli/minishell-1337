/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:46:34 by haghouli          #+#    #+#             */
/*   Updated: 2023/03/29 15:07:20 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**p3(t_env *env, char *str)
{
	char	**paths;

	paths = ft_split(env->value, ':');
	if (str == NULL && env->value[0] == ':')
		paths = copy_plus_one(paths);
	free(str);
	return (paths);
}

char	**get_paths(t_env *env)
{
	char	*str;
	char	**paths;

	paths = NULL;
	while (env)
	{
		if (!ft_strcmp(env->var, "PATH"))
		{
			str = check_pointes(env->value);
			if (str)
			{
				paths = ft_split(str, ':');
				free(str);
				return (paths);
			}
			else
				return (p3(env, str));
		}
		env = env->next;
	}
	return (NULL);
}

char	*get_true_path(char **paths, char *cmd)
{
	int		i;
	char	*tmp;
	char	*true_path;

	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		true_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!access(true_path, F_OK))
			return (true_path);
		free(true_path);
		true_path = NULL;
		i++;
	}
	return (NULL);
}

int	is_path_command(char *cmd)
{
	if (ft_strnstr(cmd, "/", 1))
		return (1);
	return (0);
}
