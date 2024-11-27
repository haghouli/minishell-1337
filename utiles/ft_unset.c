/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtadlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:05:48 by haghouli          #+#    #+#             */
/*   Updated: 2023/03/29 15:21:03 by mtadlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_unseted(char *str)
{
	int	i;

	i = 0;
	if (!ft_isalpha(str[0]))
		return (0);
	while (str[i])
	{
		if (!ft_isalnum(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_indef(char **arr)
{
	int		i;
	char	*tmp;

	i = 0;
	while (arr[i])
	{
		if (!check_unseted(arr[i]))
		{
			not_valid_identfier("unset", arr[i]);
			tmp = arr[i];
			arr[i] = ft_strdup("0");
			free(tmp);
		}
		i++;
	}
}

int	is_in(char **to_search_in, char *to_find)
{
	int	i;

	i = 1;
	while (to_search_in[i])
	{
		if (!ft_strcmp(to_search_in[i++], to_find))
			return (1);
	}
	return (0);
}

void	skip_begin(t_list *lst, t_env **env)
{
	t_env	*tmp;

	while (is_in(lst->cmd, (*env)->var))
	{
		tmp = *env;
		(*env) = (*env)->next;
		free(tmp);
	}
}

void	ft_unset(t_env **env, t_list *lst)
{
	t_env	*tmp;
	t_env	*env_tmp;

	if (!env || !ft_strcmp("_", lst->cmd[1]))
		return ;
	check_indef(lst->cmd);
	skip_begin(lst, env);
	env_tmp = *env;
	while (env_tmp->next)
	{
		if (is_in(lst->cmd, env_tmp->next->var))
		{
			tmp = env_tmp->next;
			env_tmp->next = env_tmp->next->next;
			free(tmp->var);
			free(tmp->value);
			free(tmp);
		}
		else
			env_tmp = env_tmp->next;
	}
}
