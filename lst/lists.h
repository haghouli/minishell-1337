/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:00:56 by haghouli          #+#    #+#             */
/*   Updated: 2023/03/28 16:00:58 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_H
# define LISTS_H
# include "../ms/libft/libft.h"

t_env	*ft_lstnew_env(char *var, char *value);
void	ft_lstadd_front_env(t_env **lst, t_env *new);
int		ft_lstsize_env(t_env *lst);
t_env	*ft_lstlast_env(t_env *lst);
void	ft_lstadd_back_env(t_env **lst, t_env *new);
void	ft_lstdelone_env(t_env *lst, void (*del)(void *));
void	ft_lstclear_env(t_env **lst, void (*del)(void *));
void	ft_lstiter_env(t_env *lst, void (*f)(void *));
t_env	*ft_lstmap_env(t_env *env, char *(*f)(char *, char *),
			void (*del)(void *));
void	ft_lstsort_env(t_env **env);
int		ft_lstsize(t_list *lst);

void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);

#endif