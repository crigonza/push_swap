/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:51:49 by crigonza          #+#    #+#             */
/*   Updated: 2022/04/27 15:20:39 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nblen(int n)
{
	long int	nbr;
	int			i;

	i = 0;
	nbr = n;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		nbr = -nbr;
	i = 1;
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}
char	*ft_addst(char *str, long nbr, int len)
{
	char *aux;

	aux = str;
	aux[len--] = '\0';
	if (nbr == -2147483648)
		return (aux);
	if (nbr == 0)
		aux[0] = '0';
	if (nbr < 0)
	{
		nbr = -nbr;
		aux[0] = '-';
	}
	while (nbr > 0)
	{
		aux[len] = (nbr % 10) + 48;
		nbr /= 10;
		len--;
	}
	return (aux);
}
char	*ft_alloc(long nbr, int len)
{
	char	*str;

	if (nbr == -2147483648)
	{
		str = (char *)malloc(12);
		if (!str)
			return (NULL);
		ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str = ft_addst(str, nbr, len);
	return (str);
}

char	*ft_itoa(int n)
{
	int			i;
	char		*str;
	long int	nbr;

	nbr = n;
	i = ft_nblen(n);
	str = ft_alloc(nbr, i);
	if (!str)
		return (NULL);
	return (str);
}