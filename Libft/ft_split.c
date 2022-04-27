/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 19:22:55 by crigonza          #+#    #+#             */
/*   Updated: 2022/04/26 19:50:02 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wcounter(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s[i] != c)
		i++;
	count++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}
char	*ft_addstr(char const *s, char c, int start)
{
	int		i;
	int		j;
	char	*substr;

	j = 0;
	i = start;
	while (s[i] != c)
		i++;
	j++;
	substr = (char *)malloc(sizeof(char) * (j + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (s[start] != c)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**splitstr;

	if (!s)
		return (NULL);
	j = ft_wcounter(s, c);
	splitstr = (char **)malloc(sizeof(char *) * (j + 1));
	if (!splitstr)
		return (NULL);
	i = 0;
	j = 0;
	while (s[j] != '\0')
	{
		if (s[j] && s[j] == c)
			j++;
		if (s[j] != c)
		{
			splitstr[i] = ft_addstr(s, c, j);
			i++;
			while (s[j] && s[j] != c)
				j++;
		}
	}
	splitstr[i] = NULL;
	return (splitstr);
}
