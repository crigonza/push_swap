/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:57:53 by crigonza          #+#    #+#             */
/*   Updated: 2022/07/11 18:04:37 by crigonza         ###   ########.fr       */
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

void ft_top_or_bottom(t_stack **stack, int bottom, int top, char c)
{
	if (top< bottom)
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

int	ft_find_min(t_stack **b)
{
	int		min;
	t_stack	*tmp;

	tmp = *b;
	min = tmp->nb;
	while (tmp->next)
	{
		if (min > tmp->nb)
			min = tmp->nb;
		tmp = tmp->next;
	}
	if (min > tmp->nb)
		min = tmp->nb;
	return (min);
}

int	ft_find_next(t_stack **b, int num)
{
	int		i;
	t_stack	*tmp;

	tmp = *b;
	i = 0;
	if (tmp->next)
	{
		while (i < 10)
		{
			tmp = *b;
			if (tmp->nb == num + i)
				return (num + i);
			while (tmp->next)
			{
				tmp = tmp->next;
				if (tmp->nb == num + i)
					return (num + i);
			}
			i++;
		}
	}
	return (0);
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