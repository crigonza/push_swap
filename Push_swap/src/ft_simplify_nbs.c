/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simplify_nbs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:09:17 by crigonza          #+#    #+#             */
/*   Updated: 2022/07/11 20:48:44 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	*ft_copy(int *numbers, int size)
{
	int	*copy;
	int	i;

	copy = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		copy[i] = numbers[i];
		i++;
	}
	numbers = ft_simplify_nbs(numbers, ft_order_copy(copy, size), size);
	return (numbers);
}

int	*ft_order_copy(int *copy, int size)
{
	int	i;
	int	j;
	int	swap;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (copy[i] > copy[j])
			{
				swap = copy[i];
				copy[i] = copy[j];
				copy[j] = swap;
			}
			j++;
		}
		i++;
	}
	return (copy);
}

int	*ft_simplify_nbs(int *numbers, int *copy, int size)
{
	int	i;
	int	j;
	int	y;

	i = 0;
	while (i < size)
	{
		y = 0;
		j = 0;
		while (j < size && y == 0)
		{
			if (numbers[i] == copy[j])
			{
				numbers[i] = j;
				y = 1;
			}
			j++;
		}
		i++;
	}
	free(copy);
	return (numbers);
}
