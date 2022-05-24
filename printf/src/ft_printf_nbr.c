/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:51:29 by crigonza          #+#    #+#             */
/*   Updated: 2022/05/23 21:17:36 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_printf_id(t_printf *tab)
{
	char *str;
	int nb;

	nb = va_arg(tab->arg, int);
	if (nb < 0 && ((tab->zero && !tab->point) || tab->precision))
		{
			nb = -nb;
			tab->lenght += write(1, "-", 1);
			if (tab->zero)
				tab->width--;
		}
	else if (nb == 0 && !tab->width && tab->precision)
		return;
	else if (nb == 0 && tab->point && !tab->width)
	{
		tab->lenght += ft_put_sp(tab->minfw);
		return;	
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

	if ((tab->zero || tab->precision) && !tab->point)
	{
		i = tab->width - ft_strlen(str);
		while (i > 0)
		{
			tab->lenght += write(1, "0", 1);
			i--;
		}
		tab->lenght += write(1, str, ft_strlen(str));
	}
	else if (tab->minfw && !tab->width && !tab->minus)
	{
		tab->lenght += ft_put_sp(tab->minfw - ft_strlen(str));
		tab->lenght += write(1, str, ft_strlen(str));
	}
	else if (tab->point && tab->width && !tab->minus)
	{
		if (str[0] == '-')
		{
			if (tab->width < (int)ft_strlen(str))
			{
				tab->width = ft_strlen(str);
				tab->lenght += ft_put_sp(tab->minfw - tab->width);
				tab->lenght += write(1, "-", 1);
				tab->lenght += ft_put_zeros(tab->width - ft_strlen(str));
			}
			else
			{
				tab->lenght += ft_put_sp(tab->minfw - tab->width - 1);
				tab->lenght += write(1, "-", 1);
				tab->lenght += ft_put_zeros(tab->width - ft_strlen(str) + 1);
			}
			str = ft_substr(str, 1, ft_strlen(str) - 1);
			tab->lenght += write(1, str, ft_strlen(str));
		}
		else
		{
			if (tab->width < (int)ft_strlen(str))
				tab->width = ft_strlen(str);
			if (str[0] == '-')
			{
				tab->lenght += ft_put_sp(tab->minfw - tab->width - 1);
				tab->lenght += ft_put_zeros(tab->width - ft_strlen(str) + 1);
			}
			else
			{
				tab->lenght += ft_put_sp(tab->minfw - tab->width);
				tab->lenght += ft_put_zeros(tab->width - ft_strlen(str));
			}
			tab->lenght += write(1, str, ft_strlen(str));
		}
	}
	else if (tab->minus)
	{
		if(tab->point)
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

int	ft_put_zeros(int len)
{
	int i;

	i = 0;
	while(len > 0)
	{
		write(1, "0", 1);
		len --;
		i ++;
	}
	return (i);
}