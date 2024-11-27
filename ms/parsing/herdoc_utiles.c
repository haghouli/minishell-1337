/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc_utiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtadlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:02:22 by mtadlaou          #+#    #+#             */
/*   Updated: 2023/03/28 13:19:42 by mtadlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void	handle_doc(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	exit(42);
}

char	*get_tty(void)
{
	char	**s;
	char	*str;
	int		i;

	i = -1;
	s = ft_split(ttyname(1), '/');
	while (s[++i])
	{
		if (ft_strnstr(s[i], "ttys", ft_strlen(s[i])))
			str = s[i];
		else
			free(s[i]);
	}
	free(s);
	return (str);
}

char	*generate_file(char *limit)
{
	t_norm	*n;

	n = malloc(sizeof(t_norm));
	n->i = 0;
	n->ia = ft_itoa(n->i);
	n->tmp2 = get_tty();
	n->file = ft_strjoin2(n->ia, limit, n->tmp2);
	while (!access(n->file, F_OK))
	{
		free(n->tmp2);
		free(n->ia);
		free(n->file);
		(n->i)++;
		n->ia = ft_itoa(n->i);
		n->tmp2 = get_tty();
		n->tmp = ft_strjoin2(n->ia, limit, n->tmp2);
		n->file = n->tmp;
	}
	n->fd = open(n->file, O_TRUNC | O_WRONLY | O_CREAT, 0644);
	close(n->fd);
	free(n->tmp2);
	free(n->ia);
	return (free(n), n->file);
}

char	*keep_delete_quote(char *s, int *j, char c)
{
	char	*str;
	int		start;
	int		end;

	if (c == '0')
	{
		start = *j;
		while (s[*j] && s[*j] != '\"' && s[*j] != '\'')
			(*j)++;
		end = *j;
		str = ft_substr(s, start, end - start);
		if (s[*j])
			(*j)--;
		return (str);
	}
	(*j)++;
	start = *j;
	while (s[*j] != c)
		(*j)++;
	end = (*j);
	str = ft_substr(s, start, end - start);
	return (str);
}

char	*delete_limit_quote(char *limit)
{
	int		i;
	char	*str;
	char	*s2;
	char	*tmp;

	i = 0;
	str = NULL;
	while (limit[i])
	{
		if (limit[i] == '\"')
			s2 = keep_delete_quote(limit, &i, '\"');
		else if (limit[i] == '\'')
			s2 = keep_delete_quote(limit, &i, '\'');
		else
			s2 = keep_delete_quote(limit, &i, '0');
		tmp = ft_strjoin(str, s2);
		free(str);
		str = tmp;
		free(s2);
		i++;
	}
	free(limit);
	return (str);
}
