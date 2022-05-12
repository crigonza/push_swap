/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 11:21:33 by crigonza          #+#    #+#             */
/*   Updated: 2022/05/12 19:23:47 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*strge[OPEN_MAX];
	char		*line;

	if (fd == -1 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	if (!strge[fd])
	{
		strge[fd] = malloc(sizeof(char) * 1);
		strge[fd][0] = '\0';
	}
	strge[fd] = ft_read_file(fd, strge[fd]);
	if (!strge[fd])
		return (NULL);
	line = ft_line(strge[fd]);
	strge[fd] = ft_rest(strge[fd]);
	return (line);
}

char	*ft_rest(char *strge)
{
	int		len;
	char	*temp;

	len = 0;
	while (strge[len] && strge[len] != '\n')
		len++;
	if (strge[len] == '\0')
	{
		free(strge);
		return (NULL);
	}
	len++;
	temp = ft_substr(strge, len, ft_strlen(strge) - len);
	free(strge);
	return (temp);
}

char	*ft_line(char *strge)
{
	char	*temp;
	int		i;

	i = 0;
	if (!strge[i])
		return (NULL);
	while (strge[i] && strge[i] != '\n')
		i++;
	temp = (char *)malloc(sizeof(char) * i + 2);
	if (!temp)
		return (NULL);
	i = 0;
	while (strge[i] && strge[i] != '\n')
	{
		temp[i] = strge[i];
		i++;
	}
	if (strge[i] == '\n')
		temp[i++] = '\n';
	temp[i] = '\0';
	return (temp);
}

char	*ft_read_file(int fd, char *strge)
{
	char	*buffer;
	int		nbyte;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	nbyte = 1;
	while (nbyte > 0 && !ft_strchr(strge, '\n'))
	{
		nbyte = read(fd, buffer, BUFFER_SIZE);
		if (nbyte == -1)
		{
			free(strge);
			free(buffer);
			return (NULL);
		}
		buffer[nbyte] = '\0';
		strge = ft_join_free(strge, buffer);
	}
	free(buffer);
	return (strge);
}

char	*ft_join_free(char *strge, char *buffer)
{
	char	*aux;

	aux = ft_strjoin(strge, buffer);
	free(strge);
	return (aux);
}
