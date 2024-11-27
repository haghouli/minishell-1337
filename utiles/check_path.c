/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:11:03 by haghouli          #+#    #+#             */
/*   Updated: 2023/03/29 14:26:03 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**copy_plus_one(char **arr)
{
	char	**path;
	int		i;
	int		j;

	i = 0;
	j = 0;
	path = malloc(sizeof(char *) * arr_size(arr) + 2);
	path[i++] = ft_strdup(".");
	while (arr[j])
		path[i++] = ft_strdup(arr[j++]);
	path[i] = NULL;
	ft_free(arr);
	return (path);
}

int	count_pointe(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (i != 0 && str[i - 1] == ':' && str[i] == ':')
		{
			count++;
			i++;
		}
		if (str[i] == '\0')
			break ;
		i++;
	}
	return (count);
}

char	*check_pointes(char *str)
{
	char	*new_path;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (count_pointe(str) == 0)
		return (NULL);
	new_path = malloc(strlen(str) + (count_pointe(str) + 1) + 10);
	while (str[i])
	{
		if (i != 0 && str[i] == ':' && str[i - 1] == ':')
		{
			new_path[j++] = '.';
			new_path[j++] = str[i++];
		}
		else
			new_path[j++] = str[i++];
	}
	new_path[j] = '\0';
	return (new_path);
}
