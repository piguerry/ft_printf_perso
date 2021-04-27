# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: piguerry <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/22 14:54:35 by piguerry          #+#    #+#              #
#    Updated: 2019/11/12 11:52:56 by piguerry         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					=	libft.a

SRCS					=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

BONUS					= ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

OBJS					=	${SRCS:.c=.o}

OBJSBONUS				=	${BONUS:.c=.o}

INCLUDES				=	libft.h

CFLAGS					=	-Wall -Werror -Wextra

RM						=	rm -f

CC						=	gcc

.c.o:
						${CC} -I${INCLUDES} -c $< ${CFLAGS} -o ${<:.c=.o}

all					:	${NAME}

$(NAME)				:	${OBJS}
						ar cr ${NAME} ${OBJS} ${INCLUDES}
						ranlib ${NAME}

bonus				:	${OBJSBONUS}
						ar cr ${NAME} ${OBJSBONUS} ${INCLUDES}
						ranlib ${NAME}

clean				:	
						${RM} ${OBJS} ${OBJSBONUS}

fclean				:	clean
						${RM} libft.a

re					:   fclean ${NAME}

.PHONY				:	all bonus fclean clean re
