/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 09:54:37 by haghouli          #+#    #+#             */
/*   Updated: 2023/03/28 16:06:43 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_exit(t_list *lst)
{
	if (arr_size(lst->cmd) == 1)
		exit(0);
	else if (arr_size(lst->cmd) == 2)
	{
		if (is_number(lst->cmd[1]))
			exit((char)ft_atoi(lst->cmd[1]));
		else
		{
			numeric_arg_require(lst);
			exit(255);
		}
	}
	else
	{
		if (is_number(lst->cmd[1]))
			to_many_args();
		else
		{
			numeric_arg_require(lst);
			exit(255);
		}
	}
}
