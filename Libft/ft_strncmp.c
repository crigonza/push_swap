/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:51:01 by crigonza          #+#    #+#             */
/*   Updated: 2022/04/21 19:13:11 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Compares the the first n bytes of two strings s1 and s2                    */

#include"libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && *s1 != '\0' || *s2 != '\0')
	{
		if (s1 == s2)
			n--;
		else
			return(*s1 - *s2);	
	}	
	return (s1 - s2);
}
int main (void)
{
	size_t  n;
	int x;
	char *s1 = "abcdefg";
	char *s2 = "agcdefg";
	n = 20;
	x = strncmp(s1, s2, n);
	printf("%d\n", x);
	x = ft_strncmp(s1, s2, n);
	printf("%d", x);

	return (0);
}
