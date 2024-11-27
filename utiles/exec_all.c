/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:25:34 by haghouli          #+#    #+#             */
/*   Updated: 2023/03/28 15:56:14 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	p2(t_list *lst, t_env **env, int *pip)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	close(pip[0]);
	if (lst->next == NULL || lst->outfile != 1)
		dup2(lst->outfile, 1);
	else
		dup2(pip[1], 1);
	if (!is_built_in(lst->cmd[0]))
	{
		exec_builtin(lst, env);
		exit(g_status);
	}
	else if (execve(lst->cmd[0], lst->cmd, copy_lst_to_array(*env)) == -1)
	{
		command_not_found(lst->cmd[0]);
		exit(127);
	}
	close_pipes(pip);
}

void	p1(t_list **lst, t_env **env, int *pip, int *id)
{
	change_last_exec(*env, ft_strdup((*lst)->cmd[0]));
	*id = fork();
	if (*id == 0)
		p2(*lst, env, pip);
	*lst = (*lst)->next;
	if (*lst && (*lst)->infile != 0)
		dup2((*lst)->infile, 0);
	else
		dup2(pip[0], 0);
	close_pipes(pip);
}

void	exec_all(t_list *lst, t_env **env)
{
	int	pip[2];
	int	s;
	int	id;

	dup2(lst->infile, 0);
	while (lst)
	{
		pipe(pip);
		if (lst->cmd && !is_exec(lst, *env))
			p1(&lst, env, pip, &id);
		else
		{
			dup2(pip[0], 0);
			close_pipes(pip);
			lst = lst->next;
		}
	}
	close_pipes(pip);
	waitpid(id, &s, 0);
	while (wait(NULL) != -1)
		;
	if (WIFEXITED(s))
		g_status = WEXITSTATUS(s);
}
