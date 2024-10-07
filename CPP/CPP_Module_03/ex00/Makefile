# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/01 11:05:54 by jdenis            #+#    #+#              #
#    Updated: 2024/03/05 14:48:16 by jdenis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ClapTrap
	
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

OBJ	= 	main.o			\
		ClapTrap.o		\

HEADER	=	ClapTrap.hpp

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean re