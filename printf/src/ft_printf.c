/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:41:53 by crigonza          #+#    #+#             */
/*   Updated: 2022/05/24 21:15:26 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_printf(char const *str, ...)
{
	va_list		arg;
	t_printf	*tab;
	int			len;

	va_start(arg, str);
	tab = ft_initialize(str, arg);
	while (tab->format[tab->i])
	{
		if (tab->format[tab->i] == '%')
		{
			ft_check_format(tab);
			ft_reset(tab);
		}
		else
			tab->lenght += write(1, &tab->format[tab->i], 1);
		tab->i++;
	}
	va_end(arg);
	len = tab->lenght;
	free(tab);
	return (len);
}

void	ft_check_format(t_printf *tab)
{
	tab->i++;
	while (!ft_strchr(SPECIFIERS, tab->format[tab->i]))
	{
		if (tab->format[tab->i] == '.')
			ft_point(tab);
		else if (tab->format[tab->i] == '+')
			tab->plus = 1;
		else if (tab->format[tab->i] == '#')
			tab->sharp = 1;
		else if (tab->format[tab->i] == ' ')
			tab->space = 1;
		else if (tab->format[tab->i] == '-' || tab->format[tab->i] == '0')
			ft_minus_zero(tab);
		else if (ft_isdigit(tab->format[tab->i]))
		{
			ft_width(tab);
			tab->minfw = tab->width;
			tab->width = 0;
		}
		tab->i++;
	}
	ft_check_conv(tab);
}

void	ft_check_conv(t_printf *tab)
{
	if (tab->format[tab->i] == '%')
	{
		tab->percent = 1;
		ft_printf_c(tab);
	}
	else if (tab->format[tab->i] == 'c')
		ft_printf_c(tab);
	else if (tab->format[tab->i] == 's')
		ft_print_s(tab);
	else if (tab->format[tab->i] == 'p')
		ft_printf_p(tab);
	else if (tab->format[tab->i] == 'd' || tab->format[tab->i] == 'i')
		ft_printf_id(tab);
	else if (tab->format[tab->i] == 'x')
		ft_printf_h(tab);
	else if (tab->format[tab->i] == 'X')
	{
		tab->upperx = 1;
		ft_printf_h(tab);
	}
	else if (tab->format[tab->i] == 'u')
		ft_print_u(tab);
}

void	ft_point(t_printf *tab)
{
	if (tab->format[tab->i - 1] == '%')
	{
		tab->precision = 1;
		if (ft_isdigit(tab->format[tab->i + 1]))
			ft_width(tab);
	}
	else
	{
		tab->point = 1;
		if (tab->minus || tab->zero)
		{
			tab->minfw = tab->width;
			tab->width = 0;
		}
		if (ft_isdigit(tab->format[tab->i + 1]))
			ft_width(tab);
	}
}

void	ft_minus_zero(t_printf *tab)
{
	if (tab->format[tab->i] == '-')
	{
		tab->minus = 1;
		if (ft_isdigit(tab->format[tab->i + 1]))
			ft_width(tab);
	}
	else if (tab->format[tab->i] == '0')
	{
		tab->zero = 1;
		if (ft_isdigit(tab->format[tab->i + 1]))
			ft_width(tab);
	}
}
