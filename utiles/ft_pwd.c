/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 08:38:06 by haghouli          #+#    #+#             */
/*   Updated: 2023/03/28 14:41:35 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	change_pwd(t_env *env)
{
	char	*str;

	str = NULL;
	while (env)
	{
		if (!ft_strcmp(env->var, "PWD"))
		{
			free(env->value);
			env->value = getcwd(str, 100);
			break ;
		}
		env = env->next;
	}
}

void	env_change_pwd(t_env **env, char *old_pwd)
{
	t_env	*tmp;
	int		b;

	b = 0;
	change_pwd(*env);
	tmp = *env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->var, "OLDPWD"))
		{
			free(tmp->value);
			tmp->value = old_pwd;
			b = 1;
		}
		tmp = tmp->next;
	}
	if (b == 0)
		ft_lstadd_back_env(env, ft_lstnew_env(ft_strdup("OLDPWD"),
				ft_strdup(old_pwd)));
}

void	ft_pwd(void)
{
	char	*str;

	str = NULL;
	printf("%s\n", getcwd(str, 100));
	g_status = 0;
}
