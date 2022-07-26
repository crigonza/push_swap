/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:31:04 by crigonza          #+#    #+#             */
/*   Updated: 2022/07/25 18:27:06 by crigonza         ###   ########.fr       */
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

void	ft_sort_five(t_stack **a, t_stack **b)
{
	int	top;
	int	bot;
	t_stack	*tmp;

	tmp = *a;
	top = ft_search_top_(a, 0);
	bot = ft_search_bottom_(a, 0);
	(*a) = tmp;
	ft_top_or_bottom(a, bot, top , 'a');
	ft_push_b(a, b);
	tmp = *a;
	top = ft_search_top_(a, 1);
	bot = ft_search_bottom_(a, 1);
	(*a)= tmp;
	ft_top_or_bottom(a, bot, top , 'a');
	ft_push_b(a, b);
	ft_sort_three(a);
	ft_push_a(a, b);
	ft_push_a(a, b);
}

