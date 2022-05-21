/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:02:32 by crigonza          #+#    #+#             */
/*   Updated: 2022/05/20 17:50:15 by crigonza         ###   ########.fr       */
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
	{
		ft_putptr(ptr);
		tab->lenght += ft_ptrlen(ptr);
		if (tab->minus)
		{
			while((tab->width - ft_ptrlen(ptr)) - 2 > 0)
			{
				tab->lenght += write (1, " ", 1);
				tab->width--;
			}
		}
	}
}

void	ft_putptr(unsigned long ptr)
{
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
}

int	ft_ptrlen(unsigned long ptr)
{
	int len;

	len = 0;
	while (ptr!= 0)
	{
		ptr /= 16;
		len++;
	}
	return (len);
}