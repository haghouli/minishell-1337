/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 09:24:35 by haghouli          #+#    #+#             */
/*   Updated: 2023/03/28 15:09:16 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exec_builtin(t_list *lst, t_env **env)
{
	change_last_exec(*env, ft_strdup(lst->cmd[0]));
	if (!ft_strcmp(lst->cmd[0], "pwd") || !ft_strcmp(lst->cmd[0], "/bin/pwd"))
		ft_pwd();
	else if (!ft_strcmp(lst->cmd[0], "exit"))
		ft_exit(lst);
	else if (!ft_strcmp(lst->cmd[0], "echo") || !ft_strcmp(lst->cmd[0],
			"/bin/echo"))
		ft_echo(lst);
	else if (!ft_strcmp(lst->cmd[0], "env") || !ft_strcmp(lst->cmd[0],
			"/usr/bin/env"))
		ft_env(*env, lst);
	else if (!ft_strcmp(lst->cmd[0], "cd") || !ft_strcmp(lst->cmd[0],
			"/usr/bin/cd"))
		ft_cd(lst, env);
	else if (!ft_strcmp(lst->cmd[0], "unset"))
		ft_unset(env, lst);
	else if (!ft_strcmp(lst->cmd[0], "export"))
		ft_export(lst, env);
}
