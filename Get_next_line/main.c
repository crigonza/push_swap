/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 11:48:29 by crigonza          #+#    #+#             */
/*   Updated: 2022/05/07 11:58:27 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main()
{
	char	*line;
	int		fd;

	fd = open (test, O_RDONLY);
	if (fd < 0)
		return (NULL);
	printf("%s,line = get_next_line(fd));
	return (0)
}
