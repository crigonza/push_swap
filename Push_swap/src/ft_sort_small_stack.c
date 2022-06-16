/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:31:04 by crigonza          #+#    #+#             */
/*   Updated: 2022/06/15 22:36:52 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void ft_sort_small_stack(t_stack **a, t_stack **b, int size)
{
    if (size == 3)
        ft_sort_three(a);
    else if (size == 5)
        ft_sort_five(a, b);
}

void    ft_sort_three(t_stack **a)
{
    if ((*a)->nb < (*a)->next->nb)
    {
        if ((*a)->nb < (*a)->next->next->nb)
        {
            ft_swap_a(a);
            ft_rotate_a(a);
        }
        else
            ft_rev_rot_a(a);
    }
    else if((*a)->nb > (*a)->next->nb)
    {
        if ((*a)->next->nb > (*a)->next->next->nb)
        {
            ft_swap_a(a);
            ft_rev_rot_a(a);
        }
        else if((*a)->nb < (*a)->next->next->nb)
            ft_swap_a(a);
        else
            ft_rotate_a(a);
    }
}

void ft_sort_five(t_stack **a, t_stack **b)
{
    ft_push_b(a, b);
    ft_push_b(a, b);
    ft_sort_three(a);
    ft_push_a(a, b);
    ft_sort_five_(a);
    ft_push_a(a, b);
    ft_sort_five_(a);
}

void    ft_sort_five_(t_stack **a)
{
    if ((*a)->nb > (*a)->next->nb)
    {
        if ((*a)->nb < (*a)->next->next->nb)
            ft_swap_a(a);
        else if ((*a)->nb > (*a)->next->next->nb)
        {
            if ((*a)->next->next->next->next == NULL)
            {
                if ((*a)->nb > (*a)->next->next->next->nb)
                    ft_rotate_a(a);
            }
            else
            {
                if ((*a)->nb > (*a)->next->next->next->next->nb)
                    ft_rotate_a(a);
                else 
                {
                    ft_rev_rot_a(a);
                    ft_swap_a(a);
                    ft_rotate_a(a);
                    ft_rotate_a(a);
                }
            }
        }
    }
}
