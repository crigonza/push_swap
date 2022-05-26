# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/15 18:57:32 by crigonza          #+#    #+#              #
#    Updated: 2022/05/26 18:43:29 by crigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

AR = ar rc

LIBFT = Libft

SRC_DIR = src

INC_DIR = inc

OBJ_DIR = obj

SRC = ft_printf.c printf_utils.c ft_print_u.c \
		ft_print_str.c ft_printf_nbr.c ft_print_ptr.c \
		ft_printf_hex.c 

BONUS_SRC = ft_printf_bonus.c printf_utils_bonus.c \
			ft_print_u_bonus.c ft_print_str_bonus.c \
			ft_printf_nbr_bonus.c ft_print_ptr_bonus.c \
			ft_printf_hex_bonus.c

SRCS = $(addprefix $(SRC_DIR)/,$(SRC))

OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

BONUSOBJS = $(addprefix $(OBJ_DIR)/,$(BONUS_SRC:.c=.o))

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
	RM -f $(BONUSOBJS)
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

bonus: $(BONUSOBJS)
	make -C $(LIBFT)
	cp Libft/Libft.a ./$(NAME)
	$(AR) $(NAME) $(BONUSOBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p obj
	$(CC) $(FLAGS) -c $< -o $@

.PHONY: re all clean fclean

