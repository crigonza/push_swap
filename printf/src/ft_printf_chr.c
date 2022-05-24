/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:47:47 by crigonza          #+#    #+#             */
/*   Updated: 2022/05/23 21:20:09 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

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
