/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:47:47 by crigonza          #+#    #+#             */
/*   Updated: 2022/05/17 21:10:25 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/ft_printf.h"

void ft_printf_c(t_printf *tab)
{
	int c;

	c = va_arg(tab->arg, int);
	tab->lenght += write(1, &c, 1);
	if(tab->minus)
	{
		while(tab->width > 1)
		{
			tab->lenght += write(1, " ", 1);
			tab->width--;
		}
	}
}