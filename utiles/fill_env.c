/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 05:25:12 by haghouli          #+#    #+#             */
/*   Updated: 2023/03/29 10:59:28 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	fill_if_empty(t_env **env, t_data *data)
{
	t_env	*n1;
	t_env	*n2;
	t_env	*n3;
	t_env	*n4;
	char	*str;

	str = NULL;
	n1 = malloc(sizeof(t_env));
	n2 = malloc(sizeof(t_env));
	n3 = malloc(sizeof(t_env));
	n4 = malloc(sizeof(t_env));
	n1->var = ft_strdup("PWD");
	n1->value = getcwd(str, 100);
	n1->next = n2;
	n2->var = ft_strdup("OLDPWD");
	n2->value = NULL;
	n2->next = n3;
	n3->var = ft_strdup("SHLVL");
	n3->value = ft_itoa(data->lvl);
	n3->next = n4;
	n4->var = ft_strdup("_");
	n4->value = ft_strdup("/usr/bin/env");
	n4->next = NULL;
	(*env) = n1;
}

char	*get_befor(char *str, char c)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] != c && str[i] && str[i] != '+')
		i++;
	s = malloc(sizeof(char) * (i + 1));
	while (j < i)
	{
		s[j] = str[j];
		j++;
	}
	s[j] = '\0';
	return (s);
}

char	*get_after(char *str, char c)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	while (str[i] != c && str[i])
		i++;
	if (str[i] == '\0')
		return (NULL);
	if (str[i] == '+')
		i++;
	s = malloc(sizeof(char) * (ft_strlen(str) - i));
	i++;
	while (str[i])
		s[j++] = str[i++];
	s[j] = '\0';
	return (s);
}

void	fill_env(t_env **env, char **ev, t_data *data)
{
	int		i;
	char	*str;

	i = 0;
	fill_if_empty(env, data);
	while (ev[i])
	{
		str = get_befor(ev[i], '=');
		if (ft_strcmp(str, "OLDPWD") && ft_strcmp(str, "PWD") && ft_strcmp(str,
				"SHLVL") && ft_strcmp(str, "_"))
			ft_lstadd_back_env(env, ft_lstnew_env(str, get_after(ev[i], '=')));
		else
			free(str);
		i++;
	}
}
