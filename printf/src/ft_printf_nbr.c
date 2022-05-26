/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:51:29 by crigonza          #+#    #+#             */
/*   Updated: 2022/05/26 14:28:11 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_printf_id(t_printf *tab)
{
	char		*str;
	long		nb;

	nb = va_arg(tab->arg, int);
	if (nb < 0 && ((tab->zero && !tab->point) || tab->precision))
		nb = ft_neg_num(tab, nb);
	else if (nb == 0 && !tab->width && tab->precision)
		return ;
	else if (nb == 0 && tab->point && !tab->width)
	{
		tab->lenght += ft_put_sp(tab->minfw);
		return ;
	}
	
	if (nb == 2147483648)
	{
		nb = 2147483647;
		str = ft_itoa(nb);
		str[9] = '8';
	}
	else
		str = ft_itoa(nb);
	if (nb >= 0 && tab->plus)
		tab->lenght += write(1, "+", 1);
	else if (nb >= 0 && tab->space)
		tab->lenght += write(1, " ", 1);
	ft_putnbrf (str, tab);
}

void	ft_putnbrf(char *str, t_printf *tab)
{
	if ((tab->zero || tab->precision) && !tab->point)
	{
		tab->lenght += ft_put_zeros(tab->width - ft_strlen(str));
		tab->lenght += write(1, str, ft_strlen(str));
	}
	else if (tab->minfw && !tab->width && !tab->minus)
	{
		tab->lenght += ft_put_sp(tab->minfw - ft_strlen(str));
		tab->lenght += write(1, str, ft_strlen(str));
	}
	else if (tab->point && tab->width && !tab->minus)
		ft_negative(tab, str);
	else if (tab->minus)
	{
		if (tab->point)
			ft_negative_(tab, str);
		else
		{
			tab->lenght += write(1, str, ft_strlen(str));
			tab->lenght += ft_put_sp(tab->width - ft_strlen(str));
		}
	}
	else
		tab->lenght += write(1, str, ft_strlen(str));
	free(str);
}

void	ft_negative(t_printf *tab, char *str)
{
	if (str[0] == '-')
	{
		if (tab->width < (int)ft_strlen(str))
			tab->width = ft_strlen(str);
		else
			tab->width ++;
		tab->lenght += ft_put_sp(tab->minfw - tab->width);
		tab->lenght += write(1, "-", 1);
		tab->lenght += ft_put_zeros(tab->width - ft_strlen(str));
		str = ft_substr(str, 1, ft_strlen(str) - 1);
		tab->lenght += write(1, str, ft_strlen(str));
	}
	else
	{
		if (tab->width < (int)ft_strlen(str))
			tab->width = ft_strlen(str);
		tab->lenght += ft_put_sp(tab->minfw - tab->width);
		tab->lenght += ft_put_zeros(tab->width - ft_strlen(str));
		tab->lenght += write(1, str, ft_strlen(str));
	}
}

void	ft_negative_(t_printf *tab, char *str)
{
	if (str[0] == '-')
	{
		if (tab->width < (int)ft_strlen(str))
			tab->width = ft_strlen(str) - 1;
		tab->lenght += write(1, "-", 1);
		tab->lenght += ft_put_zeros(tab->width - ft_strlen(str) + 1);
		str = ft_substr(str, 1, ft_strlen(str) - 1 );
		tab->lenght += write(1, str, ft_strlen(str));
		tab->lenght += ft_put_sp(tab->minfw - tab->width - 1);
	}
	else
	{
		if (tab->width < (int)ft_strlen(str))
			tab->width = ft_strlen(str);
		tab->lenght += ft_put_zeros(tab->width - ft_strlen(str));
		tab->lenght += write(1, str, ft_strlen(str));
		tab->lenght += ft_put_sp(tab->minfw - tab->width);
	}
}
