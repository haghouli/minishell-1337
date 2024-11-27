/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtadlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:11:43 by mtadlaou          #+#    #+#             */
/*   Updated: 2023/03/28 13:20:29 by mtadlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

char	**get_cmd(t_split **p)
{
	char	**s;
	t_split	*tmp;
	int		i;

	i = 0;
	if (p == NULL || *p == NULL)
		return (NULL);
	s = malloc(sizeof(char *) * (list_size(*p) + 1));
	tmp = *p;
	while (tmp)
	{
		s[i++] = ft_strdup(tmp->str);
		tmp = tmp->next;
	}
	s[i] = NULL;
	ft_lstclear2(p);
	return (s);
}

int	list_size(t_split *p)
{
	int	i;

	i = 0;
	while (p)
	{
		i++;
		p = p->next;
	}
	return (i);
}

char	*ft_strjoin2(char *s1, char *s2, char *s3)
{
	char	*p;
	int		a;
	int		i;
	int		j;

	if (s1 == NULL)
		return (ft_strjoin(s2, s3));
	a = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
	p = malloc(sizeof(char) * (a + 1));
	if (p == NULL)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		p[++j] = s1[i];
	i = -1;
	while (s2[++i])
		p[++j] = s2[i];
	i = -1;
	while (s3[++i])
		p[++j] = s3[i];
	p[++j] = '\0';
	return (p);
}

void	print_error(char *s)
{
	write(2, s, ft_strlen(s));
}

t_split	*turn_string_to_list(char *str)
{
	int		i;
	t_split	*p;
	char	**s;

	i = 0;
	p = NULL;
	s = new_split(str, ' ');
	if (!s)
		return (NULL);
	while (s[i])
	{
		ft_lstadd_back2(&p, ft_lstnew2(s[i]));
		i++;
	}
	free(s);
	return (p);
}
