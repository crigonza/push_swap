/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 19:41:37 by crigonza          #+#    #+#             */
/*   Updated: 2022/07/11 20:38:20 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_swap(t_stack **stack, char c)
{
	t_stack	*tmp;
	int		swap;

	tmp = *stack;
	swap = tmp->next->nb;
	tmp->next->nb = tmp->nb;
	tmp->nb = swap;
	if (c == 'a')
		ft_putendl_fd("sa", 1);
	else if (c == 'b')
		ft_putendl_fd("sb", 1);
	else if (c == 'x')
		return ;
}

void	ft_rotate(t_stack **stack, char c)
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
	if (c == 'a')
		ft_putendl_fd("ra", 1);
	else if (c == 'b')
		ft_putendl_fd("rb", 1);
	else if (c == 'x')
		return ;
}

void	ft_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a, 'x');
	ft_rotate(stack_b, 'x');
	ft_putendl_fd("rr", 1);
}

void	ft_rev_rot(t_stack **stack, char c)
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
	if (c == 'a')
		ft_putendl_fd("rra", 1);
	else if (c == 'b')
		ft_putendl_fd("rrb", 1);
	else if (c == 'x')
		return ;
}

void	ft_rev_rot_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_rev_rot(stack_a, 'x');
	ft_rev_rot(stack_b, 'x');
	ft_putendl_fd("rrr", 1);
}
