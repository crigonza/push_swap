/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:08:56 by crigonza          #+#    #+#             */
/*   Updated: 2022/07/28 14:20:00 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker_bonus.h"

int	ft_is_sorted(t_stack **stack)
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

void	ft_select_sort(t_stack **a, t_stack **b, int size, t_moves **moves)
{
	if (size == 2 && (*a)->nb > (*a)->next->nb)
		ft_swap(a, 'a', moves);
	else if (size == 3)
		ft_sort_three(a, moves);
	else if (size == 4)
		ft_hundred(a, b, size, moves);
	else if (size == 5)
		ft_sort_five(a, b, moves);
	else if (size > 5 && size < 101)
		ft_hundred(a, b, size, moves);
	else if (size > 100)
		ft_five_hundred(a, b, size, moves);
}

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

int	ft_get_array(int argc, char **argv, t_stack **a)
{
	int	size;
	int	*nbarray;

	nbarray = NULL;
	size = argc - 1;
	if (argc == 2)
	{
		size = ft_size(argv[1]);
		if (size == 1 || size == 0)
			exit(0);
		if (size > 1)
			nbarray = ft_split_args(argv[1], size);
	}
	else
		nbarray = ft_parse(argc, argv);
	if (!nbarray)
		ft_error();
	nbarray = ft_copy(nbarray, size);
	(*a) = ft_stack(nbarray, size);
	free(nbarray);
	return (size);
}

void	push_swap_bonus(int argc, char **argv, t_moves **moves)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	if (argc < 2)
		exit(0);
	stack_b = NULL;
	size = ft_get_array(argc, argv, &stack_a);
	if (!ft_is_sorted(&stack_a))
		ft_select_sort(&stack_a, &stack_b, size, moves);
	/* while (stack_a->next)
	{
		printf("%d|", stack_a->nb);
		stack_a = stack_a->next;
	}
	printf("%d|", stack_a->nb); */
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
}
