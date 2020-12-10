# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiborroq <kiborroq@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/12 15:07:14 by kiborroq          #+#    #+#              #
#    Updated: 2020/11/17 00:38:55 by kiborroq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
LIBFT 		= libft/
SRCS_DIR	= srcs/
SRCS		= ${SRCS_DIR}parse_conv_utils.c \
			${SRCS_DIR}ft_printf_utils.c \
			${SRCS_DIR}treat_char.c \
			${SRCS_DIR}treat_str.c \
			${SRCS_DIR}treat_int.c \
			${SRCS_DIR}treat_uint.c \
			${SRCS_DIR}treat_hex.c \
			${SRCS_DIR}treat_point.c \
			${SRCS_DIR}treat_perc.c \
			${SRCS_DIR}ft_printf.c
OBJS		= ${SRCS:.c=.o}
INCL		= includes/
CC			= gcc
CFLAGS		= -Werror -Wextra -Wall

.c.o :
			@${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCL}

${NAME} : 	${OBJS}
			@make bonus -C ${LIBFT}
			@cp ${LIBFT}/libft.a ${NAME}
			@echo Create ${NAME}
			@ar rc ${NAME} ${OBJS}
			@ranlib ${NAME}

all :		${NAME}

clean :
			@make clean -C ${LIBFT}
			@echo Remove all *.o
			@rm -f ${OBJS}

fclean : 	clean
			@make fclean -C ${LIBFT}
			@echo Remove ${NAME}
			@rm -f ${NAME}

re : 		fclean all

.PHONY: 	all clean fclean re .c.o test
