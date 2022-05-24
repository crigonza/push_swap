/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:52:33 by crigonza          #+#    #+#             */
/*   Updated: 2022/05/23 18:12:08 by crigonza         ###   ########.fr       */
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
	if (!hex && !tab->width && tab->precision)
		return;
	if (tab->point && !hex && !tab->width)
	{
		tab->lenght += ft_put_sp(tab->minfw);
		return;
	}
	if (!tab->minus)
	{
		if (tab->sharp)
		{
			if(i == 0)
				tab->lenght += write(1, "0x", 2);
			else
				tab->lenght += write(1, "0X", 2);
		}
		else if ((tab->precision || tab->zero) && !tab->minfw)
			tab->lenght += ft_put_zeros(tab->width - len);
		else if (tab->minfw && !tab->minus)
		{
			if (tab->width)
			{
				if(tab->width < len)
					tab->width = len;
				tab->lenght += ft_put_sp(tab->minfw - tab->width);
				tab->lenght += ft_put_zeros(tab->width - len);
			}
			else
				tab->lenght += ft_put_sp(tab->minfw - len);
		}
		ft_puthex(hex, i);
	}
	if (tab->minus)
	{
		if (tab->point) 
		{
			if (tab->width < len && hex)
				tab->width = len;
			tab->lenght += ft_put_zeros(tab->width - len);
			ft_puthex(hex, i);
			tab->lenght += ft_put_sp(tab->minfw - tab->width);
		}
		else
		{
			ft_puthex(hex, i);
			tab->lenght += ft_put_sp(tab->width - len);
		}
	}
	tab->lenght += len;
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
	if (!hex)
		return (1);
	while (hex != 0)
	{
		hex /= 16;
		len++;
	}
	return (len);
}