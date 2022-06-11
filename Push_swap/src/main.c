/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:52:48 by crigonza          #+#    #+#             */
/*   Updated: 2022/06/11 10:12:11 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int main (int argc, char **argv)
{
    int *nbarray;
    int i;

    i = 0;
    nbarray = ft_parse(argc - 1, argv);
    while(i < argc-1)
    {
        printf("%d**", nbarray[i]);
        i++;
    }


}