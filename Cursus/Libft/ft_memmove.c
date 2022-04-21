/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:10:52 by crigonza          #+#    #+#             */
/*   Updated: 2022/04/20 17:36:22 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int i;
	const char *schar;
	unsigned char *dchar;
	unsigned char *temp;
	schar = src;
	dchar = dest;
	i = 0;
	if ((schar != NULL) && (dchar != NULL))
	{
		while (i<n)
		{
			temp[i] = schar[i];
			i++;
		}
		i = 0;
		while (i<n)
		{
			dchar[i] = temp[i];
			i++;
		}
	}
	return (dest);
}
