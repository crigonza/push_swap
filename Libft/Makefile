# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 18:39:21 by crigonza          #+#    #+#              #
#    Updated: 2022/04/22 19:11:01 by crigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	=

OBJS	=	${SRCS:.c=.o}

CC		= gcc

CCFLAGS	= -Wall -Wextra -Werror -g

RM		= rm -f

all: ${NAME}

${NAME}:
			${CC} -c ${FLAGS} ${SRCS}
			ar rcs ${NAME} ${OBJS}

clean:
				${RM} ${OBJS} 
