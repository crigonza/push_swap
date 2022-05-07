/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 11:21:33 by crigonza          #+#    #+#             */
/*   Updated: 2022/05/07 13:27:23 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd == -0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	
}

char	*ft_read_file(int fd, char *buffer)
{
	char	*buff;
	int		nbyte;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	nbyte = 1;
	while (nbyte > 0 || (!ft_strchr(buffer, '\n'))
		nbyte = read(fd ,buff ,BUFFER_SIZE);
	if (nbyte == '-1')
		free(buff);
		return (NULL);
	buff[nbyte] = '\0';
	return(ft_strjoin(buffer, buff);
}

int main()
{
	
}
