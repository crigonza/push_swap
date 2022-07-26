/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:57:53 by crigonza          #+#    #+#             */
/*   Updated: 2022/07/25 18:33:49 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_select_nb(t_stack **a, t_stack **b, int max)
{
	int		top;
	int		bottom;
	t_stack	*temp;

	temp = *a;
	top = ft_search_top(a, max);
	bottom = ft_search_bottom(a, max);
	(*a) = temp;
	ft_top_or_bottom(a, bottom, top, 'a');
	ft_push_b(a, b);
}

void	ft_select_nb_(t_stack **a, t_stack **b, int max)
{
	int		top;
	int		bottom;
	t_stack	*temp;

	temp = *b;
	top = ft_search_top(b, max);
	bottom = ft_search_bottom(b, max);
	(*b) = temp;
	ft_top_or_bottom(b, bottom, top, 'b');
	ft_push_a(a, b);
}

void	ft_top_or_bottom(t_stack **stack, int bottom, int top, char c)
{
	if (top < bottom)
	{
		while (top > 0)
		{
			ft_rotate(stack, c);
			top--;
		}
	}
	else
	{
		while (bottom > 0)
		{
			ft_rev_rot(stack, c);
			bottom--;
		}
	}
}

void	ft_sort_to_a(t_stack **a, t_stack **b, int number)
{
	int		top;
	int		bottom;
	t_stack	*tmp;

	tmp = *b;
	top = ft_search_top_(b, number);
	bottom = ft_search_bottom_(b, number);
	(*b) = tmp;
	ft_top_or_bottom(b, bottom, top, 'b');
	ft_push_a(a, b);
}

void	ft_sort_to_b(t_stack **a, t_stack **b, int number)
{
	int		top;
	int		bottom;
	t_stack	*tmp;

	tmp = *a;
	top = ft_search_top_(a, number);
	bottom = ft_search_bottom_(a, number);
	(*a) = tmp;
	ft_top_or_bottom(a, bottom, top, 'a');
	ft_push_b(a, b);
}
