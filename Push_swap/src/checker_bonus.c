/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:40:57 by crigonza          #+#    #+#             */
/*   Updated: 2022/07/06 14:54:49 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker_bonus.h"
int	ft_check_orders(t_stack **c, t_stack **d, char *order)
{
	if (!ft_strncmp(order, "sa\n", 3))
		ft_swap_bonus(c);
	else if(!ft_strncmp(order, "sb\n", 3))
		ft_swap_bonus(d);
	else if(!ft_strncmp(order, "ss\n", 3))
		ft_swap_ab_bonus(c, d);
	else if(!ft_strncmp(order, "pa\n", 3))
		ft_push_a_bonus(c, d);
	else if(!ft_strncmp(order, "pb\n", 3))
		ft_push_b_bonus(c, d);
	else if(!ft_strncmp(order, "ra\n", 3))
		ft_rotate_bonus(c);
	else if(!ft_strncmp(order, "rb\n", 3))
		ft_rotate_bonus(d);
	else if(!ft_strncmp(order, "rr\n", 3))
		ft_rotate_ab_bonus(c, d);
	else
		ft_check_orders_2(c, d, order);
	return(1);
}

int ft_check_orders_2(t_stack **c, t_stack **d, char *order)
{
	if(!ft_strncmp(order, "rrb\n", 4))
		ft_rev_rot_bonus(d);
	else if(!ft_strncmp(order, "rra\n", 4))
		ft_rev_rot_bonus(c);
	else if(!ft_strncmp(order, "rrr\n", 4))
		ft_rev_rot_ab_bonus(c, d);
	else
		return(0);
	return(1);

}

void ft_checker(t_stack **c, t_stack **d)
{
	char *order;
	//char *temp;

	order = get_next_line(0);
	while(order)
	{
		if (!ft_check_orders(c, d, order))
		{
			ft_putendl_fd("Error", 1);
			exit(-1);
		}
		free(order);
		order = get_next_line(0);
	}
}

int main(int argc, char **argv)
{
    t_stack *c;
    t_stack *d;
    int *nbarray;
    int size;

    size = argc - 1;
	d = NULL;
	if (argc < 2)
		return (0);
	else if (argc == 2)
	{
		size = ft_size_bonus(argv[1]);
		if (size == 1)
			return (0);
		nbarray = ft_split_args_bonus(argv[1], size);
	}
	else
		nbarray = ft_parse_bonus(argc, argv);
	if (!nbarray)
	{
		ft_putendl_fd("Error", 1);
		return (0);
	}
    c = ft_stack(nbarray, size);
	ft_checker(&c, &d);



    
}