/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:22:51 by haghouli          #+#    #+#             */
/*   Updated: 2023/03/29 14:53:57 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_non_path_cmd(t_list *lst, t_env *env)
{
	char	**paths;
	char	*true_path;

	paths = get_paths(env);
	if (paths == NULL)
		return (ft_free(paths), command_not_found(lst->cmd[0]), 127);
	else
	{
		true_path = get_true_path(paths, lst->cmd[0]);
		if (true_path == NULL || lst->cmd[0][0] == '.')
			return (command_not_found(lst->cmd[0]), ft_free(paths), 127);
		free(lst->cmd[0]);
		lst->cmd[0] = true_path;
		return (ft_free(paths), 0);
	}
	return (0);
}

int	check_outher_cmd(t_list *lst, t_env *env)
{
	if (is_path_command(lst->cmd[0]))
	{
		if (access(lst->cmd[0], F_OK) == -1)
			return (file_not_found("minishell", lst->cmd[0]), 1);
		return (0);
	}
	else if (access(lst->cmd[0], X_OK) != -1 && lst->cmd[0][0] == '.')
		return (0);
	else
		return (check_non_path_cmd(lst, env));
	return (0);
}

int	is_exec(t_list *lst, t_env *env)
{
	if (lst->cmd[0] == NULL)
		return (1);
	if (!is_built_in(lst->cmd[0]))
		return (0);
	else
		return (check_outher_cmd(lst, env));
	return (0);
}
