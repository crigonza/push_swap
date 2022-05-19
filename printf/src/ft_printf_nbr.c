/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:51:29 by crigonza          #+#    #+#             */
/*   Updated: 2022/05/19 19:18:08 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_printf_id(t_printf *tab)
{
	char *str;
	int nb;
	int i;

	i = 0;
	nb = va_arg(tab->arg, int);
	str = ft_itoa(nb);
	if (tab->zero && tab->width)
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
		tab->lenght += write(1, " ", tab->width - ft_strlen(str));
	}
	else
		tab->lenght += write(1, str, ft_strlen(str));
	free(str);
}