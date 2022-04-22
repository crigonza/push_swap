/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 19:53:28 by crigonza          #+#    #+#             */
/*   Updated: 2022/04/22 19:59:54 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *s)
{
	const char	*ptr;

	ptr = (const char*)malloc(sizeof(s));
	while(*s++ && *ptr++)
	{
		ptr = s;
	}
	return (ptr);
}
