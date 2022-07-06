/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 19:41:37 by crigonza          #+#    #+#             */
/*   Updated: 2022/07/06 13:21:58 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker_bonus.h"

void	ft_swap_bonus(t_stack **stack)
{
	t_stack	*tmp;
	int		swap;

	tmp = *stack;
	swap = tmp->next->nb;
	tmp->next->nb = tmp->nb;
	tmp->nb = swap;
}

void	ft_rotate_bonus(t_stack **stack)
{
	t_stack	*tmp;
	int		nb;

	tmp = *stack;
	nb = tmp->nb;
	while (tmp->next != 0)
	{
		tmp->nb = tmp->next->nb;
		tmp = tmp->next;
	}
	tmp->nb = nb;
}

void	ft_rotate_ab_bonus(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a, 'a');
	ft_rotate(stack_b, 'b');
}

void	ft_rev_rot_bonus(t_stack **stack)
{
	int	nb;

	while ((*stack)->next != 0)
		(*stack) = (*stack)->next;
	nb = (*stack)->nb;
	while ((*stack)->prev != 0)
	{
		(*stack)->nb = (*stack)->prev->nb;
		(*stack) = (*stack)->prev;
	}
	(*stack)->nb = nb;
}

void	ft_rev_rot_ab_bonus(t_stack **stack_a, t_stack **stack_b)
{
	ft_rev_rot(stack_a, 'a');
	ft_rev_rot(stack_b, 'b');
}

