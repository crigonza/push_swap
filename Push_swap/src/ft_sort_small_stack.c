/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:31:04 by crigonza          #+#    #+#             */
/*   Updated: 2022/07/04 21:54:59 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_sort_small_stack(t_stack **a, t_stack **b, int size)
{
	if (size == 3)
		ft_sort_three(a);
	else if (size == 5)
		ft_sort_five(a, b);
}

void	ft_sort_three(t_stack **a)
{
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

void	ft_sort_five(t_stack **a, t_stack **b)
{
	ft_push_b(a, b);
	ft_push_b(a, b);
	ft_sort_three(a);
	ft_sort_five_(a, b);
	ft_push_a(a, b);
	ft_sort_five_(a, b);
	ft_push_a(a, b);
	if (!ft_is_sorted(a))
	{
		while((*a)->nb != 0)
			ft_rotate(a, 'a');
	}

}

void	ft_sort_five_(t_stack **a, t_stack **b)
{
	int next;
	int min;

	min = ft_find_min(a);
	next = ft_find_next(a, (*b)->nb);
	if (next)
	{
		while((*a)->nb != next)
			ft_rotate(a, 'a');
	}
	else
	{
		while((*a)->nb != min)
			ft_rotate(a, 'a');
	}	
}
