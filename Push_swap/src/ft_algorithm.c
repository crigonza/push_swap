/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 21:31:42 by crigonza          #+#    #+#             */
/*   Updated: 2022/06/28 08:17:36 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* void    ft_chunk(t_stack **a, t_stack **b)
{
    int count;

    count = 100;
    while (count > 0)
    {
        if (count > 80)
            ft_select_nb(a, b, 19, 0);
        else if (count > 60)
            ft_select_nb(a, b, 39, 20);
        else if (count > 40)
            ft_select_nb(a, b, 59, 40);
        else if (count > 20)
            ft_select_nb(a, b, 79, 60);
        else
            ft_select_nb(a, b, 99, 80);
        count --;
    }
    count = 99;
    while (count <= 0)
    {
        ft_sort_to_a(a, b ,count);
        count --;
    }

} */

void    ft_chunk(t_stack **a, t_stack **b)
{
    int count;

    count = 18;
    while (count > 0)
    {
        if (count > 15)
            ft_select_nb(a, b, 4);
        else if (count > 10 && count < 16)
            ft_select_nb(a, b, 9);
         else if (count > 5 && count < 11)
            ft_select_nb(a, b, 14);
        else
            ft_select_nb(a, b, 18); 
        count --;
    }
    /* count = 19;
    while (count <= 0)
    {
        ft_sort_to_a(a, b ,count);
        count --;
    } */

}

void    ft_select_nb(t_stack **a, t_stack **b, int max)
{
    int top;
    int botton;
    t_stack *temp;

    temp = *a;
    top = ft_search_top(a, max);
    botton = ft_search_botton(a , max);
    (*a) = temp;
    if (top < botton)
    {
        while(top > 0)
        {
            ft_rotate_a(a);
            top --;
        }
    }
    else
    {
        while(botton > 0)
        {
            ft_rev_rot_a(a);
            botton --;
        }
    }
    ft_push_b(a, b);
}

void    ft_sort_to_a(t_stack **a, t_stack **b, int number)
{
    int top;
    int botton;

    top = ft_search_top_(b, number);
    botton = ft_search_botton_(b ,number);
    if (top < botton)
    {
        while(top > 0)
        {
            ft_rotate_b(b);
            top --;
        }
    }
    else
    {
        while(botton > 0)
        {
            ft_rev_rot_b(b);
            botton --;
        }
    }
    ft_push_a(a, b);
}

/* void ft_prepare_push(t_stack **a, t_stack **b)
{
    if ((*b))
    {
        while ((*b)->next)
        {
            if((*a)->nb > (*b)->nb)
                
        }
    }

} */

int    ft_search_top(t_stack **a, int max)
{
    int i;

    i = 0;
    while ((*a)->nb > max)
    {
        (*a) = (*a)->next;
        i++;
    }
    return(i);
}

int    ft_search_botton(t_stack **a, int max)
{
    int i;

    i = 1;
    while((*a)->next->next != 0)
        (*a) = (*a)->next;
    while ((*a)->nb > max)
    {
        (*a) = (*a)->prev;
        i ++;
    }
    return(i);
}

int    ft_search_top_(t_stack **b, int number)
{
    int i;

    i = 0;
    while ((*b)->next)
    {
        if ((*b)->nb == number)
            break;
        (*b) = (*b)->next;
        i ++;
    }
    return(i);
}

int    ft_search_botton_(t_stack **b, int number)
{
    int i;

    i = 0;
    while((*b)->next)
        (*b) = (*b)->next;
    while ((*b)->prev)
    {
        if ((*b)->nb == number)
            break;
        (*b) = (*b)->prev;
        i ++;
    }
    return(i);
}
