/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:54:55 by crigonza          #+#    #+#             */
/*   Updated: 2022/07/11 20:49:27 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_search_top(t_stack **a, int max)
{
	int	i;

	i = 0;
	while ((*a)->nb < max)
	{
		(*a) = (*a)->next;
		i++;
	}
	return (i);
}

int	ft_search_bottom(t_stack **a, int max)
{
	int	i;

	i = 1;
	while ((*a)->next != 0)
		(*a) = (*a)->next;
	while ((*a)->nb < max)
	{
		(*a) = (*a)->prev;
		i++;
	}
	return (i);
}

int	ft_search_top_(t_stack **b, int number)
{
	int	i;

	i = 0;
	while ((*b)->nb != number)
	{
		(*b) = (*b)->next;
		i++;
	}
	return (i);
}

int	ft_search_bottom_(t_stack **b, int number)
{
	int	i;

	i = 1;
	while ((*b)->next != 0)
		(*b) = (*b)->next;
	while ((*b)->nb != number)
	{
		(*b) = (*b)->prev;
		i++;
	}
	return (i);
}
