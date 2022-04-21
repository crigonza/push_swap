/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:36:52 by crigonza          #+#    #+#             */
/*   Updated: 2022/04/20 15:21:38 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Fills n bytes of the memory pointed to by s with the constant byte c       */

#include"libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	int	i;
	unsigned char *schar;
	schar = s;
	i = 0;
	while (i < n)
	{
		schar[i] = c;
		i ++;
	}
	return (s);
}
