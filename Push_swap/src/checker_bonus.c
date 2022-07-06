/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:40:57 by crigonza          #+#    #+#             */
/*   Updated: 2022/07/06 07:07:30 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void ft_checker(t_stack **c, t_stack **d)
{
	char *order;
	char *temp;

	order = get_next_line(0);
	while(order)
	{
		if (!ft_instruc(c, d, order))
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
    c = ft_stack(nbarray, size);
	ft_checker(&c, &d);



    
}