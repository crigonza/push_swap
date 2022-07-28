/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:40:57 by crigonza          #+#    #+#             */
/*   Updated: 2022/07/28 14:36:52 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker_bonus.h"

int	ft_check_orders(t_stack **c, t_stack **d, char *order)
{
	if (!ft_strncmp(order, "sa\n", 4))
		ft_swap_bonus(c);
	else if (!ft_strncmp(order, "sb\n", 4))
		ft_swap_bonus(d);
	else if (!ft_strncmp(order, "ss\n", 4))
		ft_swap_ab_bonus(c, d);
	else if (!ft_strncmp(order, "pa\n", 4))
		ft_push_a_bonus(c, d);
	else if (!ft_strncmp(order, "pb\n", 4))
		ft_push_b_bonus(c, d);
	else if (!ft_strncmp(order, "ra\n", 4))
		ft_rotate_bonus(c);
	else if (!ft_strncmp(order, "rb\n", 4))
		ft_rotate_bonus(d);
	else if (!ft_strncmp(order, "rr\n", 4))
		ft_rotate_ab_bonus(c, d);
	else if (!ft_check_orders_2(c, d, order))
		return (0);
	return (1);
}

int	ft_check_orders_2(t_stack **c, t_stack **d, char *order)
{
	if (!ft_strncmp(order, "rrb\n", 5))
		ft_rev_rot_bonus(d);
	else if (!ft_strncmp(order, "rra\n", 5))
		ft_rev_rot_bonus(c);
	else if (!ft_strncmp(order, "rrr\n", 5))
		ft_rev_rot_ab_bonus(c, d);
	else
		return (0);
	return (1);
}

void	ft_checker(t_stack **a, t_stack **b, t_moves *moves)
{
	while (moves->next)
	{
		if (!ft_check_orders(a, b, moves->move))
			ft_error();
		moves = moves->next;
	}
	if (!ft_check_orders(a, b, moves->move))
		ft_error();
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
	t_moves		*moves;

	b = NULL;
	push_swap_bonus(argc, argv, &moves);
	ft_get_array_bonus(argc, argv, &a);
	ft_checker(&a, &b, moves);
	while (moves->next)
	{
		printf("%s", moves->move);
		moves = moves->next;
	}
	printf("%s", moves->move);
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}
