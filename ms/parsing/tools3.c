/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtadlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:11:59 by mtadlaou          #+#    #+#             */
/*   Updated: 2023/03/28 13:20:33 by mtadlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

int	get_len(char *s)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(s);
	while (s[++i])
	{
		if (s[i] == '\'' || s[i] == '"')
		{
			i++;
			while (s[i] != '\'' && s[i] != '"')
				i++;
		}
		if ((s[i] == '<' && s[i + 1] == '<') || (s[i] == '>' && s[i
					+ 1] == '>'))
			len += 2;
		else if (s[i] == '<' || s[i] == '>')
			len += 2;
	}
	return (len);
}

void	ft_copystr(char *s, char *str, int *i, int *j)
{
	if (s[*i] == '\'' || s[*i] == '"')
	{
		str[(*j)++] = s[(*i)++];
		while (s[*i] != '\'' && s[*i] != '"')
			str[(*j)++] = s[(*i)++];
	}
	if ((s[*i] == '<' && s[*i + 1] == '<') || (s[*i] == '>' && s[*i
				+ 1] == '>'))
	{
		str[(*j)++] = ' ';
		str[(*j)++] = s[(*i)++];
		str[(*j)++] = s[*i];
		str[(*j)++] = ' ';
	}
	else if (s[*i] == '<' || s[*i] == '>')
	{
		str[(*j)++] = ' ';
		str[(*j)++] = s[*i];
		str[(*j)++] = ' ';
	}
	else
		str[(*j)++] = s[*i];
}

char	*alloc_new_str(char *s)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = 0;
	str = malloc(sizeof(char) * (get_len(s) + 1));
	i = -1;
	while (s[++i])
		ft_copystr(s, str, &i, &j);
	str[j] = '\0';
	free(s);
	return (str);
}

void	free_2d_table(char **s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
	s = NULL;
}

char	*add_space_to_str(char *s2)
{
	char	**s;
	int		i;
	char	*str;
	char	*tmp;

	str = NULL;
	i = -1;
	s = new_split(s2, ' ');
	free(s2);
	while (s[++i])
		if (check_redection(s[i]))
			s[i] = alloc_new_str(s[i]);
	i = -1;
	while (s[++i])
	{
		tmp = ft_strjoin2(str, s[i], " ");
		free(str);
		str = tmp;
		free(s[i]);
	}
	free(s);
	return (str);
}
