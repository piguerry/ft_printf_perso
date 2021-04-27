# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: piguerry <piguerry@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/25 14:21:19 by piguerry          #+#    #+#              #
#    Updated: 2021/04/08 14:43:47 by piguerry         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					=	libftprintf.a

SRCS					=	ft_lst.c \
						parser_d.c \
						parser_u.c \
						ft_printf.c \
						parser_p.c \
						parser_x.c \
						flagparser.c \
						parser.c \
						parser_c.c \
						parser_s.c \
						ft_itoa_u.c 

SRCSLIB					=	libft/ft_atoi.c \
						libft/ft_isalpha.c \
						libft/ft_isdigit.c \
						libft/ft_itoa.c \
						libft/ft_strdup.c \
						libft/ft_strjoin.c \
						libft/ft_strlen.c


OBJS					=	${SRCS:.c=.o}

OBJSLIB					=	ft_atoi.o \
						ft_isalpha.o \
						ft_isdigit.o \
						ft_itoa.o \
						ft_strdup.o \
						ft_strjoin.o \
						ft_strlen.o

INCLUDES				=	ft_printf.h

INCLUDESLIB				=	libft/libft.h

CFLAGS					=	-Wall -Werror -Wextra

RM						=	rm -f

CC						=	gcc

.c.o:
						${CC} -I${INCLUDES} -c $< ${CFLAGS} -o ${<:.c=.o}

all					:	${NAME}

$(NAME)					:	
						${CC} -I${INCLUDES} -c $< ${SRCS}	
						${CC} -I${INCLUDESLIB} -c $< ${SRCSLIB}
						ar cr ${NAME} ${OBJS} ${OBJSLIB} ${INCLUDES} ${INCLUDESLIB}
						ranlib ${NAME}

clean					:	
						${RM} ${OBJS} ${OBJSLIB}

fclean					:	clean
						${RM} libftprintf.a

re					:	fclean ${NAME}

.PHONY					:	all fclean clean re
