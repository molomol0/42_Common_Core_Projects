# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/01 11:05:54 by jdenis            #+#    #+#              #
#    Updated: 2024/03/13 15:55:02 by jdenis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= DiamondTrap

CC		= c++
FLAGS	= -Wall -Wextra -Werror -Wshadow -std=c++98
RM		= rm -rf

OBJ	= 	main.o			\
		ClapTrap.o		\
		ScravTrap.o		\
		FragTrap.o		\
		DiamondTrap.o	\

HEADER	=	ClapTrap.hpp	\
			ScravTrap.hpp	\
			FragTrap.hpp	\
			DiamondTrap.hpp	\

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean re