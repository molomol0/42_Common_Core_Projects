# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/28 08:09:31 by jdenis            #+#    #+#              #
#    Updated: 2024/02/28 09:14:20 by jdenis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= violence
	
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

OBJ	= 	main.o			\
		Weapon.o		\
		HumanA.o		\
		HumanB.o		\

HEADER	=	Weapon.hpp	\
			HumanA.hpp		\
			HumanB.hpp		\

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean re