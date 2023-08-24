# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/04 14:28:22 by jdenis            #+#    #+#              #
#    Updated: 2023/08/15 00:48:52 by jdenis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex_bonus
CC = @cc
CFLAGS = -Wall -Wextra -Werror

SRCS =	srcs/pipex.c \
		srcs/pipex_utils.c

SRCS_BONUS =	srcs_bonus/pipex_bonus.c \
				srcs_bonus/pipex_bonus_utils.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

HEADER_FILES = srcs/pipex.h
HEADER_FILES_BONUS = srcs_bonus/pipex_bonus.h
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME) 

$(NAME): $(OBJS) $(HEADER_FILES) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_PATH) -lft
	@echo "	Compilation of  $(NAME):  \033[1;32mOK\033[m"

$(OBJS): %.o: %.c $(HEADER_FILES)
	$(CC) $(CFLAGS) -I. -I$(LIBFT_PATH)/includes -c $< -o $@

bonus: $(OBJS_BONUS) $(HEADER_FILES_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) -L$(LIBFT_PATH) -lft
	@echo "	Compilation of  $(NAME_BONUS):  \033[1;32mOK\033[m"

$(OBJS_BONUS): %.o: %.c $(HEADER_FILES_BONUS)
	$(CC) $(CFLAGS) -I. -I$(LIBFT_PATH)/includes -c $< -o $@

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_PATH)

clean:
	@$(MAKE) -s -C $(LIBFT_PATH) clean
	@rm -f $(OBJS)
	@rm -f $(OBJS_BONUS)
	@echo "\033[1;33m>> all .o files are deleted.\033[0m"

fclean: clean
	@$(MAKE) -s -C $(LIBFT_PATH) fclean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@echo "\033[0;31m>> $(NAME) all objects are deleted.\033[0m"

re: fclean all

.PHONY: all clean fclean re