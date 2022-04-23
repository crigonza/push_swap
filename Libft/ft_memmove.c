/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:10:52 by crigonza          #+#    #+#             */
/*   Updated: 2022/04/23 13:23:10 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Copies n bytes from memory area src to memory area dest. */

#include"libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	unsigned char *schar;
	unsigned char *dchar;
	schar = (unsigned char *)src;
	dchar = (unsigned char *)dest;
	i = 0;
	if (n == 0 || src == dest)
	   return (dest);	
	if (schar > dchar)
	{
		while(n > 0)
		{
			dchar[n] = schar[n];
			n--;
		}
		return (dest);
	}
	while (i < n)
	{
		dchar[i] = schar[i];
		i++;
	}
	return (dest);
}
