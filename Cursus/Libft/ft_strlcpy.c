/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:37:10 by crigonza          #+#    #+#             */
/*   Updated: 2022/04/19 20:00:36 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	i = 0;
	if (dstsize > 0)
	{
		while ( src[i] != '\0')
		{
			if(i == dstsize)
			{
				i--;
				break;
			}
			dst[i] = src[i];
			i ++;
		}
	}
	dst[i] = '\0';
	while (src[i] != '\0')
		i ++;
	return (i);
}
