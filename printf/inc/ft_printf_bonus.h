/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:44:36 by crigonza          #+#    #+#             */
/*   Updated: 2022/05/26 19:06:54 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "../Libft/libft.h"
# include <stdarg.h>
# include <limits.h>

typedef struct s_printf
{
	char const	*format;
	va_list		arg;
	int			lenght;
	int			minus;
	int			zero;
	int			precision;
	int			point;
	int			width;
	int			sharp;
	int			space;
	int			plus;
	int			minfw;
	int			percent;
	int			upperx;
	int			i;
}				t_printf;

t_printf		*ft_initialize(char const *str, va_list arg);
int				ft_printf(char const *str, ...);
void			ft_check_format(t_printf *tab);
void			ft_check_conv(t_printf *tab);
void			ft_minus_zero(t_printf *tab);
void			ft_point(t_printf *tab);
void			ft_width(t_printf *tab);
void			ft_reset(t_printf *tab);
void			ft_printf_c(t_printf *tab);
void			ft_print_s(t_printf *tab);
void			ft_print_str(t_printf *tab, char *str);
void			ft_point_width(t_printf *tab, char *str);
int				ft_put_sp(int width);
void			ft_printf_id(t_printf *tab);
void			ft_putnbrf(char *str, t_printf *tab);
void			ft_negative(t_printf *tab, char *str);
void			ft_negative_(t_printf *tab, char *str);
long			ft_printf_id_(t_printf *tab);
int				ft_put_zeros(int len);
void			ft_printf_p(t_printf *tab);
void			ft_putptr(unsigned long ptr);
int				ft_ptrlen(unsigned long ptr);
void			ft_printf_h(t_printf *tab);
void			ft_print_hex(t_printf *tab, unsigned int hex, int i);
void			ft_print_hex_(t_printf *tab, unsigned int hex, int i);
void			ft_puthex(unsigned int hex, int upper);
int				ft_hexlen(unsigned int hex);
void			ft_print_u(t_printf *tab);
char			*ft_uitoa(unsigned int num);

# define SPECIFIERS "cspdiuxX%"

#endif