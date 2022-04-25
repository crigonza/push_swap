/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 19:22:55 by crigonza          #+#    #+#             */
/*   Updated: 2022/04/25 18:37:58 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_wcounter(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (s[i] != c)
		i ++;
		count ++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
	
			count ++;
		i++;
	}
	return (count);
}
char	*ft_addstr(char const *s, char c)
{
	int	i;
	char *substr;

	i = 0;
	while (s[i] != c)
		i ++;
	substr = (char*)malloc(sizeof(char) * (i + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (s[i] != c)
	{
		substr[i] = s[i];
		i ++;
	}
	substr[i] = '\0';
	return (substr);
}

char    **ft_split(char const *s, char c)
{
    int 	i;
	int 	wlen;
	char	**splitstr;

	wlen = ft_wcounter(s, c);
	splitstr = (char **)malloc(sizeof(char *) * wlen + 1);
	if (!splitstr)
		return (NULL);
	i = 0;
	wlen = 0;
	while (s[wlen] != '\0')
	{
		while (s[wlen] && s[wlen] == c)
			wlen ++;
		if (s[wlen] != c)
			{
				splitstr[i] = ft_addstr(s[i], c);
				i++;
				while (s[wlen] && s[wlen] != c)
					wlen++;
			}
	}
	splitstr[i] = '\0';
	return (splitstr);
}
