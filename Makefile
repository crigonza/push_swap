# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/09 22:39:41 by crigonza          #+#    #+#              #
#    Updated: 2022/08/02 21:34:16 by crigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

CC = gcc

FLAGS = -Wall -Werror -Wextra

LIBFT = Libft/libft.a

SRC_DIR = src

INC_DIR = inc

OBJ_DIR = obj

SRC_BONUS_DIR = bonus

SRC = push_swap.c \
	ft_check.c \
	ft_parse.c \
	ft_algorithm.c \
	ft_sort_utils.c \
	ft_sort_utils_2.c \
	ft_instructions.c \
	ft_instructions_2.c \
	ft_simplify_nbs.c \
	ft_sort_small_stack.c \
	ft_stacks.c \

SRC_BONUS = checker_bonus.c \
		ft_instructions_bonus.c \
		ft_instructions_2_bonus.c \
		ft_parse_bonus.c \
		ft_stacks_bonus.c \
		push_swap_bonus.c \
		ft_check_bonus.c \
		ft_moves_bonus.c \
		ft_algorithm_bonus.c \
		ft_sort_utils_bonus.c \
		ft_sort_utils_2_bonus.c \
		ft_instructions_b.c \
		ft_instructions_2_b.c \
		ft_simplify_nbs_bonus.c \
		ft_sort_small_stack_bonus.c \

		

OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

OBJ_BONUS = $(addprefix $(OBJ_DIR)/,$(SRC_BONUS:.c=.o)) 

all: $(NAME)

$(NAME):   $(OBJS)
		make -C Libft/
		$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		mkdir -p $(OBJ_DIR)
		$(CC) $(FLAGS) -c $< -o $@

bonus: $(BONUS)

$(BONUS):	$(OBJ_BONUS)
		make -C Libft/
		$(CC) $(FLAGS) $(OBJ_BONUS) $(LIBFT) -o $@

$(OBJ_DIR)/%.o: $(SRC_BONUS_DIR)/%.c
		mkdir -p $(OBJ_DIR)
		$(CC) $(FLAGS) -c $< -o $@

clean:
		rm -f $(OBJS)
		rm -rf $(OBJ_DIR)
		make clean -C Libft/

fclean: clean
		rm -f $(NAME)
		rm -f $(BONUS)
		make fclean -C Libft/

re: fclean all

.PHONY: re all clean fclean
