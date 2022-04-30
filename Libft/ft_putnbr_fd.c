/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:07:23 by crigonza          #+#    #+#             */
/*   Updated: 2022/04/26 21:19:22 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
    char *nbr;
    long int    ln;

    ln = n;
    nbr = ft_itoa(ln);
	ft_putstr_fd(nbr, fd);
}
