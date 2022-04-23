/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:35:45 by crigonza          #+#    #+#             */
/*   Updated: 2022/04/23 12:17:06 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char *ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	x;

	i = 0;
	j = 0;
	x = 0;
	if (s2[0] == '\0')
		return((char*)s1);
	while(s1[i] != '\0' && i < len)
	{
		if (s1[i] != s2[j])
			i++;
		else
			x = i;
			while (s1[i] == s2[j])
			{
				x++;
				j++;
			}
			if (s2[j] == '\0')
				return((char*)&s1[i]);
	}
	return (NULL);
}
