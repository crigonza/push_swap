/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:40:57 by crigonza          #+#    #+#             */
/*   Updated: 2022/07/05 13:50:10 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int main(int argc, char **argv)
{
    t_stack **a;
    t_stack **b;
    int *nbarray;
    int size;

    size = argc - 1;
	b = NULL;
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
    a = ft_stack(nbarray, size);


    
}