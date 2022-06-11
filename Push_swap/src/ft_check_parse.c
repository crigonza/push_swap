/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 10:04:07 by crigonza          #+#    #+#             */
/*   Updated: 2022/06/11 10:09:28 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int *ft_parse(int argc, char **argv)
{
    int *array;
    int i;

    i = 0;
    array = (int *)malloc(sizeof(int) * argc);
    if(!array)
        return(0);
    while (i < argc)
    {
        array[i] = ft_atoi(argv[i]);
    }
    return (array);
}