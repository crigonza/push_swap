/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:31:04 by crigonza          #+#    #+#             */
/*   Updated: 2022/07/11 20:03:49 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_sort_three(t_stack **a)
{
	if (ft_is_sorted(a))
		return ;
	if ((*a)->nb < (*a)->next->nb)
	{
		if ((*a)->nb < (*a)->next->next->nb)
		{
			ft_swap(a, 'a');
			ft_rotate(a, 'a');
		}
		else
			ft_rev_rot(a, 'a');
	}
	else if ((*a)->nb > (*a)->next->nb)
	{
		if ((*a)->next->nb > (*a)->next->next->nb)
		{
			ft_swap(a, 'a');
			ft_rev_rot(a, 'a');
		}
		else if ((*a)->nb < (*a)->next->next->nb)
			ft_swap(a, 'a');
		else
			ft_rotate(a, 'a');
	}
}

void	ft_sort_five(t_stack **a, t_stack **b, int size)
{
	int times;

	times = size - 3;
	while (times > 0)
	{
		ft_push_b(a, b);
		times --;
	}
	ft_sort_three(a);
	times = size - 3;
	while (times > 0)
	{
		ft_sort_five_(a, b);
		ft_push_a(a, b);
		times --;
	}
	if (!ft_is_sorted(a))
	{
		while ((*a)->nb != 0)
			ft_rotate(a, 'a');
	}
}

void	ft_sort_five_(t_stack **a, t_stack **b)
{
	int	next;
	int	min;

	min = ft_find_min(a);
	next = ft_find_next(a, (*b)->nb);
	if (next)
	{
		while ((*a)->nb != next)
			ft_rotate(a, 'a');
	}
	else
	{
		while ((*a)->nb != min)
			ft_rotate(a, 'a');
	}
}
