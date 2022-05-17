/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:41:53 by crigonza          #+#    #+#             */
/*   Updated: 2022/05/17 13:45:41 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_printf(char const *str, ...)
{
	va_list		arg;
	t_printf	*tab;
	int			len;

	va_start(arg, str);
	tab = ft_initialize(str, arg);
	while (tab->format[tab->i])
	{
		if (tab->format[tab->i] == '%')
			ft_check_format(tab);
		else
			tab->lenght += write(1, &tab->format[tab->i], 1);
		tab->i ++;
	}
	va_end(arg);
	len = tab->lenght;
	free (tab);
	return (len);
}

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

void	ft_check_format(t_printf *tab)
{
	tab->i++;
	while (!ft_strchr(SPECIFIERS, tab->format[tab->i]))
	{
		if (tab->format[tab->i] == '.')
			tab->point = 1;
		else if (tab->format[tab->i] == '0')
			tab->zero = 1;
		else if (tab->format[tab->i] == '-')
		{
			tab->minus = 1;
		}
		else if (tab->format[tab->i] == '+')
			tab->plus = 1;
		else if (tab->format[tab->i] == '#')
			tab->sharp = 1;
		else if (tab->format[tab->i] == ' ')
			tab->space = 1;
		tab->i ++;
		tab->lenght ++;
	}
	ft_check_conv(tab);
}

void	ft_check_conv(t_printf *tab)
{
	if (tab->format[tab->i] == '%')
		tab->lenght += write(1, "%", 1);
	if (tab->format[tab->i] == 'c')
		ft_printf_c(tab);
	if (tab->format[tab->i] == 's')
		ft_printf_s(tab);
	if (tab->format[tab->i] == 'd')
		ft_printf_d(tab);
}

void ft_printf_c(t_printf *tab)
{
	int c;

	c = va_arg(tab->arg, int);
	tab->lenght += write(1, &c, 1);
}

void	ft_printf_s(t_printf *tab)
{
	char *str;

	str = va_arg(tab->arg, char *);
	while(*str)
	{
		tab->lenght += write(1, str, 1);
		str ++;
	}
}

void	ft_printf_d(t_printf *tab)
{
	char *str;
	long	nb;

	nb = va_arg(tab->arg, int);
	str = ft_itoa(nb);
	while(*str)
	{
		tab->lenght += write(1, str, 1);
		str ++;
	}
}

/*char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

int main(void)
{
	ft_printf("%c\n%c\n", '0', 'a');
	ft_printf("%s\n", "hola mundo");
	ft_printf("%-c, '0');
	return (0);
}*/
