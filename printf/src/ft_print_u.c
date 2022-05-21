/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 21:48:32 by crigonza          #+#    #+#             */
/*   Updated: 2022/05/21 10:25:59 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void    ft_print_u(t_printf *tab)
{
    unsigned int    num;
    char            *strnum;

    num = va_arg(tab->arg, unsigned int);
    if (num == 0)
    {
        tab->lenght += write(1, "0", 1);
        return;
    }
    strnum = ft_uitoa(num);
    ft_putnbrf(strnum, tab);
}

char    *ft_uitoa(unsigned int num)
{
    unsigned int n;
    int i;
    char    *strnum;

    i = 0;
    n = num;
    while(n != 0)
    {
        n /= 10;
        i ++;
    }
    strnum = (char *)malloc(sizeof(char) * i + 1);
    if (!strnum)
        return(0);
    strnum[i--]= '\0';
    while (num != 0)
    {
        strnum[i] = num % 10 + '0';
        num /= 10;
        i --;
    }
    return (strnum);
}