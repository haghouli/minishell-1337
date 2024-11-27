/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_single_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 12:59:13 by haghouli          #+#    #+#             */
/*   Updated: 2023/03/29 13:54:00 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	p1(t_list *lst, t_env **env, int *pip, int *s)
{
	int	id;

	change_last_exec(*env, ft_strdup(lst->cmd[0]));
	pipe(pip);
	dup2(lst->infile, 0);
	id = fork();
	if (id == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		dup2(lst->outfile, 1);
		g_status = 0;
		close(pip[0]);
		write(pip[1], &g_status, sizeof(int));
		if (execve(lst->cmd[0], lst->cmd, copy_lst_to_array(*env)))
		{
			command_not_found(lst->cmd[0]);
			exit(1);
		}
	}
	read(pip[0], &g_status, sizeof(int));
	close(pip[1]);
	waitpid(id, s, 0);
}

void	exec_single_cmd(t_list *lst, t_env **env)
{
	int	pip[2];
	int	s;

	s = 0;
	if (lst->cmd)
	{
		if (!is_built_in(lst->cmd[0]))
		{
			dup2(lst->outfile, 1);
			exec_builtin(lst, env);
		}
		else
		{
			if (!is_exec(lst, *env))
			{
				p1(lst, env, pip, &s);
				if (WIFEXITED(s))
					g_status = WEXITSTATUS(s);
			}
			if (s == 2)
				g_status = 130;
			else if (s == 3)
				g_status = 131;
		}
	}
}
