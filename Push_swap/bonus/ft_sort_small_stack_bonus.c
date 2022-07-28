/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small_stack_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:31:04 by crigonza          #+#    #+#             */
/*   Updated: 2022/07/27 21:13:11 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker_bonus.h"

void	ft_sort_three(t_stack **a, char **moves)
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

void	ft_sort_five(t_stack **a, t_stack **b, char **moves)
{
	int		top;
	int		bot;
	t_stack	*tmp;

	tmp = *a;
	top = ft_search_top_(a, 0);
	bot = ft_search_bottom_(a, 0);
	(*a) = tmp;
	ft_top_or_bottom(a, bot, top, 'a', moves);
	ft_push_b(a, b, moves);
	tmp = *a;
	top = ft_search_top_(a, 1);
	bot = ft_search_bottom_(a, 1);
	(*a) = tmp;
	ft_top_or_bottom(a, bot, top, 'a', moves);
	ft_push_b(a, b, moves);
	ft_sort_three(a, moves);
	ft_push_a(a, b, moves);
	ft_push_a(a, b, moves);
}
