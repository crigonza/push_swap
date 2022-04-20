/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:09:53 by crigonza          #+#    #+#             */
/*   Updated: 2022/04/20 15:27:41 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Place n zero-valued bytes in the area pointed to by s.                     */

#include"libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

int main()
{
    char str[50] = "Aticleworld is a programming Blog.";
    printf("\nBefore memset(): %s\n\n", str);
    // Fill 6 characters starting from str[11] with '*'
    ft_bzero(str + 11, 6);
    printf("After memset(): %s\n\n", str);
    return 0;
}
