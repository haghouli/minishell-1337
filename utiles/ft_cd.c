/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 08:35:53 by haghouli          #+#    #+#             */
/*   Updated: 2023/03/28 15:58:41 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_cd_old(t_env *env, char *old_pwd, char *str)
{
	while (env)
	{
		if (!ft_strcmp("OLDPWD", env->var))
		{
			str = env->value;
			break ;
		}
		env = env->next;
	}
	if (!str)
	{
		write(2, "bash: cd: OLDPWD not set\n", 26);
		g_status = 1;
		old_pwd = NULL;
	}
	else
	{
		chdir(str);
		printf("%s\n", str);
	}
}

void	change_dir(t_list *lst)
{
	char	*tmp;

	tmp = NULL;
	if (ft_strnstr(lst->cmd[1], "~", 2))
	{
		tmp = lst->cmd[1];
		lst->cmd[1] = ft_strjoin(getenv("HOME"), lst->cmd[1] + 1);
		free(tmp);
		g_status = 0;
	}
	if (chdir(lst->cmd[1]) == -1)
	{
		file_not_found("minishell", lst->cmd[1]);
		g_status = 1;
	}
}

void	ft_cd(t_list *lst, t_env **env)
{
	char	*old_pwd;
	char	*str;
	char	*tmp;

	str = NULL;
	tmp = NULL;
	old_pwd = getcwd(tmp, 100);
	free(tmp);
	if (lst->cmd[1] == NULL)
		chdir(getenv("HOME"));
	else if (!ft_strcmp("-", lst->cmd[1]) && open(lst->cmd[1], O_RDONLY) < 0)
		ft_cd_old(*env, old_pwd, str);
	else
		change_dir(lst);
	if (old_pwd)
		env_change_pwd(env, old_pwd);
}
