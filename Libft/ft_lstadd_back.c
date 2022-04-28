/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 21:13:41 by crigonza          #+#    #+#             */
/*   Updated: 2022/04/28 08:07:27 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *aux;

    aux = *lst;
    if (!lst || !new)
        return;
    if (aux == NULL)
        aux = new;
    else
        while(aux->next != NULL)
            aux = aux->next;
        aux->next= new;
}