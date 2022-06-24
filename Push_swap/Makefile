# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/09 22:39:41 by crigonza          #+#    #+#              #
#    Updated: 2022/06/24 18:01:36 by crigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

FLAGS = -Wall -Werror -Wextra

LIBFT = Libft/libft.a

SRC_DIR = src

INC_DIR = inc

OBJ_DIR = obj

SRC = main.c \
	ft_check_parse.c \
	ft_algorithm.c \
	ft_instructions.c \
	ft_simplify_nbs.c \
	ft_sort_small_stack.c \
	ft_stacks.c \
	push.c \

OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o)) 

all: $(NAME)

$(NAME):   $(OBJS)
		make -C Libft/
		$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		mkdir -p $(OBJ_DIR)
		$(CC) $(FLAGS) -c $< -o $@

clean:
		rm -f $(OBJS)
		rm -rf $(OBJ_DIR)
		make clean -C Libft/

fclean: clean
		rm -f $(NAME)
		make fclean -C Libft/

re: fclean all

.PHONY: re all clean fclean
