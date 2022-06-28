/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:59:33 by crigonza          #+#    #+#             */
/*   Updated: 2022/06/28 18:29:35 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../Libft/libft.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nb;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

int	      main(int argc, char **argv);
int	      *ft_parse(int argc, char **argv);
int	      ft_num_is_in(int *temp, int i);
int	      ft_int_is_valid(char *number);
int	      ft_is_sorted(t_stack **stack);
int	      *ft_copy(int *numbers, int size);
int	      *ft_order_copy(int *copy, int size);
int	      *ft_simplify_nbs(int *numbers, int *copy, int size);
t_stack		*ft_stack(int *numbers, int size);
t_stack     *ft_new_node(int number);
void		ft_stack_add_node(t_stack **stack, t_stack *node);
void		ft_add_top(t_stack **stack, t_stack *node);
void		ft_swap(t_stack **stack, char c);
void		ft_rotate(t_stack **stack, char c);
void		ft_rotate_b(t_stack **stack);
void		ft_rev_rot(t_stack **stack, char c);
void		ft_rev_rot_b(t_stack **stack);
void		ft_push_b(t_stack **stack_a, t_stack **stack_b);
void		ft_push_a(t_stack **stack_a, t_stack **stack_b);
void		ft_rotate_ab(t_stack **stack_a, t_stack **stack_b);
void		ft_rev_rot_ab(t_stack **stack_a, t_stack **stack_b);
void		ft_sort_small_stack(t_stack **a, t_stack **b, int size);
void		ft_sort_three(t_stack **a);
void		ft_sort_five(t_stack **a, t_stack **b);
void		ft_sort_five_(t_stack **a);
void		ft_chunk(t_stack **a, t_stack **b);
void        ft_select_nb(t_stack **a, t_stack **b, int max);
void		ft_free_stack(t_stack **stack);
void	    ft_sort_to_a(t_stack **a, t_stack **b, int number);

void		ft_prepare_push(t_stack **a, t_stack **b);
int		ft_search_top(t_stack **a, int max);
int		ft_search_top_(t_stack **b, int number);
int		ft_search_botton(t_stack **a, int max);
int		ft_search_botton_(t_stack **b, int number);

#endif