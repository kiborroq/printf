# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiborroq <kiborroq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/31 11:14:47 by kiborroq          #+#    #+#              #
#    Updated: 2020/11/02 16:57:10 by kiborroq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
SRCS		= ft_memset.c\
			ft_bzero.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_strlen.c\
			ft_strdup.c\
			ft_strndup.c \
			ft_strlcat.c\
			ft_strchr.c\
			ft_strrchr.c\
			ft_strnstr.c\
			ft_strncmp.c\
			ft_atoi.c\
			ft_isalpha.c\
			ft_isdigit.c\
			ft_isalnum.c\
			ft_isascii.c\
			ft_isprint.c\
			ft_isspace.c \
			ft_toupper.c\
			ft_tolower.c\
			ft_substr.c\
			ft_strjoin.c\
			ft_strtrim.c\
			ft_split.c\
			ft_itoa.c\
			ft_itoa_base.c \
			ft_uitoa.c \
			ft_putchar_fd.c\
			ft_putstr_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c \
			ft_calloc.c \
			ft_strlcpy.c \
			ft_strmapi.c \
			ft_memccpy.c
SRCS_B		= ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c
OBJS		= ${SRCS:.c=.o}
OBJS_B		= ${SRCS_B:.c=.o}
CC			= gcc
CFLAGS		= -Werror -Wextra -Wall

.c.o :
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I.

${NAME} : 	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

bonus:		${OBJS} ${OBJS_B}
			ar rc ${NAME} ${OBJS}  ${OBJS_B}
			ranlib ${NAME}

so :		
			${CC} -shared -o libft.so ${OBJS}

all :		${NAME}

clean :
			rm -f ${OBJS} ${OBJS_B}

fclean : 	clean
			rm -f ${NAME}
			rm -f libft.so

re : 		fclean all

.PHONY: 	all clean fclean re .c.o test
