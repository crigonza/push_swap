/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:35:16 by crigonza          #+#    #+#             */
/*   Updated: 2022/06/09 23:58:18 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int    main(int argc, char **argv)
{
    t_stack *stka;
    //t_stack *stkb;


    //stkb = NULL;
    stka = ft_stack(argc, argv);
    while(stka->next != NULL)
    {
        printf ("%d", stka->nb);
        stka = stka->next;
    }
}

t_stack   *ft_stack(int argc, char **argv)
{
    t_stack *tmp;
    int i;
    int size;

    i = 0;
    tmp = NULL;
    while(i++ < argc)
    {
        if ((size = ft_check_digits(argv[i])) == 0)
            return(NULL);
        else
            while (tmp->next != NULL)
                tmp = tmp->next;
            tmp->next = ft_new_node(ft_atoi(argv[i]));
    }
    return (tmp);
}

int   ft_check_digits(char *number)
{
    int i;

    i = 0;
    if (number[i] == '-' || number[i] ==  '+')
        i++;
    while (number[i])
    {
        if (!ft_isdigit(number[i]))
            return (0);
        else
            i++;
    }
    return (i);
}

t_stack *ft_new_node(int num)
{
    t_stack *node;

    node = (t_stack *)malloc(sizeof(t_list));
    if (!node)
        return (NULL);
    node->nb = num;
    node->next = NULL;
    return (node); 
}

/*****************************************************************************/

int	ft_atoi(const char *nptr)
{
	int			i;
	long int	n;
	long int	result;

	i = 0;
	result = 0;
	n = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			n *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result *= 10;
		result += nptr[i] - 48;
		i++;
	}
	return (result * n);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
