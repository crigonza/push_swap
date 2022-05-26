/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:49:51 by crigonza          #+#    #+#             */
/*   Updated: 2022/05/26 18:15:10 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf_bonus.h"

void	ft_print_s(t_printf *tab)
{
	char	*str;

	str = va_arg(tab->arg, char *);
	if (!str)
		str = "(null)";
	if (!tab->width && !tab->minfw && tab->point)
		return ;
	ft_print_str(tab, str);
}

void	ft_print_str(t_printf *tab, char *str)
{
	if (tab->minfw && !tab->point)
	{
		tab->lenght += ft_put_sp(tab->minfw - ft_strlen(str));
		tab->lenght += write(1, str, ft_strlen(str));
	}
	else if (tab->precision)
	{
		if (tab->width < (int)ft_strlen(str))
			tab->lenght += write(1, str, tab->width);
		else
			tab->lenght += write(1, str, ft_strlen(str));
	}
	else if (tab->point && tab->width)
		ft_point_width(tab, str);
	else if (tab->minfw && !tab->width)
		tab->lenght += ft_put_sp(tab->minfw);
	else
		tab->lenght += write(1, str, ft_strlen(str));
	if (tab->minus)
		tab->lenght += ft_put_sp(tab->width - ft_strlen(str));
}

void	ft_point_width(t_printf *tab, char *str)
{
	if (tab->width > (int)ft_strlen(str))
		tab->width = ft_strlen(str);
	if (tab->minfw && !tab->minus)
		tab->lenght += ft_put_sp(tab->minfw - tab->width);
	tab->lenght += write(1, str, tab->width);
	if (tab->minus)
		tab->lenght += ft_put_sp(tab->minfw - tab->width);
}

void	ft_printf_c(t_printf *tab)
{
	int	c;

	if (tab->percent)
		c = '%';
	else
		c = va_arg(tab->arg, int);
	if (tab->minfw)
		tab->lenght += ft_put_sp(tab->minfw - 1);
	tab->lenght += write(1, &c, 1);
	if (tab->minus)
		tab->lenght += ft_put_sp(tab->width - 1);
}
