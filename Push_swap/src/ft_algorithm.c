/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 21:31:42 by crigonza          #+#    #+#             */
/*   Updated: 2022/07/25 17:53:55 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void ft_hundred(t_stack **a, t_stack ** b, int size)
{
	int key;
	int key2;
	int i;
	int j;

	j = 0;
	i = 0;
	key = size / 5;
	key2 = key;
	while (i < 4)
	{
		while (j < key2)
		{
			ft_select_nb(a, b, key2 - 1);
			j++;
		}
		key2 += key;
		i ++;
	}
	key2 -= key;
	ft_push_to_b(a, b, key2, size - 1);
	ft_push_to_a(a, b, size - 1, 0);
}

void ft_five_hundred(t_stack **a, t_stack ** b, int size)
{
	int key;
	int key2;
	int i;
	int j;

	j = 0;
	i = 0;
	key = size / 15;
	key2 = key;
	while (i < 14)
	{
		while (j < key2)
		{
			ft_select_nb(a, b, key2 - 1);
			j++;
		}
		key2 += key;
		i ++;
	}
	key2 -= key;
	ft_push_to_b(a, b, key2, size - 1);
	ft_push_to_a(a, b, size - 1, 0);
} 

void	ft_push_to_a(t_stack **a, t_stack **b, int size, int siz)
{
	while (size >= siz)
	{
		ft_sort_to_a(a, b, size);
		size--;
	}
}

void	ft_push_to_b(t_stack **a, t_stack **b, int size, int siz)
{
	while (size <= siz)
	{
		ft_sort_to_b(a, b, size);
		size++;
	}
}
