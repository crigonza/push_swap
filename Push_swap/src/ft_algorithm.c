/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 21:31:42 by crigonza          #+#    #+#             */
/*   Updated: 2022/07/11 20:37:32 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_hundred(t_stack **a, t_stack **b, int size)
{
	int	total;

	total = size - 1;
	while (size > 0)
	{
		if (size > 80)
			ft_select_nb(a, b, 79);
		else if (size > 60 && size < 81)
			ft_select_nb(a, b, 59);
		else if (size > 40 && size < 61)
			ft_select_nb(a, b, 39);
		else if (size > 20 && size < 41)
			ft_select_nb(a, b, 19);
		else
			ft_select_nb(a, b, 0);
		size--;
	}
	ft_push_to_a(a, b, total);
}

void	ft_five_hundred(t_stack **a, t_stack **b, int size)
{
	int	total;

	total = size - 1;
	while (size > 221)
	{
		if (size > 460)
			ft_select_nb(a, b, 459);
		else if (size > 420 && size < 461)
			ft_select_nb(a, b, 419);
		else if (size > 380 && size < 421)
			ft_select_nb(a, b, 379);
		else if (size > 340 && size < 381)
			ft_select_nb(a, b, 339);
		else if (size > 300 && size < 341)
			ft_select_nb(a, b, 299);
		else if (size > 260 && size < 301)
			ft_select_nb(a, b, 259);
		else if (size > 220 && size < 261)
			ft_select_nb(a, b, 219);
		size--;
	}
	ft_five_hundred_2(a, b, size, total);
}

void	ft_five_hundred_2(t_stack **a, t_stack **b, int size, int total)
{
	while (size > 0)
	{
		if (size > 180 && size < 221)
			ft_select_nb(a, b, 179);
		else if (size > 140 && size < 181)
			ft_select_nb(a, b, 139);
		else if (size > 100 && size < 141)
			ft_select_nb(a, b, 99);
		else if (size > 60 && size < 101)
			ft_select_nb(a, b, 59);
		else if (size > 20 && size < 61)
			ft_select_nb(a, b, 19);
		else
			ft_select_nb(a, b, 0);
		size--;
	}
	ft_push_to_a(a, b, total);
}

void	ft_push_to_a(t_stack **a, t_stack **b, int size)
{
	while (size >= 0)
	{
		ft_sort_to_a(a, b, size);
		size--;
	}
}
