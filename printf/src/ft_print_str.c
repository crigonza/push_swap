/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:49:51 by crigonza          #+#    #+#             */
/*   Updated: 2022/05/17 20:50:23 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/ft_printf.h"

void	ft_printf_s(t_printf *tab)
{
	char *str;

	str = va_arg(tab->arg, char *);
	
	if(tab->minus && tab->width)
	{	
		tab->lenght += tab->width;
		while (*str)
		{
			write(1, str, 1);
			str ++;
			tab->width--;
		}
		while(tab->width > 0)
		{
			write(1, " ", 1);
			tab->width--;
		}
	}
	else
	{
		while(*str)
		{
			tab->lenght += write(1, str, 1);
			str ++;
		}
	}
}