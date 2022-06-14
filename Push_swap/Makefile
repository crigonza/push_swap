# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/09 22:39:41 by crigonza          #+#    #+#              #
#    Updated: 2022/06/11 12:28:04 by crigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

FLAGS = -Wall -Werror -Wextra

AR = ar rc

LIBFT = LIBFT

SRC_DIR = src

INC_DIR = inc

OBJ_DIR = obj

SRC = main.c ft_check_parse.c \

SRCS = $(addprefix $(SRC_DIR)/,$(SRC)) 

OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o)) 

all: $(NAME)

$(NAME): $(OBJS)
		make -C $(LIBFT)
		cp Libft/Libft.a ./$(NAME)
		$(AR) $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		mkdir -p obj
		$(CC) $(FLAGS) -c $< -o $@

clean:
		rm -f $(OBJS)
		rm -rf $(OBJ_DIR)
		make clean -C $(LIBFT)

fclean: clean
		rm -f $(NAME)
		make fclean -C $(LIBFT)

re: fclean all

.PHONY: re all clean fclean
