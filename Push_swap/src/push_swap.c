/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:08:56 by crigonza          #+#    #+#             */
/*   Updated: 2022/07/20 21:30:02 by crigonza         ###   ########.fr       */
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
	else if (size > 3 && size < 21)
		ft_sort_five(a, b, size);
	else if (size > 20 && size < 101)
		ft_hundred(a, b, size);
	else if (size > 100)
		ft_five_hundred(a, b, size);
}

int ft_check_one(long int num)
{
	if (num < -2147483648 || num > 2147483647)
	{
		return (0);
	}
	return (1);
}

int	*ft_get_array(int argc, char **argv)
{
	int	size;
	int	*nbarray;

	size = argc - 1;
	if (argc < 2)
		exit (0);
	else if (argc == 2)
	{
		size = ft_size(argv[1]);
		if (size == 1)
		{
			if (!ft_int_is_valid(argv[1]) || !ft_check_one(ft_atoi(argv[1])))
				return (0);
			exit (0);
		}
		if (!ft_str_is_valid(argv[1]))
			return (0);
		nbarray = ft_split_args(argv[1], size);
	}
	else
		nbarray = ft_parse(argc, argv);
	return (nbarray);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*nbarray;
	int		size;

	size = argc - 1;
	stack_b = NULL;
	nbarray = ft_get_array(argc, argv);
	if (!nbarray)
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	if (argc == 2)
		size = ft_size(argv[1]);
	nbarray = ft_copy(nbarray, size);
	stack_a = ft_stack(nbarray, size);
	if (ft_is_sorted(&stack_a))
		return (0);
	ft_select_sort(&stack_a, &stack_b, size);
	free(nbarray);
	ft_free_stack(&stack_a);
	return (0);
}
