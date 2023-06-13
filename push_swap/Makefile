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
CHECKER_NAME = checker
CC = @cc
CFLAGS = -Wall -Wextra -Werror -g3

SRCS =	operations/push.c \
		operations/reverse.c \
		operations/rotate.c \
		operations/swap.c \
		utils_main.c \
		list_to_stack.c \
		is_sort.c \
		solver.c \
		solver_three.c \
		solver_ten.c \
		get_pos.c \
		pop.c \
		solver_big.c \
		solver_big_big.c \
		up.c \
		solver_five.c \
		init.c

SWAP_SRCS = main.c $(SRCS)
CHECKER_SRCS = checker.c $(SRCS)

OBJS = $(SWAP_SRCS:.c=.o)
OBJS_CHECKER = $(CHECKER_SRCS:.c=.o)

HEADER_FILES = push_swap.h
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME) $(CHECKER_NAME)

$(NAME): $(OBJS) $(HEADER_FILES) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_PATH) -lft
	@echo "	Compilation of  $(NAME):  \033[1;32mOK\033[m"

$(CHECKER_NAME): $(OBJS_CHECKER) $(HEADER_FILES) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(CHECKER_NAME) $(OBJS_CHECKER) -L$(LIBFT_PATH) -lft
	@echo "	Compilation of  $(CHECKER_NAME):  \033[1;32mOK\033[m"

$(OBJS): %.o: %.c $(HEADER_FILES)
	@$(CC) $(CFLAGS) -I. -I$(LIBFT_PATH)/includes -c $< -o $@

$(OBJS_CHECKER): %.o: %.c $(HEADER_FILES)

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_PATH)

clean:
	@$(MAKE) -s -C $(LIBFT_PATH) clean
	@rm -f $(OBJS)
	@rm -f $(OBJS_CHECKER)
	@echo "\033[1;33m>> all .o files are deleted.\033[0m"

fclean: clean
	@$(MAKE) -s -C $(LIBFT_PATH) fclean
	@rm -f $(NAME)
	@echo "\033[0;31m>> $(NAME) all objects are deleted.\033[0m"
	@rm -rf $(CHECKER_NAME)
	@echo "\033[0;31m>> $(CHECKER_NAME) all objects are deleted.\033[0m"

re: fclean all

.PHONY: all clean fclean re