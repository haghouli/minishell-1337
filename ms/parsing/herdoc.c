/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtadlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:04:38 by mtadlaou          #+#    #+#             */
/*   Updated: 2023/03/29 13:34:39 by mtadlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

int	wait_process(pid_t pid, int *st)
{
	waitpid(pid, st, 0);
	if (*st != 0)
	{
		if (*st == 256 * 42)
			g_status = 1;
		return (0);
	}
	return (1);
}

int	fork_for_herdoc(int expand, char *s, int fd, t_env *env)
{
	t_norm	p;

	p.pid = fork();
	if (p.pid == 0)
	{
		signal(SIGINT, handle_doc);
		while (1)
		{
			write(1, "heredoc> ", 10);
			p.str = get_next_line(0);
			if (!p.str)
				exit(1);
			if (!ft_strcmp(p.str, s))
				break ;
			if (expand == 1)
				p.str = do_expanding(p.str, env);
			write(fd, p.str, ft_strlen(p.str));
			free(p.str);
		}
		(free(p.str), free(s), exit(0));
	}
	if (!wait_process(p.pid, &p.st))
		return (0);
	return (1);
}

char	*here_doc(char *limit, t_env *env, t_herdoc **doc)
{
	int		fd;
	char	*s;
	int		expand;
	char	*file;

	expand = 1;
	if (ft_strchr(limit, '\"') || ft_strchr(limit, '\"'))
	{
		limit = delete_limit_quote(limit);
		expand = 0;
	}
	file = generate_file(limit);
	ft_lstadd_back3(doc, ft_lstnew3(ft_strdup(file)));
	fd = open(file, O_TRUNC | O_WRONLY | O_RDONLY, 0644);
	if (fd == -1)
		print_error("error with openning her_doc\n");
	s = ft_strjoin(limit, "\n");
	free(limit);
	if (!fork_for_herdoc(expand, s, fd, env))
		return (free(file), free(s), NULL);
	close(fd);
	return (free(s), file);
}

int	open_her_doc(char *str, t_herdoc **doc, t_env *env, t_save **save)
{
	t_norn	n;

	n.s = new_split(str, '|');
	n.i = -1;
	while (n.s[++(n.i)])
	{
		n.s[n.i] = add_space_to_str(n.s[n.i]);
		n.p = turn_string_to_list(n.s[n.i]);
		n.tmp = n.p;
		while (n.p)
		{
			if (!ft_strcmp(n.p->str, "<<"))
			{
				n.p->next->str = here_doc(n.p->next->str, env, doc);
				if (n.p->next->str == NULL)
					return (free_2d_table(n.s), ft_lstclear2(&n.tmp),
						remove_herdoc_files(doc));
			}
			n.p = n.p->next;
		}
		generate_list(save, fill_list(n.tmp));
	}
	return (free_2d_table(n.s), 1);
}

t_list	*start_the_process(char *s, t_env *env, t_herdoc **doc)
{
	t_list	*mini;
	int		i;
	t_save	*save;
	t_save	*tmp;

	mini = NULL;
	save = NULL;
	if (open_her_doc(s, doc, env, &save) == 0)
		return (free_saver(&save), NULL);
	i = -1;
	tmp = save;
	while (tmp)
	{
		ft_lstadd_back(&mini, ft_new(&(tmp->list), env));
		tmp = tmp->next;
	}
	free_saver(&save);
	return (mini);
}
