/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 11:48:29 by crigonza          #+#    #+#             */
/*   Updated: 2022/05/10 19:09:46 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		fd;

	fd = open ("./test.txt", O_RDONLY);
	while(1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		printf("%s",line);
		free (line);
	}
}
