/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 11:21:33 by crigonza          #+#    #+#             */
/*   Updated: 2022/05/10 19:54:24 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*strge;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	strge = ft_read_file(fd, strge);
	if (!strge)
		return (NULL);
	line = ft_get_line(strge);
	strge = ft_free_st(strge, line);
	return (line);
}
char	*ft_free_st(char *strge, char *line)
{
	int		len;
	int 	i;
	char	*temp;

	len = ft_strlen(line);
	temp = (char *)malloc(sizeof(char) * (ft_strlen(strge) - len) + 1);
	if (!temp)
		return (NULL);
	i = 0;
	while (strge[len] != '\0')
		temp[i++] = strge[len++];
	temp[i++] = '\0';
	//free (strge);
	return (temp);
}
char	*ft_get_line(char *strge)
{
	char	*temp;
	int		i;

	i = 0;
	while (strge[i] && strge[i] != '\n')
		i++;
	if (strge[i] == '\0')
		return(strge);
	temp = (char *)malloc(sizeof(char) * i + 2);
	if (!temp)
		return (NULL);
	i = 0;
	while (strge[i] != '\n')
	{
		temp[i] = strge[i];
		i++;
	}
	temp[i] = '\n';
	temp[i+1] = '\0';
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
	while (nbyte > 0)
	{
		nbyte = read(fd ,buffer ,BUFFER_SIZE);
		if (nbyte == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[nbyte] = '\0';
		strge = ft_strjoin(strge, buffer);
		if(!ft_strchr(strge, '\n'))
			break;
	}
	free (buffer);
	return (strge);
}

