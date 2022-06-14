/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 10:04:07 by crigonza          #+#    #+#             */
/*   Updated: 2022/06/13 22:03:01 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int *ft_parse(int argc, char **argv)
{
    int *temp;
    int i;

    i = 0;
    temp = (int *)malloc(sizeof(int) * argc - 1);
    if(!temp)
        return(0);
    while (i < argc - 1)
    {
        if (!ft_int_is_valid(argv[i + 1]))
        {
            free(temp);
            return(0);
        }
        temp[i] = ft_atoi(argv[i + 1]);
        if (ft_num_is_in(temp, i))
        {
            free(temp);
            return (0);
        }
        i++;
    }
    return (temp);
}

int ft_num_is_in(int *temp, int i)
{
    int j;

    j = 0;
    while(j < i)
    {
        if(temp[j] == temp[i])
            return(1);
        j ++;
    }
    return(0);
}

int ft_int_is_valid(char *number)
{
    int i;

    i = 0;
    if(number[i] == '-' || number[i] == '+')
        i++;
    while(number[i])
    {
        if (!ft_isdigit(number[i]))
            return(0);
        i++;
    }
    return(1);
}

int ft_is_sorted(t_stack **stack)
{
    t_stack *tmp;

    tmp = *stack;
    if (tmp->nb < tmp->next->nb)
        tmp = tmp->next;
    else
        return(0);
    while (tmp->next->next)
    {
        if((tmp->nb < tmp->next->nb) && (tmp->nb > tmp->prev->nb))
            tmp = tmp->next;
        else 
            return (0);
    }
    return(1);
}

int *ft_simplify_nbs(int *numbers)
{
    int *copy;
    int i;
    //int j;

    copy = NULL;
    i = 0;
    //j = 0;
    while (numbers[i])
    {
        copy[i] = numbers[i];
        i++;
    }
   /*  i = 0;
    while (i < size)
    {
        while (j < size)
        {
            if (copy[i] == numbers[j])
                copy[i] = j;
            j++;
        }
        i++;
    }
    i = 0;
    while (copy[i])
    {
        printf("  %d  ", copy[i]);
        i ++;
    } */
    return(copy);
}
