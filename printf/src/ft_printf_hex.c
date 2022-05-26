/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:52:33 by crigonza          #+#    #+#             */
/*   Updated: 2022/05/25 20:13:59 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_printf_h(t_printf *tab)
{
	unsigned int	hex;
	int				i;

	i = tab->upperx;
	hex = (unsigned int)va_arg(tab->arg, unsigned int);
	if (!hex && !tab->width && tab->precision)
		return ;
	if (tab->point && !hex && !tab->width)
	{
		tab->lenght += ft_put_sp(tab->minfw);
		return ;
	}
	if (tab->sharp && hex)
	{
		if (i == 0)
			tab->lenght += write(1, "0x", 2);
		else
			tab->lenght += write(1, "0X", 2);
	}
	ft_print_hex(tab, hex, i);
}

void	ft_print_hex(t_printf *tab, unsigned int hex, int i)
{
	if (!tab->minus)
	{
		if ((tab->precision || tab->zero) && !tab->minfw)
			tab->lenght += ft_put_zeros(tab->width - ft_hexlen(hex));
		else if (tab->minfw && !tab->minus)
		{
			if (tab->width)
			{
				if (tab->width < ft_hexlen(hex))
					tab->width = ft_hexlen(hex);
				tab->lenght += ft_put_sp(tab->minfw - tab->width);
				tab->lenght += ft_put_zeros(tab->width - ft_hexlen(hex));
			}
			else
				tab->lenght += ft_put_sp(tab->minfw - ft_hexlen(hex));
		}
		ft_puthex(hex, i);
	}
	ft_print_hex_(tab, hex, i);
}

void	ft_print_hex_(t_printf *tab, unsigned int hex, int i)
{
	if (tab->minus)
	{
		if (tab->point)
		{
			if (tab->width < ft_hexlen(hex) && hex)
				tab->width = ft_hexlen(hex);
			tab->lenght += ft_put_zeros(tab->width - ft_hexlen(hex));
			ft_puthex(hex, i);
			tab->lenght += ft_put_sp(tab->minfw - tab->width);
		}
		else
		{
			ft_puthex(hex, i);
			tab->lenght += ft_put_sp(tab->width - ft_hexlen(hex));
		}
	}
	tab->lenght += ft_hexlen(hex);
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

int	ft_hexlen(unsigned int hex)
{
	int	len;

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
