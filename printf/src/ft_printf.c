/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:41:53 by crigonza          #+#    #+#             */
/*   Updated: 2022/05/17 19:30:56 by crigonza         ###   ########.fr       */
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
		{
			ft_check_format(tab);
			ft_reset(tab);
		}
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
void	ft_reset(t_printf *tab)
{
	tab->width = 0;
	tab->minus = 0;
}

void	ft_check_format(t_printf *tab)
{
	tab->i++;
	//tab->lenght++;
	while (!ft_strchr(SPECIFIERS, tab->format[tab->i]))
	{
		if (tab->format[tab->i] == '.')
			tab->point = 1;
		else if (tab->format[tab->i] == '0')
			tab->zero = 1;
		else if (tab->format[tab->i] == '-')
		{
			tab->minus = 1;
			if (ft_isdigit(tab->format[tab->i+1]))
			{
				tab->i++;
				tab->width += ft_atoi(&tab->format[tab->i]);
				while(ft_isdigit(tab->format[tab->i]))
					tab->i++;
				tab->i--;
			}
		}
		else if (tab->format[tab->i] == '+')
			tab->plus = 1;
		else if (tab->format[tab->i] == '#')
			tab->sharp = 1;
		else if (tab->format[tab->i] == ' ')
			tab->space = 1;
		tab->i ++;
		//tab->lenght ++;
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
	/*if (tab->format[tab->i] == 'p')
		ft_printf_p(tab);*/
	if (tab->format[tab->i] == 'd' || tab->format[tab->i] == 'i')
		ft_printf_id(tab);
}

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

/*void ft_printf_p(t_printf *tab)
{

}*/

void	ft_printf_id(t_printf *tab)
{
	char *str;
	int	nb;

	nb = va_arg(tab->arg, int);
	str = ft_itoa(nb);
	if (tab->minus && tab->width)
	{
		tab->lenght += write(1, str, ft_strlen(str));
		tab->lenght += write(1, " ", tab->width-ft_strlen(str));
	}
	else
		tab->lenght += write(1, str, ft_strlen(str));
	free(str);
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

int	ft_atoi(const char *nptr)
{
	int			i;
	long int	n;
	long int	result;

	i = 0;
	result = 0;
	n = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			n *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result *= 10;
		result += nptr[i] - 48;
		i++;
	}
	return (result * n);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int main(void)
{
	int x;
	int y;

	x = ft_printf("%d", 1975);
	y = printf("%-10s", "Hola1");
	printf("%d----%d", x, y);
	return (0);
}*/
