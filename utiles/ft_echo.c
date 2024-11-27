/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 09:00:13 by haghouli          #+#    #+#             */
/*   Updated: 2023/03/27 13:30:59 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_n_flag(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void	echo_n(t_list *lst)
{
	int	i;

	i = 1;
	while (lst->cmd[i] && is_n_flag(lst->cmd[i]))
		i++;
	while (lst->cmd[i])
	{
		ft_putstr_fd(lst->cmd[i++], lst->outfile);
		if (lst->cmd[i])
			write(lst->outfile, " ", 1);
	}
}

void	ft_echo(t_list *lst)
{
	int	i;

	i = 1;
	if (arr_size(lst->cmd) == 1)
		write(lst->outfile, "\n", 1);
	else if (!ft_strncmp(lst->cmd[1], "-n", 2) && is_n_flag(lst->cmd[1]))
		echo_n(lst);
	else
	{
		while (lst->cmd[i])
		{
			ft_putstr_fd(lst->cmd[i++], lst->outfile);
			if (lst->cmd[i])
				write(lst->outfile, " ", 1);
		}
		write(lst->outfile, "\n", 1);
	}
	g_status = 0;
}
