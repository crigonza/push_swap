/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small_stack_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:31:04 by crigonza          #+#    #+#             */
/*   Updated: 2022/08/01 18:05:56 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker_bonus.h"

void	ft_sort_three(t_stack **a, t_moves **moves)
{
	if (ft_is_sorted(a))
		return ;
	if ((*a)->nb < (*a)->next->nb)
	{
		if ((*a)->nb < (*a)->next->next->nb)
		{
			ft_swap(a, 'a', moves);
			ft_rotate(a, 'a', moves);
		}
		else
			ft_rev_rot(a, 'a', moves);
	}
	else if ((*a)->nb > (*a)->next->nb)
	{
		if ((*a)->next->nb > (*a)->next->next->nb)
		{
			ft_swap(a, 'a', moves);
			ft_rev_rot(a, 'a', moves);
		}
		else if ((*a)->nb < (*a)->next->next->nb)
			ft_swap(a, 'a', moves);
		else
			ft_rotate(a, 'a', moves);
	}
}

void	ft_sort_five(t_stack **a, t_stack **b, t_moves **moves)
{
	int		tb[2];
	t_stack	*tmp;

	tmp = *a;
	tb[0] = ft_search_top_(a, 0);
	tb[1] = ft_search_bottom_(a, 0);
	(*a) = tmp;
	ft_top_or_bottom(a, tb, 'a', moves);
	ft_push_b(a, b, moves);
	tmp = *a;
	tb[0] = ft_search_top_(a, 1);
	tb[1] = ft_search_bottom_(a, 1);
	(*a) = tmp;
	ft_top_or_bottom(a, tb, 'a', moves);
	ft_push_b(a, b, moves);
	ft_sort_three(a, moves);
	ft_push_a(a, b, moves);
	ft_push_a(a, b, moves);
}
