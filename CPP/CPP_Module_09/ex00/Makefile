# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 13:37:38 by jdenis            #+#    #+#              #
#    Updated: 2024/06/09 19:24:47 by jdenis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= btc
	
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

OBJ	= 	main.o				\
		BitcoinExchange.o	\
		

HEADER	=	BitcoinExchange.hpp

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean re