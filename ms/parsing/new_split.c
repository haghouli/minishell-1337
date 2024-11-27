/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtadlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:25:02 by mtadlaou          #+#    #+#             */
/*   Updated: 2023/03/29 15:11:56 by mtadlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void	ft_skeep(const char *s, int *i, int j)
{
	if (s[*i] == '"')
	{
		(*i)++;
		while (s[*i] != '"')
			(*i)++;
	}
	if (s[*i] == '\'')
	{
		(*i)++;
		while (s[*i] != '\'')
			(*i)++;
	}
	if (j == 0)
		(*i)++;
}

static void	*free_fun(char **s, size_t a)
{
	size_t	i;

	i = 0;
	while (i < a)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static char	**full_split(const char *str, char **spl, char c)
{
	int	i;
	int	j;
	int	h;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && str[i] != '\t')
		{
			h = i;
			while (str[i] != c && str[i] && str[i] != '\t')
				ft_skeep(str, &i, 0);
			spl[j] = ft_substr(str, h, (i - h));
			if (spl[j] == NULL)
				return (free_fun(spl, j));
			j++;
		}
		else
			i++;
	}
	spl[j] = NULL;
	return (spl);
}

static int	string_num(const char *str, char c)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (str[i])
	{
		ft_skeep(str, &i, 1);
		if (str[i] == c || str[i] == '\t')
		{
			if (str[i + 1] != c && str[i + 1] != '\t' && str[i + 1] != '\0')
				a++;
		}
		i++;
	}
	if (str[0] != c && str[0] != '\t')
		return (a + 1);
	return (a);
}

char	**new_split(char const *s, char c)
{
	char	**p;

	if (s == NULL)
		return (NULL);
	p = (char **)malloc(sizeof(char *) * (string_num(s, c) + 1));
	if (!p)
		return (NULL);
	p = full_split(s, p, c);
	return (p);
}
