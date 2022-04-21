/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:48:59 by crigonza          #+#    #+#             */
/*   Updated: 2022/04/21 17:22:19 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char*)s);
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

