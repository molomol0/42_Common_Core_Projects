# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 15:44:16 by jdenis            #+#    #+#              #
#    Updated: 2023/06/06 14:36:38 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	type/ft_isalnum.c \
			type/ft_isprint.c \
			mem/ft_memcmp.c  \
			fd/ft_putchar_fd.c \
			string/ft_split.c \
			string/ft_strlcat.c \
			string/ft_strncmp.c \
			string/ft_substr.c \
			conversion/ft_atoi.c \
			type/ft_isalpha.c \
			conversion/ft_itoa.c \
			fd/ft_putendl_fd.c \
			string/ft_strchr.c \
			string/ft_strlcpy.c \
			string/ft_strnstr.c \
			type/ft_tolower.c \
			mem/ft_bzero.c \
			type/ft_isascii.c \
			mem/ft_memcpy.c \
			mem/ft_memmove.c \
			fd/ft_putnbr_fd.c \
			string/ft_strdup.c \
			string/ft_strlen.c \
			string/ft_strrchr.c \
			type/ft_toupper.c \
			mem/ft_calloc.c \
			type/ft_isdigit.c \
			mem/ft_memchr.c \
			mem/ft_memset.c \
			fd/ft_putstr_fd.c \
			string/ft_strjoin.c \
			string/ft_strmapi.c \
			string/ft_strtrim.c \
			string/ft_striteri.c \
			list/ft_lstnew.c \
			list/ft_lstadd_front.c \
			list/ft_lstsize.c \
			list/ft_lstlast.c \
			list/ft_lstadd_back.c \
			list/ft_lstdelone.c \
			list/ft_lstclear.c \
			list/ft_lstiter.c \
			list/ft_lstmap.c

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}


all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all