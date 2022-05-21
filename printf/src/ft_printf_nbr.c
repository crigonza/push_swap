/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:51:29 by crigonza          #+#    #+#             */
/*   Updated: 2022/05/20 21:17:35 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_printf_id(t_printf *tab)
{
	char *str;
	int nb;

	nb = va_arg(tab->arg, int);
	if (nb < 0 && (tab->zero || tab->precision))
		{
			nb = -nb;
			tab->lenght += write(1, "-", 1);
			if (tab->zero)
				tab->width--;
		}
	str = ft_itoa(nb);
	if (nb >= 0 && tab->plus)
		tab->lenght += write(1, "+", 1);
	else if (nb >= 0 && tab->space)
		tab->lenght += write(1, " ", 1);
	ft_putnbrf (str , tab);

}

void	ft_putnbrf(char *str, t_printf *tab)
{
	int i;


	if (tab->zero || tab->precision)
	{
		i = tab->width - ft_strlen(str);
		while (i > 0)
		{
			tab->lenght += write(1, "0", 1);
			i--;
		}
		tab->lenght += write(1, str, ft_strlen(str));
	}
	else if (tab->minus && tab->width)
	{
		tab->lenght += write(1, str, ft_strlen(str));
		i = tab->width - ft_strlen(str);
		while(i > 0)
		{
			tab->lenght += write(1, " ", 1);
			i --;
		}
	}
	else
		tab->lenght += write(1, str, ft_strlen(str));
	free(str);
}