/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 21:31:42 by crigonza          #+#    #+#             */
/*   Updated: 2022/06/16 19:33:32 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    ft_chunk(t_stack **a, t_stack **b)
{
    int count;

    count = 100;
    while (count > 0)
    {
        if (count > 80)
            ft_select_nb(a, b, 19, 0, count);
        else if (count > 60)
            ft_select_nb(a, b, 39, 20, count);
        else if (count > 40)
            ft_select_nb(a, b, 59, 40, count);
        else if (count > 20)
            ft_select_nb(a, b, 79, 60, count);
        else
            ft_select_nb(a, b, 99, 80, count);
        count --;
    }
}

void    ft_select_nb(t_stack **a, t_stack **b, int max, int min, int count)
{
    int top;
    int botton;
    int tmp;

    top = ft_search_top(a, min, max);
    botton = ft_search_botton(a ,min, max);
    if (top < botton)
        tmp = top;
    else 
        tmp = botton;
    if (tmp < count / 2)
    {
        while(tmp > 0)
        {
            ft_rotate_a(a);
            top --;
        }
    }
    else
    {
        while(tmp > 0)
        {
            ft_rev_rot_a(a);
            botton --;
        }
    }
    ft_prepare_push(a, b);
}

void ft_prepare_push(t_stack **a, t_stack **b)
{
    if ((*b))
    {
        while ((*b)->next)
        {
            if((*a)->nb > (*b)->nb)
                
        }
    }

}

int    ft_search_top(t_stack **a, int max, int min)
{
    int i;

    i = 0;
    while ((*a)->next)
    {
        if ((*a)->nb > min && (*a)->nb < max)
            break;
        (*a) = (*a)->next;
        i ++;
    }
    return(i);
}

int    ft_search_botton(t_stack **a, int max, int min)
{
    int i;

    i = 0;
    while((*a)->next)
        (*a) = (*a)->next;
    while ((*a)->prev)
    {
        if ((*a)->nb > min && (*a)->nb < max)
            break;
        (*a) = (*a)->prev;
        i ++;
    }
    return(i);
}
