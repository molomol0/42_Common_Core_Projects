# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 13:52:37 by marvin            #+#    #+#              #
#    Updated: 2023/06/06 13:52:37 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

SRCS =	operations/push.c \
		operations/reverse.c \
		operations/rotate.c \
		operations/swap.c \
		utils_main.c \
		list_to_stack.c \
		main.c

OBJS = $(SRCS:.c=.o)
HEADER_FILES = push_swap.h
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(HEADER_FILES) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_PATH) -lft

$(OBJS): %.o: %.c $(HEADER_FILES)
	$(CC) $(CFLAGS) -I. -I$(LIBFT_PATH)/includes -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re