/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 10:35:14 by crigonza          #+#    #+#             */
/*   Updated: 2022/04/24 10:58:20 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sstr;
	size_t	i;

	if (!s)
		return (NULL);
	sstr = (char *)malloc(len * sizeof(char) + 1);
	if (!sstr)
		return (NULL);
	i = 0;
	while (i < len && start < ft_strlen(s))
	{
		sstr[i] = s[start];
		start++;
		i++;
	}
	sstr[i] = '\0';
	return (sstr);
}
