/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 21:31:42 by crigonza          #+#    #+#             */
/*   Updated: 2022/07/05 14:49:11 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_sort_large_stack(t_stack **a, t_stack **b, int size)
{
	if (size == 100)
		ft_chunk_hundred(a, b, size);
	if (size == 500)
		ft_chunk_five_hundred(a, b, size);
}

void	ft_chunk_hundred(t_stack **a, t_stack **b, int size)
{
	int	total;

	total = size - 1;
	while (size > 0)
	{
		if (size > 80)
			ft_select_nb(a, b, 79);
		else if (size > 60 && size < 81)
			ft_select_nb(a, b, 59);
		else if (size > 40 && size < 61)
			ft_select_nb(a, b, 39);
		else if (size > 20 && size < 41)
			ft_select_nb(a, b, 19);
		else
			ft_select_nb(a, b, 0);
		size--;
	}
	ft_push_to_a(a, b, total);
}

/* void    ft_chunk_five_hundred(t_stack **a, t_stack **b)
{
    int count;
	int	total;

    count = 500;
    while (count > 0)
    {
        if (count > 455)
            ft_select_nb(a, b, 454);
        else if (count > 410 && count < 456)
            ft_select_nb(a, b, 409);
        else if (count > 365 && count < 411)
            ft_select_nb(a, b, 364);
        else if (count > 320 && count < 366)
            ft_select_nb(a, b, 319);
        else if (count > 275 && count < 321)
            ft_select_nb(a, b, 274);
        else if (count > 230 && count < 276)
            ft_select_nb(a, b, 229);
        else if (count > 185 && count < 231)
            ft_select_nb(a, b, 184);
        else if (count > 140 && count < 186)
            ft_select_nb(a, b, 139);
        else if (count > 95 && count < 141)
            ft_select_nb(a, b, 94);
        else if (count > 40 && count < 96)
            ft_select_nb(a, b, 39);
        else
            ft_select_nb(a, b, 0);
        count --;
    }
    count = 499;
    while (count >= 0)
    {
        ft_sort_to_a(a, b ,count);
        count --;
    }
} */
void	ft_chunk_five_hundred(t_stack **a, t_stack **b, int size)
{
    int total;
    
	total = size - 1;
	while (size > 0)
	{
		if (size > 460)
			ft_select_nb(a, b, 459);
		else if (size > 420 && size < 461)
			ft_select_nb(a, b, 419);
		else if (size > 380 && size < 421)
			ft_select_nb(a, b, 379);
		else if (size > 340 && size < 381)
			ft_select_nb(a, b, 339);
		else if (size > 300 && size < 341)
			ft_select_nb(a, b, 299);
		else if (size > 260 && size < 301)
			ft_select_nb(a, b, 259);
		else if (size > 220 && size < 261)
			ft_select_nb(a, b, 219);
		else if (size > 180 && size < 221)
			ft_select_nb(a, b, 179);
		else if (size > 140 && size < 181)
			ft_select_nb(a, b, 139);
		else if (size > 100 && size < 141)
			ft_select_nb(a, b, 99);
		else if (size > 60 && size < 101)
			ft_select_nb(a, b, 59);
		else if (size > 20 && size < 61)
			ft_select_nb(a, b, 19);
		else
			ft_select_nb(a, b, 0);
		size--;
	}
	ft_push_to_a(a, b, total);
}

void	ft_push_to_a(t_stack **a, t_stack **b, int size)
{
	while (size >= 0)
	{
		ft_sort_to_a(a, b, size);
		size--;
	}
}

void	ft_select_nb(t_stack **a, t_stack **b, int max)
{
	int		top;
	int		botton;
	t_stack	*temp;

	temp = *a;
	top = ft_search_top(a, max);
	botton = ft_search_botton(a, max);
	(*a) = temp;
	if (top < botton)
	{
		while (top > 0)
		{
			ft_rotate(a, 'a');
			top--;
		}
	}
	else
	{
		while (botton > 0)
		{
			ft_rev_rot(a, 'a');
			botton--;
		}
	}
	/* if ((*b) != NULL)
        ft_order_b(b, (*a)->nb); */
	ft_push_b(a, b);
}

void	ft_order_b(t_stack **b, int num)
{
	int		next;
	int		top;
	int		botton;
	t_stack	*tmp;

	tmp = *b;
	top = 0;
	botton = 0;
	next = ft_find_next(b, num);
	if (!next)
		next = ft_find_min(b);
	top = ft_search_top_(b, next);
	botton = ft_search_botton_(b, next);
	(*b) = tmp;
	if (top < botton)
	{
		while (top > 0)
		{
			ft_rotate(b, 'b');
			top--;
		}
	}
	else
	{
		while (botton > 0)
		{
			ft_rev_rot(b, 'b');
			botton--;
		}
	}
}

int	ft_find_min(t_stack **b)
{
	int		min;
	t_stack	*tmp;

	tmp = *b;
	min = tmp->nb;
	while (tmp->next)
	{
		if (min > tmp->nb)
			min = tmp->nb;
		tmp = tmp->next;
	}
	if (min > tmp->nb)
		min = tmp->nb;
	return (min);
}

int	ft_find_next(t_stack **b, int num)
{
	int		i;
	t_stack	*tmp;

	tmp = *b;
	i = 0;
	if (tmp->next)
	{
		while (i < 10)
		{
			tmp = *b;
			if (tmp->nb == num + i)
				return (num + i);
			while (tmp->next)
			{
				tmp = tmp->next;
				if (tmp->nb == num + i)
					return (num + i);
			}
			i++;
		}
	}
	return (0);
}

void	ft_sort_to_a(t_stack **a, t_stack **b, int number)
{
	int		top;
	int		botton;
	t_stack	*tmp;

	tmp = *b;
	top = ft_search_top_(b, number);
	botton = ft_search_botton_(b, number);
	(*b) = tmp;
	if (top < botton)
	{
		while (top > 0)
		{
			ft_rotate(b, 'b');
			top--;
		}
	}
	else
	{
		while (botton > 0)
		{
			ft_rev_rot(b, 'b');
			botton--;
		}
	}
	ft_push_a(a, b);
}

int	ft_search_top(t_stack **a, int max)
{
	int	i;

	i = 0;
	while ((*a)->nb < max)
	{
		(*a) = (*a)->next;
		i++;
	}
	return (i);
}

int	ft_search_botton(t_stack **a, int max)
{
	int	i;

	i = 1;
	while ((*a)->next != 0)
		(*a) = (*a)->next;
	while ((*a)->nb < max)
	{
		(*a) = (*a)->prev;
		i++;
	}
	return (i);
}

int	ft_search_top_(t_stack **b, int number)
{
	int	i;

	i = 0;
	while ((*b)->nb != number)
	{
		(*b) = (*b)->next;
		i++;
	}
	return (i);
}

int	ft_search_botton_(t_stack **b, int number)
{
	int	i;

	i = 1;
	while ((*b)->next != 0)
		(*b) = (*b)->next;
	while ((*b)->nb != number)
	{
		(*b) = (*b)->prev;
		i++;
	}
	return (i);
}
