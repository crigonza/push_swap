/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:08:56 by crigonza          #+#    #+#             */
/*   Updated: 2022/07/26 18:31:34 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

void	ft_select_sort(t_stack **a, t_stack **b, int size)
{
	if (size == 2 && (*a)->nb > (*a)->next->nb)
		ft_swap(a, 'a');
	else if (size == 3)
		ft_sort_three(a);
	else if (size == 4)
		ft_hundred(a, b, size);
	else if (size == 5)
		ft_sort_five(a, b);
	else if (size > 5 && size < 101)
		ft_hundred(a, b, size);
	else if (size > 100)
		ft_five_hundred(a, b, size);
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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	if (argc < 2)
		exit(0);
	stack_b = NULL;
	size = ft_get_array(argc, argv, &stack_a);
	if (!ft_is_sorted(&stack_a))
		ft_select_sort(&stack_a, &stack_b, size);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}
