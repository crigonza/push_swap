/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:36:44 by crigonza          #+#    #+#             */
/*   Updated: 2022/06/27 21:02:34 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*ft_stack(int *numbers, int size)
{
	t_stack	*temp;
	t_stack	*stack;
	int		i;

	i = 0;
	stack = NULL;
	while (i < size - 1)
	{
		temp = ft_new_node(numbers[i]);
		ft_stack_add_node(&stack, temp);
		i++;
	}
	return (stack);
}

t_stack	*ft_new_node(int number)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->nb = number;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_stack_add_node(t_stack **stack, t_stack *node)
{
	t_stack	*aux;

	if (*stack == NULL)
	{
		*stack = node;
		return ;
	}
	aux = *stack;
	while (aux->next)
		aux = aux->next;
	aux->next = node;
	node->next = NULL;
	node->prev = aux;
}

void	ft_add_top(t_stack **stack, t_stack *node)
{
	if (*stack == NULL)
	{
		(*stack) = node;
		return ;
	}
	node->next = *stack;
	(*stack)->prev = node;
	*stack = node;
}

void ft_free_stack(t_stack **stack)
{
    t_stack *temp;

    temp = *stack;
    *stack = temp->next;
    free(temp);
    if(*stack != 0)
        ft_free_stack(stack);
}