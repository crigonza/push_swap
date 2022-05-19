/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ini_reset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:53:03 by crigonza          #+#    #+#             */
/*   Updated: 2022/05/17 20:54:39 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

t_printf	*ft_initialize(char const *str, va_list arg)
{
	t_printf	*newlst;

	newlst = malloc (sizeof(t_printf));
	if (!newlst)
		return (NULL);
	newlst->format = str;
	va_copy(newlst->arg, arg);
	newlst->lenght = 0;
	newlst->minus = 0;
	newlst->zero = 0;
	newlst->precission = 0;
	newlst->point = 0;
	newlst->width = 0;
	newlst->sharp = 0;
	newlst->space = 0;
	newlst->plus = 0;
	newlst->i = 0;
	return (newlst);
}

void	ft_reset(t_printf *tab)
{
	tab->width = 0;
	tab->minus = 0;
}