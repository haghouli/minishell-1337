/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:42:38 by haghouli          #+#    #+#             */
/*   Updated: 2023/03/24 14:51:02 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_built_in(char *cmd)
{
	if (!cmd)
		return (1);
	if (!ft_strcmp(cmd, "echo") || !ft_strcmp(cmd, "/bin/echo")
		|| !ft_strcmp(cmd, "cd") || !ft_strcmp(cmd, "/usr/bin/cd")
		|| !ft_strcmp(cmd, "pwd") || !ft_strcmp(cmd, "/bin/pwd")
		|| !ft_strcmp(cmd, "export") || !ft_strcmp(cmd, "unset")
		|| !ft_strcmp(cmd, "env") || !ft_strcmp(cmd, "/usr/bin/env")
		|| !ft_strcmp(cmd, "exit"))
		return (0);
	return (1);
}
