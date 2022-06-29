/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:08:56 by crigonza          #+#    #+#             */
/*   Updated: 2022/06/29 19:46:52 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	int *nbarray;

	stack_b = NULL;
	if (argc == 2)
		nbarray = ft_split_args(argv);
	else
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
	if (argc < 6)
		ft_sort_small_stack(&stack_a, &stack_b, argc - 1);
	else 
		ft_chunk(&stack_a, &stack_b);
		
	printf("\n");
	while (stack_a->next != 0)
	{
		printf("%d**", stack_a->nb);
		stack_a = stack_a->next;
	}
	printf("%d**", stack_a->nb);
	printf("\n");
	/*while(stack_b->next != 0)
    {
        printf("%d**", stack_b->nb);
        stack_b = stack_b->next;
    }
    printf("%d**", stack_b->nb);  */
	free(nbarray);
	ft_free_stack(&stack_a);
	//ft_free_stack(&stack_b);
	return (0);
}