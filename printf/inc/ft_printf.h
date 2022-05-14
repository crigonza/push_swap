/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:44:36 by crigonza          #+#    #+#             */
/*   Updated: 2022/05/14 11:30:49 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "../libft/libft.h"
#include <stdarg.h>

typedef struct  s_formats
{
    int     minus;
    int     zero;
    int     precission;
    int     point;
    int     width;
    int     sharp;
    int     space;
    int     plus;
}

#define SPECIFIERS      "cspdiuxX%"


#endif