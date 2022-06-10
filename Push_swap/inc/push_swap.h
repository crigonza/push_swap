/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:59:33 by crigonza          #+#    #+#             */
/*   Updated: 2022/06/09 23:56:27 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../Libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct  s_stack
{
      int               nb;
      struct s_stack *next;
}                   t_stack;

int         main(int argc, char **argv);
t_stack     *ft_stack(int argc, char **argv);
t_stack     *ft_new_node(int num);
int         ft_check_digits(char *number);

int	ft_atoi(const char *nptr);
int	ft_isdigit(int c);

















# endif