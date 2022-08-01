/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils_2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:57:53 by crigonza          #+#    #+#             */
/*   Updated: 2022/08/01 18:07:38 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker_bonus.h"

void	ft_select_nb(t_stack **a, t_stack **b, int max, t_moves **moves)
{
	int		tb[2];
	t_stack	*temp;

	temp = *a;
	tb[0] = ft_search_top(a, max);
	tb[1] = ft_search_bottom(a, max);
	(*a) = temp;
	ft_top_or_bottom(a, tb, 'a', moves);
	ft_push_b(a, b, moves);
}

void	ft_select_nb_(t_stack **a, t_stack **b, int max, t_moves **moves)
{
	int		tb[2];
	t_stack	*temp;

	temp = *b;
	tb[0] = ft_search_top(b, max);
	tb[1] = ft_search_bottom(b, max);
	(*b) = temp;
	ft_top_or_bottom(b, tb, 'b', moves);
	ft_push_a(a, b, moves);
}

void	ft_top_or_bottom(t_stack **stack, int *tb, char c, t_moves **moves)
{
	int	top;
	int	bottom;

	top = tb[0];
	bottom = tb[1];
	if (top < bottom)
	{
		while (top > 0)
		{
			ft_rotate(stack, c, moves);
			top--;
		}
	}
	else
	{
		while (bottom > 0)
		{
			ft_rev_rot(stack, c, moves);
			bottom--;
		}
	}
}

void	ft_sort_to_a(t_stack **a, t_stack **b, int number, t_moves **moves)
{
	int		tb[2];
	t_stack	*tmp;

	tmp = *b;
	tb[0] = ft_search_top_(b, number);
	tb[1] = ft_search_bottom_(b, number);
	(*b) = tmp;
	ft_top_or_bottom(b, tb, 'b', moves);
	ft_push_a(a, b, moves);
}

void	ft_sort_to_b(t_stack **a, t_stack **b, int number, t_moves **moves)
{
	int		tb[2];
	t_stack	*tmp;

	tmp = *a;
	tb[0] = ft_search_top_(a, number);
	tb[1] = ft_search_bottom_(a, number);
	(*a) = tmp;
	ft_top_or_bottom(a, tb, 'a', moves);
	ft_push_b(a, b, moves);
}
