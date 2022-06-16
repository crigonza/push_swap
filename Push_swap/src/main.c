/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:52:48 by crigonza          #+#    #+#             */
/*   Updated: 2022/06/16 18:22:39 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	int *nbarray;

	stack_b = NULL;
	nbarray = ft_parse(argc, argv);
	if (!nbarray)
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	nbarray = ft_copy(nbarray, argc - 1);
	stack_a = ft_stack(nbarray, argc);
	if (ft_is_sorted(&stack_a))
		return (0);
	ft_sort_small_stack(&stack_a, &stack_b, argc - 1);
	/* ft_push_b(&stack_a, &stack_b);
    ft_push_b(&stack_a, &stack_b);
    ft_swap_a(&stack_a);
    ft_rev_rot_a(&stack_a); */
	while (stack_a->next)
	{
		printf("%d**", stack_a->nb);
		stack_a = stack_a->next;
	}
	//printf("%d**", stack_a->nb);
	printf("\n");
	/* while(stack_b->next)
    {
        printf("%d**", stack_b->nb);
        stack_b = stack_b->next;
    }
    printf("%d**", stack_b->nb); */
	free(nbarray);
	return (0);
}