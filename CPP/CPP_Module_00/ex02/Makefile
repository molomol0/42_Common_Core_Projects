# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/26 09:51:31 by jdenis            #+#    #+#              #
#    Updated: 2024/02/26 10:09:17 by jdenis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Account
	
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

OBJ	= 	Account.o	\
		tests.o		\

HEADER	=	Account.hpp

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean re

#comparaison des log diff <(cut -c18- 19920104_091532.log) <(cut -c18- mes_log.log)