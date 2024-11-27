/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtadlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:22:06 by mtadlaou          #+#    #+#             */
/*   Updated: 2023/03/29 14:08:24 by mtadlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "./libft/libft.h"
# include <dirent.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct norm
{
	pid_t	pid;
	int		st;
	char	*str;
	int		i;
	char	*file;
	char	*tmp;
	char	*tmp2;
	int		fd;
	char	*ia;
}			t_norm;

typedef struct normn
{
	char	*str;
	char	*tmp1;
	char	*s2;
	char	**s;
	int		i;
	t_split	*p;
	t_split	*tmp;
}			t_norn;

int			g_status;

t_list		*start_the_process(char *s, t_env *env, t_herdoc **doc);
char		**new_split(char const *s, char c);
t_list		*ft_new(t_split **p, t_env *env);
char		*ft_strjoin2(char *s1, char *s2, char *s3);
t_split		*ft_lstnew2(char *s);
void		ft_lstadd_back2(t_split **lst, t_split *new);
t_split		*turn_string_to_list(char *str);
void		print_error(char *s);
void		ft_lstclear2(t_split **lst);
void		ft_lstremove(t_split **p, char *to_delete);
t_split		*open_and_remove(t_list *head, t_split *p, t_env *env);
char		*add_space_to_str(char *s);
char		*get_next_line(int fd);
t_herdoc	*ft_lstnew3(char *s);
void		ft_lstadd_back3(t_herdoc **lst, t_herdoc *new);
char		*do_expanding(char *s, t_env *env);
int			check_the_list(t_split *p, int i);
int			list_size(t_split *p);
void		ft_open(t_list *head, char *s1, char *s2);
void		qoute_handling(t_split *p, t_env *env);
int			check_the_list(t_split *p, int i);
int			check_str(char *s);
int			check_redection(char *s);
void		doc_to_redection(t_split *p);
void		get_the_type(t_split *p);
t_split		*turn_string_to_list(char *str);
void		print_error(char *s);
int			list_size(t_split *p);
char		**get_cmd(t_split **p);
char		*add_space_to_str(char *s2);
int			ft_strcmp(char *s1, char *s2);
int			syntax_error(char *s);
void		ft_put(char **s1, char **s2, int i, t_split **p);
char		*delete_limit_quote(char *limit);
char		*get_tty(void);
void		ft_skeep(const char *s, int *i, int j);
void		free_2d_table(char **s);
void		free_list(t_list **lst); // remove it
char		*delete_limit_quote(char *limit);
char		*generate_file(char *limit);
void		free_saver(t_save **lst);
int			remove_herdoc_files(t_herdoc **doc);
t_save		*fill_list(t_split *p);
t_syntax	*ft_newlist(char c, int *i, int d);
void		generate_list(t_save **save, t_save *new);
int			ambiguous(t_split **p, t_split *tmp, t_list *head);
void		in_trunc_fun(t_list *head, char *s1);
void		out_trunc_fun(t_list *head, char *s1);
void		out_append_fun(t_list *head, char *s1);
int			check_argument(char **s);
void		ft_lstadd_syntax(t_syntax **lst, t_syntax *new);
void		free_syntax_list(t_syntax **lst);
t_syntax	*get_last(t_syntax *p);
void		max_herdoc(t_syntax *p, int *c);
char		*all_cases(t_syntax *p);
void		ft_skeep_space(char *s, int *i);
void		handle_doc(int sig);
void		free_herdoc(t_herdoc **lst);
int			check_newline(t_syntax *p);
int			check_append(t_syntax *p);
int			check_in(t_syntax *p);
int			check_out(t_syntax *p);
int			check_herdoc(t_syntax *p);
void		do_while(char *s, int *i);

#endif
