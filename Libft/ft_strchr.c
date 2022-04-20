/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:48:59 by crigonza          #+#    #+#             */
/*   Updated: 2022/04/20 18:16:57 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Returns a pointer to the first occurrence of char c in the string s        */

#include"libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return((char*)s);
		s++;
	}
	return (NULL);
}

int main (void)
{
	char s[] = "abcdefg";
	printf("%s", ft_strchr(s, 'f'));
	return (0);
}

