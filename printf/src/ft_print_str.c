/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:49:51 by crigonza          #+#    #+#             */
/*   Updated: 2022/05/21 13:55:12 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_printf_s(t_printf *tab)
{
	char *str;
	int	i;

	str = va_arg(tab->arg, char *);
	if (!str)
		str = "(null)";
	if (tab->minfw && !tab->point)
	{
		i = tab->minfw - ft_strlen(str);
		tab->lenght += ft_put_sp(i);
		tab->lenght += write(1, str, ft_strlen(str));
	}
	else if (tab->precision)
		if (tab->width < (int)ft_strlen(str))
			tab->lenght += write(1, str, tab->width);
		else
			tab->lenght += write(1, str, ft_strlen(str));
	else if (tab->point && tab->width)
	{
		if (tab->width > (int)ft_strlen(str))
			tab->width = ft_strlen(str);
		if (tab->minfw && !tab->minus)
			tab->lenght += ft_put_sp(tab->minfw - tab->width);
		tab->lenght += write(1, str, tab->width);
		if (tab->minus)
			tab->lenght += ft_put_sp(tab->minfw - tab->width);
	}
	else if (tab->minfw && !tab->width)
			tab->lenght += ft_put_sp(tab->minfw);
	else
		tab->lenght += write(1, str, ft_strlen(str));
	if (tab->minus)
	{
		i = tab->width - ft_strlen(str);
		tab->lenght += ft_put_sp(i);
	}
}
int ft_put_sp(int width)
{
	int len;

	len = 0;
	while (width > 0)
	{
		write(1, " ", 1);
		width--;
		len ++;
	}
	return (len);
}