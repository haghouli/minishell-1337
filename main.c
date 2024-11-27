/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:06:09 by haghouli          #+#    #+#             */
/*   Updated: 2023/03/29 10:55:27 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

void	minishell(t_data *data)
{
	data->lst = start_the_process(data->input, data->env, &data->doc);
	if (data->lst)
	{
		execute(data->input, data->lst, &data->env);
		if (!isatty(0) || !isatty(1) || !isatty(2))
		{
			dup2(data->in, 0);
			dup2(data->out, 1);
			dup2(data->err, 2);
		}
		close_fds(data->lst);
		ft_lstclear(&data->lst, free);
		unlink_herdocs(&data->doc);
	}
}

int	main(int ac, char **av, char **ev)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	init_data(&data, ac, av);
	fill_env(&data->env, ev, data);
	print_ascii();
	while (1)
	{
		data->doc = NULL;
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, ctl_c);
		data->input = readline("minishell >$ ");
		if (data->input == NULL)
			return (0);
		add_history(data->input);
		signal(SIGINT, SIG_IGN);
		if (syntax_error(data->input))
			minishell(data);
		free(data->input);
	}
}
