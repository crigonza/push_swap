/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:12:21 by crigonza          #+#    #+#             */
/*   Updated: 2022/04/22 17:28:04 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*chars1;
	unsigned char	*chars2;
	size_t 		i;

	chars1 = s1;
	chars2 = s2;
	i = 0;
	if ( n == 0 || s1 == s2)
		return(0);
	while (i < n)
	{
		if (chars1[i] == chars2[i])
			i ++;
		else
			return (chars1[i] - chars2[i]);
	}
}
