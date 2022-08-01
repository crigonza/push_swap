/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:01:30 by crigonza          #+#    #+#             */
/*   Updated: 2022/08/01 18:00:19 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include "../Libft/libft.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_stack
{
	int				nb;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

typedef struct s_moves
{
	char			*move;
	struct s_moves	*prev;
	struct s_moves	*next;
}					t_moves;

int					main(int argc, char **argv);
void				ft_checker(t_stack **a, t_stack **b, t_moves *moves);
void				ft_get_array_bonus(int argc, char **argv, t_stack **a);
int					ft_check_orders(t_stack **c, t_stack **d, char *order);
int					ft_check_orders_2(t_stack **c, t_stack **d, char *order);
void				ft_swap_bonus(t_stack **stack);
void				ft_rotate_bonus(t_stack **stack);
void				ft_rotate_ab_bonus(t_stack **stack_a, t_stack **stack_b);
void				ft_rev_rot_bonus(t_stack **stack);
void				ft_rev_rot_bonus(t_stack **stack);
void				ft_rev_rot_ab_bonus(t_stack **stack_a, t_stack **stack_b);
void				ft_push_b_bonus(t_stack **stack_a, t_stack **stack_b);
void				ft_push_a_bonus(t_stack **stack_a, t_stack **stack_b);
void				ft_swap_ab_bonus(t_stack **a, t_stack **b);
int					*ft_parse_bonus(int argc, char **argv);
int					*ft_split_args_bonus(char *argv, int size);
int					ft_size_bonus(char *arg);
int					ft_num_is_in_bonus(int *temp, int i);
int					ft_int_is_valid_bonus(char *number);
t_stack				*ft_stack_bonus(int *numbers, int size);
t_stack				*ft_new_node_bonus(int number);
t_stack				*ft_last_bonus(t_stack *st);
void				ft_stack_add_node_bonus(t_stack **st, t_stack *node);

void				push_swap_bonus(int argc, char **argv, t_moves **moves);
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
void				ft_swap(t_stack **stack, char c, t_moves **moves);
void				ft_swap_ab(t_stack **a, t_stack **b, t_moves **moves);
void				ft_rotate(t_stack **stack, char c, t_moves **moves);
void				ft_rev_rot(t_stack **stack, char c, t_moves **moves);
void				ft_push_b(t_stack **stack_a, t_stack **stack_b,
						t_moves **moves);
void				ft_push_a(t_stack **stack_a, t_stack **stack_b,
						t_moves **moves);
void				ft_rotate_ab(t_stack **stack_a, t_stack **stack_b,
						t_moves **moves);
void				ft_rev_rot_ab(t_stack **stack_a, t_stack **stack_b,
						t_moves **moves);
void				ft_select_sort(t_stack **a, t_stack **b, int size,
						t_moves **moves);
void				ft_sort_three(t_stack **a, t_moves **moves);
void				ft_sort_five(t_stack **a, t_stack **b, t_moves **moves);
void				ft_hundred(t_stack **a, t_stack **b, int size,
						t_moves **moves);
void				ft_five_hundred(t_stack **a, t_stack **b, int size,
						t_moves **moves);
void				ft_select_nb(t_stack **a, t_stack **b, int max,
						t_moves **moves);
void				ft_free_stack(t_stack **stack);
void				ft_push_to_a(t_stack **a, t_stack **b, int size,
						t_moves **moves);
void				ft_sort_to_a(t_stack **a, t_stack **b, int number,
						t_moves **moves);
void				ft_top_or_bottom(t_stack **stack, int *tb, char c,
						t_moves **moves);
int					ft_search_top(t_stack **a, int max);
int					ft_search_top_(t_stack **b, int number);
int					ft_search_bottom(t_stack **a, int max);
int					ft_search_bottom_(t_stack **b, int number);

void				ft_select_nb_(t_stack **a, t_stack **b, int max,
						t_moves **moves);
void				ft_sort_to_b(t_stack **a, t_stack **b, int number,
						t_moves **moves);
void				ft_push_to_b(t_stack **a, t_stack **b, int *key,
						t_moves **moves);
void				ft_error(void);
void				ft_new_move(t_moves **moves, char *move);
void				ft_move_add(t_moves **moves, t_moves *node);
t_moves				*ft_lastm(t_moves *moves);
void				ft_free_moves(t_moves **moves);

#endif