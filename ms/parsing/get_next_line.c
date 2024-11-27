/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtadlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:41:17 by mtadlaou          #+#    #+#             */
/*   Updated: 2023/03/28 13:19:39 by mtadlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void	*free_str(char *str, char *str1)
{
	free(str);
	free(str1);
	return (NULL);
}

char	*read_by_buffer(int fd, char *line)
{
	char	*buffer;
	char	*temp;
	int		i;

	buffer = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	i = read(fd, buffer, BUFFER_SIZE);
	if (i < 0)
		return (free_str(line, buffer));
	while (i > 0)
	{
		if (i < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		temp = ft_strjoin(line, buffer);
		free(line);
		line = temp;
		if (ft_strchr(line, '\n') != 0)
			break ;
		i = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (line);
}

char	*get_a_line(char *line)
{
	char	*new_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (line[i] == '\0')
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	new_line = malloc(i + 2 * sizeof(char));
	if (new_line == NULL)
		return (NULL);
	while (j <= i)
	{
		new_line[j] = line[j];
		j++;
	}
	new_line[j] = '\0';
	return (new_line);
}

char	*get_data_after_nl(char *data)
{
	char	*str;
	int		i;

	i = 0;
	while (data[i] && data[i] != '\n')
		i++;
	if (!data[i])
	{
		free(data);
		return (NULL);
	}
	i++;
	str = ft_strdup(data + i);
	free(data);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*read;
	char		*line;

	if ((fd < 0 || fd > OPEN_MAX) || BUFFER_SIZE <= 0)
		return (NULL);
	read = read_by_buffer(fd, read);
	if (!read)
		return (NULL);
	line = get_a_line(read);
	read = get_data_after_nl(read);
	return (line);
}
