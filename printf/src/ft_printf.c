/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:41:53 by crigonza          #+#    #+#             */
/*   Updated: 2022/05/19 19:17:59 by crigonza         ###   ########.fr       */
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
	//tab->lenght++;
	while (!ft_strchr(SPECIFIERS, tab->format[tab->i]))
	{
		if (tab->format[tab->i] == '.')
			tab->point = 1;
		else if (tab->format[tab->i] == '-')
		{
			tab->minus = 1;
			if (ft_isdigit(tab->format[tab->i + 1]))
			{
				tab->i++;
				tab->width += ft_atoi(&tab->format[tab->i]);
				while (ft_isdigit(tab->format[tab->i]))
					tab->i++;
				tab->i--;
			}
		}
		else if (tab->format[tab->i] == '0')
		{
			tab->zero = 1;
			if (ft_isdigit(tab->format[tab->i + 1]))
			{
				tab->i++;
				tab->width += ft_atoi(&tab->format[tab->i]);
				while (ft_isdigit(tab->format[tab->i]))
					tab->i++;
				tab->i--;
			}
		}
		else if (tab->format[tab->i] == '+')
			tab->plus = 1;
		else if (tab->format[tab->i] == '#')
			tab->sharp = 1;
		else if (tab->format[tab->i] == ' ')
			tab->space = 1;
		tab->i++;
		//tab->lenght ++;
	}
	ft_check_conv(tab);
}

void	ft_check_conv(t_printf *tab)
{
	if (tab->format[tab->i] == '%')
		tab->lenght += write(1, "%", 1);
	if (tab->format[tab->i] == 'c')
		ft_printf_c(tab);
	if (tab->format[tab->i] == 's')
		ft_printf_s(tab);
	if (tab->format[tab->i] == 'p')
		ft_printf_p(tab);
	if (tab->format[tab->i] == 'd' || tab->format[tab->i] == 'i')
		ft_printf_id(tab);
	if (tab->format[tab->i] == 'x')
		ft_printf_h(tab);
	if (tab->format[tab->i] == 'X')
	{
		tab->upperx = 1;
		ft_printf_h(tab);
	}
}
