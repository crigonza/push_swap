/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:08:56 by crigonza          #+#    #+#             */
/*   Updated: 2022/07/06 19:01:00 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	int *nbarray;
	int size;

	size = argc - 1;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	else if (argc == 2)
	{
		size = ft_size(argv[1]);
		if (size == 1)
			return (0);
		nbarray = ft_split_args(argv[1], size);
	}
	else
		nbarray = ft_parse(argc, argv);
	if (!nbarray)
	{
		ft_putendl_fd("Error", 1);
		return (0);
	}
	nbarray = ft_copy(nbarray, size);
	stack_a = ft_stack(nbarray, size);
	if (ft_is_sorted(&stack_a))
		return (0);
	/* ft_push_b(&stack_a, &stack_b);
	ft_push_b(&stack_a, &stack_b);
	ft_push_b(&stack_a, &stack_b);
	ft_rotate(&stack_a, 'a');
	ft_rotate(&stack_b, 'b'); */
	if (size < 100)
		ft_sort_small_stack(&stack_a, &stack_b, size);
	else
		ft_sort_large_stack(&stack_a, &stack_b, size);
	/* printf("\n");
	while (stack_a->next)
	{
		printf("%d**", stack_a->nb);
		stack_a = stack_a->next;
	}
	printf("%d**", stack_a->nb); */
	/* printf("\n");
	while(stack_b->next != 0)
    {
        printf("%d**", stack_b->nb);
        stack_b = stack_b->next;
    }
    printf("%d**", stack_b->nb); */
	free(nbarray);
	ft_free_stack(&stack_a);
	//ft_free_stack(&stack_b);
	return (0);
}