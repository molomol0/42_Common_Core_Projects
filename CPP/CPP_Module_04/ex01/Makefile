# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/01 11:05:54 by jdenis            #+#    #+#              #
#    Updated: 2024/04/07 11:08:38 by jdenis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Intelligent
	
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

OBJ	= 	main.o			\
		Animal.o		\
		Cat.o			\
		Dog.o			\
		WrongAnimal.o	\
		WrongCat.o		\
		Brain.o			\
		

HEADER	=	Animal.hpp		\
			Cat.hpp			\
			Dog.hpp			\
			WrongAnimal.hpp	\
			WrongCat.hpp	\
			Brain.hpp		\

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean re