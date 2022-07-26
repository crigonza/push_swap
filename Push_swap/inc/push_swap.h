/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:59:33 by crigonza          #+#    #+#             */
/*   Updated: 2022/07/26 18:01:17 by crigonza         ###   ########.fr       */
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

int					main(int argc, char **argv);
int					ft_get_array(int argc, char **argv, t_stack **a);
int					*ft_parse(int argc, char **argv);
int					*ft_parse_2(int argc, char **argv);
int					ft_num_is_in(int *temp, int i);
int					ft_int_is_valid(char *number);
int					ft_check_int(long int num);
int					ft_is_sorted(t_stack **stack);
int					*ft_copy(int *numbers, int size);
int					*ft_order_copy(int *copy, int size);
int					*ft_simplify_nbs(int *numbers, int *copy, int size);
int					*ft_split_args(char *argv, int size);
int					ft_size(char *arg);
t_stack				*ft_stack(int *numbers, int size);
t_stack				*ft_new_node(int number);
t_stack				*ft_last(t_stack *st);
void				ft_stack_add_node(t_stack **stack, t_stack *node);
void				ft_swap(t_stack **stack, char c);
void				ft_swap_ab(t_stack **a, t_stack **b);
void				ft_rotate(t_stack **stack, char c);
void				ft_rev_rot(t_stack **stack, char c);
void				ft_push_b(t_stack **stack_a, t_stack **stack_b);
void				ft_push_a(t_stack **stack_a, t_stack **stack_b);
void				ft_rotate_ab(t_stack **stack_a, t_stack **stack_b);
void				ft_rev_rot_ab(t_stack **stack_a, t_stack **stack_b);
void				ft_select_sort(t_stack **a, t_stack **b, int size);
void				ft_sort_three(t_stack **a);
void				ft_sort_five(t_stack **a, t_stack **b);
void				ft_hundred(t_stack **a, t_stack **b, int size);
void				ft_five_hundred(t_stack **a, t_stack **b, int size);
void				ft_select_nb(t_stack **a, t_stack **b, int max);
void				ft_free_stack(t_stack **stack);
void				ft_push_to_a(t_stack **a, t_stack **b, int size, int siz);
void				ft_sort_to_a(t_stack **a, t_stack **b, int number);
void				ft_top_or_bottom(t_stack **stack, int bottom, int top,
						char c);
int					ft_search_top(t_stack **a, int max);
int					ft_search_top_(t_stack **b, int number);
int					ft_search_bottom(t_stack **a, int max);
int					ft_search_bottom_(t_stack **b, int number);


void	ft_select_nb_(t_stack **a, t_stack **b, int max);
void	ft_sort_to_b(t_stack **a, t_stack **b, int number);
void	ft_push_to_b(t_stack **a, t_stack **b, int size, int siz);
void ft_error(void);
#endif