/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:54:57 by haghouli          #+#    #+#             */
/*   Updated: 2023/03/28 13:50:40 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute(char *input, t_list *lst, t_env **env)
{
	if (ft_strcmp(input, "\0"))
	{
		dup2(lst->infile, 0);
		if (ft_lstsize(lst) == 1)
			exec_single_cmd(lst, env);
		else
			exec_all(lst, env);
	}
	lst = NULL;
}
