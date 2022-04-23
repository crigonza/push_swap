/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 11:11:14 by crigonza          #+#    #+#             */
/*   Updated: 2022/04/23 12:16:39 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	j = 0;
	if (dstsize > 0)
	{
		while (j < (dstsize -1) && src[j] != '\0')
		{
			dst[i] = src[j];
			i ++;
			j ++;
		}	
		dst[i] = '\0';
	}
	if (ft_strlen(dst) <= dstsize)
		return(ft_strlen(src) + ft_strlen(dst));
	else
		return(ft_strlen(src) + dstsize);
}
