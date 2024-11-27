/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:25:03 by haghouli          #+#    #+#             */
/*   Updated: 2023/03/04 15:35:30 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*ft_lstmap_env(t_env *env, char *(*f)(char *, char *),
		void (*del)(void *))
{
	t_env	*t;
	t_env	*tmp;

	if (env == NULL || f == NULL || del == NULL)
		return (NULL);
	t = ft_lstnew_env(f("declare -x ", env->var), ft_strdup(env->value));
	if (!t)
		return (NULL);
	tmp = t;
	env = env->next;
	while (env)
	{
		t->next = ft_lstnew_env(f("declare -x ", env->var),
				ft_strdup(env->value));
		if (!t->next)
		{
			ft_lstclear_env(&tmp, del);
			return (0);
		}
		t = t->next;
		env = env->next;
	}
	t->next = NULL;
	return (tmp);
}
