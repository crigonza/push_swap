/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 19:34:43 by crigonza          #+#    #+#             */
/*   Updated: 2022/04/22 19:51:09 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
	char  *ptr;

	ptr = (void*)malloc(nmemb * size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero (ptr, nmemb * size);
	return (ptr);
}
