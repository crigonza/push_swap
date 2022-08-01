/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 21:31:42 by crigonza          #+#    #+#             */
/*   Updated: 2022/08/01 18:09:12 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker_bonus.h"

void	ft_hundred(t_stack **a, t_stack **b, int size, t_moves **moves)
{
	int	key[2];
	int	i;
	int	j;

	j = 0;
	i = 0;
	key[0] = size / 5;
	key[1] = key[0];
	while (i < 4)
	{
		while (j < key[1])
		{
			ft_select_nb(a, b, key[1] - 1, moves);
			j++;
		}
		key[1] += key[0];
		i++;
	}
	key[1] -= key[0];
	key[0] = size - 1;
	ft_push_to_b(a, b, key, moves);
	ft_push_to_a(a, b, size - 1, moves);
}

void	ft_five_hundred(t_stack **a, t_stack **b, int size, t_moves **moves)
{
	int	key[2];
	int	i;
	int	j;

	j = 0;
	i = 0;
	key[0] = size / 15;
	key[1] = key[0];
	while (i < 14)
	{
		while (j < key[1])
		{
			ft_select_nb(a, b, key[1] - 1, moves);
			j++;
		}
		key[1] += key[0];
		i++;
	}
	key[1] -= key[0];
	key[0] = size - 1;
	ft_push_to_b(a, b, key, moves);
	ft_push_to_a(a, b, size - 1, moves);
}

void	ft_push_to_a(t_stack **a, t_stack **b, int size, t_moves **moves)
{
	while (size >= 0)
	{
		ft_sort_to_a(a, b, size, moves);
		size--;
	}
}

void	ft_push_to_b(t_stack **a, t_stack **b, int *key, t_moves **moves)
{
	while (key[1] <= key[0])
	{
		ft_sort_to_b(a, b, key[1], moves);
		key[1]++;
	}
}
