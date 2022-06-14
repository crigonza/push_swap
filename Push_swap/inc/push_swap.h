/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:59:33 by crigonza          #+#    #+#             */
/*   Updated: 2022/06/13 22:02:27 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../Libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

typedef struct  s_stack
{
      int               nb;
      struct s_stack *prev;
      struct s_stack *next;
}                   t_stack;




int         main(int argc, char **argv);
int         *ft_parse(int argc, char **argv);
int         ft_num_is_in(int *temp, int i);
int         ft_int_is_valid(char *number);
int         ft_is_sorted(t_stack **stack);
int         *ft_simplify_nbs(int *numbers);
t_stack     *ft_stack(int *numbers, int size);
t_stack     *ft_new_node(int number);
void        ft_stack_add_node(t_stack **stack, t_stack *node);
void        ft_add_top(t_stack **stack, t_stack *node);
void        ft_swap_a(t_stack **stack);
void        ft_rotate_a(t_stack **stack);
void        ft_rotate_b(t_stack **stack);
void        ft_rev_rot_a(t_stack **stack);
void        ft_rev_rot_b(t_stack **stack);
void        ft_push_b(t_stack **stack_a, t_stack **stack_b);
void        ft_push_a(t_stack **stack_a, t_stack **stack_b);
void        ft_rotate_ab(t_stack **stack_a, t_stack **stack_b);
void        ft_rev_rot_ab(t_stack **stack_a, t_stack **stack_b);












# endif