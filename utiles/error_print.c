/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:01:25 by haghouli          #+#    #+#             */
/*   Updated: 2023/03/27 13:33:17 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	command_not_found(char *cmd)
{
	write(2, "minishell: ", 11);
	ft_putstr_fd(cmd, 2);
	write(2, ": command not found\n", 21);
	g_status = 127;
}

void	file_not_found(char *str1, char *str2)
{
	ft_putstr_fd(str1, 2);
	write(2, ":", 1);
	ft_putstr_fd(str2, 2);
	write(2, ": No such file or directory\n", 29);
	g_status = 127;
}

void	not_valid_identfier(char *str1, char *str2)
{
	write(2, "minishell: ", 12);
	ft_putstr_fd(str1, 2);
	write(2, ": `", 3);
	ft_putstr_fd(str2, 2);
	write(2, "': not a valid identifier\n", 26);
	g_status = 1;
}

void	numeric_arg_require(t_list *lst)
{
	write(2, "minishell: exit:", 11);
	ft_putstr_fd(lst->cmd[1], 2);
	write(2, ": numeric argument required\n", 29);
	g_status = 255;
}

void	to_many_args(void)
{
	write(2, "minishell: exit:", 11);
	write(2, ": too many arguments\n", 22);
	g_status = 1;
}
