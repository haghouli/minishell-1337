/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 05:12:15 by haghouli          #+#    #+#             */
/*   Updated: 2023/03/28 15:11:48 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_exports(t_list *lst, t_env **env)
{
	int	i;

	i = 1;
	while (lst->cmd[i])
	{
		if (is_valid_export(lst->cmd[i]))
		{
			if (append_if_exist(*env, lst->cmd[i]))
				;
			else if (replace_if_exist(*env, lst->cmd[i]))
				;
			else
				ft_lstadd_back_env(env, ft_lstnew_env(get_befor(lst->cmd[i],
							'='), get_after(lst->cmd[i], '=')));
		}
		i++;
	}
}

void	show_exports(t_env **env)
{
	t_env	*env_copy;
	t_env	*tmp;

	env_copy = ft_lstmap_env(*env, ft_strjoin, free);
	tmp = env_copy;
	ft_lstsort_env(&tmp);
	while (tmp)
	{
		if (ft_strcmp(tmp->var, "_") && (ft_strcmp("export", tmp->value)))
		{
			printf("%s", tmp->var);
			if (tmp->value != NULL)
				printf("=\"%s\"", tmp->value);
			printf("\n");
		}
		tmp = tmp->next;
	}
	ft_lstclear_env(&env_copy, free);
}

void	ft_export(t_list *lst, t_env **env)
{
	if (arr_size(lst->cmd) == 1)
		show_exports(env);
	else
		add_exports(lst, env);
}
