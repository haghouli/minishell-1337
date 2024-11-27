/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:03:47 by haghouli          #+#    #+#             */
/*   Updated: 2023/03/29 14:22:00 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./lst/lists.h"
# include "./ms/libft/libft.h"
# include "./ms/parsing.h"
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <unistd.h>

typedef struct s_data
{
	t_env		*env;
	t_herdoc	*doc;
	t_list		*lst;
	char		*input;
	int			in;
	int			out;
	int			err;
	int			lvl;
}				t_data;

extern void		rl_replace_line(const char *str, int *n);
void			ctl_c(int n);
void			ft_exit(t_list *lst);
void			change_last_exec(t_env *env, char *str);

/************************************** utiles *******************************/
int				is_built_in(char *cmd);
int				arr_size(char **arr);
void			ft_free(char **arr);
void			fill_env(t_env **env, char **ev, t_data *data);
char			*get_after(char *str, char c);
char			*get_befor(char *str, char c);
char			*get_true_path(char **paths, char *cmd);
char			**get_paths(t_env *env);
int				is_path_command(char *cmd);
char			**copy_lst_to_array(t_env *env);
void			exec_builtin(t_list *lst, t_env **env);
void			execute(char *input, t_list *lst, t_env **env);

void			close_fds(t_list *lst);
void			close_pipes(int *pip1);
void			ft_lstclear(t_list **lst, void (*del)(void *));

int				is_valid_export(char *str);
int				replace_if_exist(t_env *env, char *str);
int				append_if_exist(t_env *env, char *str);
void			unlink_herdocs(t_herdoc **doc);
void			init_data(t_data **data, int ac, char **av);
void			print_ascii(void);

/****************************** built in command **************************/
void			ft_pwd(void);
void			ft_echo(t_list *lst);
void			ft_env(t_env *env, t_list *lst);
void			ft_cd(t_list *lst, t_env **env);
void			ft_unset(t_env **env, t_list *lst);
void			ft_export(t_list *lst, t_env **env);

void			signals(void);
int				is_exec(t_list *lst, t_env *env);
void			exec_single_cmd(t_list *lst, t_env **env);
void			exec_all(t_list *lst, t_env **env);
void			env_change_pwd(t_env **env, char *old_pwd);
char			*check_pointes(char *str);
void			ft_free(char **arr);
char			**copy_plus_one(char **arr);

/********************************** Errors **********************************/
void			command_not_found(char *cmd);
void			file_not_found(char *str1, char *str2);
void			not_valid_identfier(char *str1, char *str2);
void			numeric_arg_require(t_list *lst);
void			to_many_args(void);

#endif