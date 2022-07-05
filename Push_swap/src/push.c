/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:57:24 by crigonza          #+#    #+#             */
/*   Updated: 2022/07/05 13:39:11 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	if (*stack_b)
		(*stack_b)->prev = tmp;
	tmp->next = *stack_b;
	*stack_b = tmp;
	(*stack_b)->prev = NULL;
	ft_putendl_fd("pb", 1);
}

void	ft_push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp;

	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	if (*stack_a)
		(*stack_a)->prev = tmp;
	tmp->next = *stack_a;
	*stack_a = tmp;
	(*stack_a)->prev = NULL;
	ft_putendl_fd("pa", 1);
}