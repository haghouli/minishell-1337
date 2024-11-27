/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtadlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:14:16 by haghouli          #+#    #+#             */
/*   Updated: 2023/03/28 10:27:39 by mtadlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	unlink_herdocs(t_herdoc **doc)
{
	t_herdoc	*tmp;

	tmp = *doc;
	if (tmp)
	{
		while (tmp)
		{
			unlink(tmp->doc);
			tmp = tmp->next;
		}
		free_herdoc(doc);
	}
}

void	close_pipes(int *pip1)
{
	close(pip1[0]);
	close(pip1[1]);
}

void	close_fds(t_list *lst)
{
	while (lst)
	{
		if (lst->infile > 2)
			close(lst->infile);
		if (lst->outfile > 2)
			close(lst->outfile);
		lst = lst->next;
	}
}
