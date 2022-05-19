/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:02:32 by crigonza          #+#    #+#             */
/*   Updated: 2022/05/17 22:03:34 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/ft_printf.h"

void ft_printf_p(t_printf *tab)
{
	unsigned long	ptr;

	ptr = (unsigned long) va_arg(tab->arg, unsigned long);
	tab->lenght += write(1, "0x", 2);
	if (!ptr)
		tab->lenght += write(1, "0", 1);
	else
		tab->lenght += ft_putptr(ptr);
	
}

int	ft_putptr(unsigned long ptr)
{
	int	len;
	unsigned long	n;

	len = 0;
	n = ptr;
	if (ptr >= 16)
	{
		ft_putptr(ptr / 16);
		ft_putptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd((ptr +'0'), 1);
		else
			ft_putchar_fd((ptr -10 + 'a'), 1);
	}
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}