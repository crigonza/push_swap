/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:52:33 by crigonza          #+#    #+#             */
/*   Updated: 2022/05/19 19:29:16 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_printf_h(t_printf *tab)
{
	unsigned long	hex;
    int i;

    i = tab->upperx;
	hex = (unsigned long)va_arg(tab->arg, unsigned long);
	if (!hex)
		tab->lenght += write(1, "0", 1);
	else
		tab->lenght += ft_puthex(hex, i);
}

int	ft_puthex(unsigned long hex, int upper)
{
	int len;
	unsigned long n;

	len = 0;
	n = hex;
	if (hex >= 16)
	{
		ft_putptr(hex / 16);
		ft_putptr(hex % 16);
	}
	else
	{
		if (hex <= 9)
			ft_putchar_fd((hex + '0'), 1);
		else
		{
			if (upper == 0)
				ft_putchar_fd((hex - 10 + 'a'), 1);
			else if (upper == 1)
				ft_putchar_fd((hex - 10 + 'A'), 1);
		}
	}
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}