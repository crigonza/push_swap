/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:49:51 by crigonza          #+#    #+#             */
/*   Updated: 2022/05/21 08:14:23 by crigonza         ###   ########.fr       */
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
	if (tab->minfw)
	{
		// if (tab->space)
		// tab->lenght += write(1, " ", 1); 
		i = tab->width - ft_strlen(str);
		tab->lenght += ft_put_sp(i);
	}
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