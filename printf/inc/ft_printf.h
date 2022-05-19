/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:44:36 by crigonza          #+#    #+#             */
/*   Updated: 2022/05/17 21:46:47 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../Libft/libft.h"
# include <stdarg.h>

typedef struct  s_printf
{
    char const    *format;
    va_list         arg;
    int         lenght;
    int     minus;
    int     zero;
    int     precission;
    int     point;
    int     width;
    int     sharp;
    int     space;
    int     plus;
    int     i;
}           t_printf;

t_printf	*ft_initialize(char  const *str, va_list arg);
int     ft_printf(char const *str, ...);
void     ft_check_format(t_printf *tab);
void    ft_check_conv(t_printf *tab);
void	ft_reset(t_printf *tab);
void    ft_printf_c(t_printf *tab);
void    ft_printf_s(t_printf *tab);
void	ft_printf_id(t_printf *tab);
void    ft_printf_p(t_printf *tab);
int	    ft_putptr(unsigned long ptr);

/*int main(void);
char	*ft_strchr(const char *s, int c);
int	ft_atoi(const char *nptr);
int	ft_isdigit(int c);*/

# define SPECIFIERS      "cspdiuxX%"


#endif