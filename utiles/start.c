/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:25:18 by haghouli          #+#    #+#             */
/*   Updated: 2023/03/29 11:17:56 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_data(t_data **data, int ac, char **av)
{
	(void)ac;
	(void)av;
	(*data)->in = dup(0);
	(*data)->out = dup(1);
	(*data)->err = dup(2);
	(*data)->env = NULL;
	(*data)->lst = NULL;
	(*data)->lvl = ft_atoi(getenv("SHLVL")) + 1;
	(*data)->doc = NULL;
}

void	print_ascii(void)
{
	printf("\n");
	printf("\e[1;35mWelcome to :");
	printf("\n");
	printf("\e[0;34m               _       _     _          _ _ \n");
	printf("              (_)     (_)   | |        | | |\n");
	printf("     _ __ ___  _ _ __  _ ___| |__   ___| | |\n");
	printf("    | '_ ` _ \\| | '_ \\| / __| '_ \\ / _ \\ | |\n");
	printf("    | | | | | | | | | | \\__ \\ | | |  __/ | |\n");
	printf("    |_| |_| |_|_|_| |_|_|___/_| |_|\\___|_|_|\n");
	printf("\n");
	printf("                              \e[1;35mby : hicham & mohcin\033[0m\n");
	printf("\n");
}
