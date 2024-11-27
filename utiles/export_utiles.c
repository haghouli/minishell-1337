/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:35:14 by haghouli          #+#    #+#             */
/*   Updated: 2023/03/29 11:19:53 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_valid_export(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if ((!ft_isalpha(str[0]) && str[0] != '_')
		|| (ft_strchr(str, ' ') && !ft_strchr(str, '=')))
		return (not_valid_identfier("export", str), 0);
	while (str[i] && str[i] != '=' && str[i] != '+')
		i++;
	if (str[i] == '+' && str[i + 1] != '=')
		return (not_valid_identfier("export", str), 0);
	return (1);
}

int	replace_if_exist(t_env *env, char *str)
{
	char	*tmp;

	tmp = get_befor(str, '=');
	while (env)
	{
		if (!ft_strcmp(tmp, env->var))
		{
			free(env->value);
			env->value = get_after(str, '=');
			return (free(tmp), 1);
		}
		env = env->next;
	}
	return (free(tmp), 0);
}

int	append_if_exist(t_env *env, char *str)
{
	int		i;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	i = 0;
	while (str[i] && str[i] != '+')
		i++;
	if (str[i] == '+' && str[i + 1] != '=')
		return (0);
	tmp = get_befor(str, '=');
	while (env)
	{
		if (!ft_strcmp(tmp, env->var))
		{
			tmp3 = env->value;
			tmp2 = get_after(str, '=');
			env->value = ft_strjoin(env->value, tmp2);
			return (free(tmp), free(tmp2), free(tmp3), 1);
		}
		env = env->next;
	}
	return (free(tmp), 0);
}
