/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:40:06 by crigonza          #+#    #+#             */
/*   Updated: 2022/04/28 20:00:48 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
size_t  ft_words(char const *s, char c)
{
    int     i;
    size_t  j;
    char    *str;

    i = 0;
    j = 0;
    str = s;
    if (str[i] != c)
    j++;
    i++;
    while(str[i])
    {
        if (str[i] == c && str[i + 1] && str[i + 1] != '\0')
            j++;
        i++;
    }
    return(j);
}
char    **ft_split(char const *s, char c)
{
    size_t  words;
    char    **

    words = ft_words(s, c);

}