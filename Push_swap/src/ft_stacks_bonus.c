/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacks_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:45:19 by crigonza          #+#    #+#             */
/*   Updated: 2022/07/06 20:51:54 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker_bonus.h"

t_stack	*ft_stack_bonus(int *numbers, int size)
{
	t_stack	*temp;
	t_stack	*stack;
	int		i;

	i = 0;
	stack = NULL;
	while (i < size)
	{
		temp = ft_new_node_bonus(numbers[i]);
		ft_stack_add_node_bonus(&stack, temp);
		i++;
	}
	return (stack);
}

t_stack	*ft_new_node_bonus(int number)
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

void	ft_stack_add_node_bonus(t_stack **st, t_stack *node)
{
	t_stack	*tmp;

	if (*st == NULL)
	{
		*st = node;
		return ;
	}
	tmp = ft_last_bonus(*st);
	tmp->next = node;
	node->prev = tmp;
}

t_stack	*ft_last_bonus(t_stack *st)
{
	while (st->next)
		st = st->next;
	return (st);
}

int	ft_is_sorted_bonus(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	if (tmp->nb < tmp->next->nb)
		tmp = tmp->next;
	else
		return (0);
	while (tmp->next)
	{
		if ((tmp->nb < tmp->next->nb) && (tmp->nb > tmp->prev->nb))
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}