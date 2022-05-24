# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/15 18:57:32 by crigonza          #+#    #+#              #
#    Updated: 2022/05/21 19:40:16 by crigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

AR = ar rcs

LIBFT = Libft

SRC_DIR = src

INC_DIR = inc

OBJ_DIR = obj

SRC = ft_printf.c ft_ini_reset.c ft_printf_chr.c \
		ft_print_str.c ft_printf_nbr.c ft_print_ptr.c \
		ft_printf_hex.c ft_print_u.c

SRCS = $(addprefix $(SRC_DIR)/,$(SRC))

OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp Libft/Libft.a ./$(NAME)
	@$(AR) $(NAME) $(OBJS)
	@ranlib $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p obj
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re:	fclean all

bonus: re

.PHONY: re all clean fclean

