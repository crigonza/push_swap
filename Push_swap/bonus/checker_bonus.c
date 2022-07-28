/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:40:57 by crigonza          #+#    #+#             */
/*   Updated: 2022/07/28 07:37:41 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker_bonus.h"

int	ft_check_orders(t_stack **c, t_stack **d, char *order)
{
	if (!ft_strncmp(order, "sa", 3))
		ft_swap_bonus(c);
	else if (!ft_strncmp(order, "sb", 3))
		ft_swap_bonus(d);
	else if (!ft_strncmp(order, "ss", 3))
		ft_swap_ab_bonus(c, d);
	else if (!ft_strncmp(order, "pa", 3))
		ft_push_a_bonus(c, d);
	else if (!ft_strncmp(order, "pb", 3))
		ft_push_b_bonus(c, d);
	else if (!ft_strncmp(order, "ra", 3))
		ft_rotate_bonus(c);
	else if (!ft_strncmp(order, "rb", 3))
		ft_rotate_bonus(d);
	else if (!ft_strncmp(order, "rr", 3))
		ft_rotate_ab_bonus(c, d);
	else if (!ft_check_orders_2(c, d, order))
		return (0);
	return (1);
}

int	ft_check_orders_2(t_stack **c, t_stack **d, char *order)
{
	if (!ft_strncmp(order, "rrb", 4))
		ft_rev_rot_bonus(d);
	else if (!ft_strncmp(order, "rra", 4))
		ft_rev_rot_bonus(c);
	else if (!ft_strncmp(order, "rrr", 4))
		ft_rev_rot_ab_bonus(c, d);
	else
		return (0);
	return (1);
}

void	ft_checker(t_stack **a, t_stack **b, char **moves)
{
	int i;

	i = 0;
	while (moves[i])
	{
		if (!ft_check_orders(a, b, moves[i]))
			ft_error();
		i++;
	}
	if (ft_is_sorted(a) && !(*b))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

void	ft_get_array_bonus(int argc, char **argv, t_stack **a)
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
	(*a) = ft_stack(nbarray, size);
	free(nbarray);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_moves *moves;
	int i = 0;

	b = NULL;
	push_swap_bonus(argc, argv, &moves);
	ft_get_array_bonus(argc, argv, &a);
	printf ("%s", mov);
	printf("\n\n");
	
	//printf("%s", moves[2]);
	ft_checker(&a, &b, moves);
	while (a->next)
	{
		printf("%d|", a->nb);
		a = a->next;
	}
	printf("%d|", a->nb);
	
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}
