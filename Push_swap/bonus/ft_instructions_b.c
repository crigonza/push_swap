/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 19:41:37 by crigonza          #+#    #+#             */
/*   Updated: 2022/07/28 14:09:39 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker_bonus.h"

void	ft_swap(t_stack **stack, char c, t_moves **moves)
{
	t_stack	*tmp;
	int		swap;

	tmp = *stack;
	swap = tmp->next->nb;
	tmp->next->nb = tmp->nb;
	tmp->nb = swap;
	if (c == 'a')
		ft_new_move(moves, "sa\n");
	else if (c == 'b')
		ft_new_move(moves, "sb\n");
	else if (c == 'x')
		return ;
}

void	ft_rotate(t_stack **stack, char c, t_moves **moves)
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
		ft_new_move(moves, "ra\n");
	else if (c == 'b')
		ft_new_move(moves, "rb\n");
	else if (c == 'x')
		return ;
}

void	ft_rotate_ab(t_stack **stack_a, t_stack **stack_b, t_moves **moves)
{
	ft_rotate(stack_a, 'x', moves);
	ft_rotate(stack_b, 'x', moves);
	ft_new_move(moves, "rr\n");
}

void	ft_rev_rot(t_stack **stack, char c, t_moves **moves)
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
		ft_new_move(moves, "rra\n");
	else if (c == 'b')
		ft_new_move(moves, "rrb\n");
	else if (c == 'x')
		return ;
}

void	ft_rev_rot_ab(t_stack **stack_a, t_stack **stack_b, t_moves **moves)
{
	ft_rev_rot(stack_a, 'x', moves);
	ft_rev_rot(stack_b, 'x', moves);
	ft_new_move(moves, "rrr\n");
}
