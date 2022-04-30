/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:51:49 by crigonza          #+#    #+#             */
/*   Updated: 2022/04/30 12:57:05 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nblen(int n)
{
	int			i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		i = 1;
	}
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			nlen;
	char		*str;
	
	nlen = ft_nblen(n);
	if (!(str = (char *)malloc(sizeof(char) * (nlen + 1))))
		return (NULL);
	str[nlen--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		{
			n = -n;
			str[0] = '-';
		}
	while (n)
	{
		str[nlen] = (n % 10) + 48;
		n = n / 10;
		nlen--; 
	}
	return (str);
}