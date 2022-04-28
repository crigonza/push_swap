/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 11:11:14 by crigonza          #+#    #+#             */
/*   Updated: 2022/04/28 17:43:27 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* appends the NUL-terminated string src to the end of dst. It will append at 
   most size - strlen(dst) - 1 bytes, NUL-terminating the result. */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t dlen;
	size_t slen;
	size_t i;

	i = 0;
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (dlen > dstsize)
		dlen = dstsize;
	while ((dlen + i) < (dstsize - 1) && src[i] != '\0')
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}