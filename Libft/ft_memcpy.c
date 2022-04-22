/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:34:26 by crigonza          #+#    #+#             */
/*   Updated: 2022/04/20 16:57:25 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Copies  n  bytes  from memory area src to memory area dest                 */

#include"libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int i;
	const char *schar;
	unsigned char *dchar;
	schar = src;
	dchar = dest;
	i = 0;
	if ((schar != NULL) && (dchar != NULL))
	{
	while (i<n)
	{
		dchar[i] = schar[i];
		i++;
	}
	return (dest);
}
