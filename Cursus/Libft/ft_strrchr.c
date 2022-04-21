/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:23:34 by crigonza          #+#    #+#             */
/*   Updated: 2022/04/21 18:48:39 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*Returns a pointer to the last occurrence of the character c in the string s */

#include"libft.h"

char *ft_strrchr(const char *s, int c)
{
    char	*lastf;
    lastf = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			lastf = s;
		s++;
	}
	return (lastf);
}
int main (void)
{
	char s[] = "abcddefg";
	printf("%s", ft_strrchr(s, 'd'));
	return (0);
}
