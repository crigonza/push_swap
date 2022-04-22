/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 19:13:55 by crigonza          #+#    #+#             */
/*   Updated: 2022/04/22 19:30:38 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int number;
	int n;

	i = 0;
	number = 0;
	n = 1;
	while (nptr[i] == '\t' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			n *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number *= 10;
		number += nptr[i] - 48;
		i++;
	}
	return (number * n);
}
int main(void)
{
	const char *a;
	a = " 	 -12345";
	printf("%d", ft_atoi(a));
	return (0);
}
