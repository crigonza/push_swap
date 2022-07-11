/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:01:30 by crigonza          #+#    #+#             */
/*   Updated: 2022/07/11 20:36:05 by crigonza         ###   ########.fr       */
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

int					main(int argc, char **argv);
void				ft_checker(t_stack **c, t_stack **d);
int					ft_check_orders(t_stack **c, t_stack **d, char *order);
int					ft_check_orders_2(t_stack **c, t_stack **d, char *order);
int					ft_is_sorted_bonus(t_stack **stack);
char				*get_next_line(int fd);
char				*ft_get_buffer(int fd, char *buffer);
char				*ft_get_line(char *buffer);
char				*ft_next(char *buffer);
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

#endif