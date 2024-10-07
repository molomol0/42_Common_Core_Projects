# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/01 11:05:54 by jdenis            #+#    #+#              #
#    Updated: 2024/04/12 13:22:25 by jdenis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Interface
	
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98 -g3
RM		= rm -rf

OBJ	= 	AMateria.o				\
		Character.o				\
		Ice.o					\
		Cure.o					\
		main.o					\
		MateriaSource.o			\
		

HEADER	=	AMateria.hpp		\
			Character.hpp		\
			Ice.hpp 			\
			Cure.hpp			\
			ICharacter.hpp		\
			IMateriaSource.hpp	\
			MateriaSource.hpp	\

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean re