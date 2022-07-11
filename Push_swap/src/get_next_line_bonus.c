/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:51:14 by crigonza          #+#    #+#             */
/*   Updated: 2022/07/11 20:39:34 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker_bonus.h"

char	*ft_get_buffer(int fd, char *buffer)
{
	char	*tmp;
	int		f;

	tmp = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	f = 1;
	while (!ft_strchr(buffer, '\n') && f)
	{
		f = read(fd, tmp, BUFFER_SIZE);
		if (f == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[f] = '\0';
		buffer = ft_strjoin(buffer, tmp);
	}
	free(tmp);
	return (buffer);
}

char	*ft_get_line(char *buffer)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	tmp = (char *)malloc(sizeof(char) * i + 2);
	if (!tmp)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		tmp[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		tmp[i] = buffer[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_next(char *buffer)
{
	int		len;
	int		size;
	char	*temp;

	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	if (buffer[len] == '\n')
		len++;
	if (!buffer[len])
	{
		free(buffer);
		return (NULL);
	}
	size = ft_strlen(&buffer[len]) + 1;
	temp = (char *)malloc(sizeof(char) * size);
	ft_memcpy(temp, &buffer[len], size);
	free(buffer);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char *buffer;
	char *line;
	if (!buffer)
	{
		buffer = (char *)malloc(sizeof(char) * 1);
		buffer[0] = '\0';
	}

	buffer = ft_get_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}