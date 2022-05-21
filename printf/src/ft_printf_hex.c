/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:52:33 by crigonza          #+#    #+#             */
/*   Updated: 2022/05/20 21:46:01 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_printf_h(t_printf *tab)
{
	unsigned int	hex;
    int i;
	int	len;

    i = tab->upperx;
	hex = (unsigned int)va_arg(tab->arg, unsigned int);
	len = ft_hexlen(hex);
	if (!hex)
		tab->lenght += write(1, "0", 1);
	else
	{
		if (tab->sharp)
		{
			if(i == 0)
				tab->lenght += write(1, "0x", 2);
			else
				tab->lenght += write(1, "0X", 2);
		}
		else if (tab->precision || tab->zero)
		{
			while(tab->width - len > 0)
			{
				tab->lenght += write(1, "0", 1);
				tab->width --;
			}
		}
		ft_puthex(hex, i);
		if (tab->minus)
		{
			while(tab->width - len > 0)
			{
				tab->lenght += write(1, " ", 1);
				tab->width --;
			}

		}
		tab->lenght += len;
	}
}

void	ft_puthex(unsigned int hex, int upper)
{
	if (hex >= 16)
	{
		ft_puthex(hex / 16, upper);
		ft_puthex(hex % 16, upper);
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
}

int ft_hexlen(unsigned int hex)
{
	int len;

	len = 0;
	while (hex != 0)
	{
		hex /= 16;
		len++;
	}
	return (len);
}