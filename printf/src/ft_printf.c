/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:41:53 by crigonza          #+#    #+#             */
/*   Updated: 2022/05/14 11:14:02 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_printf(char const *str, ...)
{
	va_list	arg;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(arg, s);
	while (str[i])
	{
		if (str[i] == '%')
		{
			while (!ft_strchr(SPECIFIERS, str[i]))
            {
			    ft_check_format(str[i]);
			    count++;
                i++;
            }
            ft_check_spec(str[i]);   
		}
		count += ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(arg);
    return count;
}

int	ft_check_spec(char *str)
{
}

int	ft_check_format(char *str)
{
}