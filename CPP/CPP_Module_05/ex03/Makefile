# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 13:37:38 by jdenis            #+#    #+#              #
#    Updated: 2024/04/24 17:11:15 by jdenis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ex03
	
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

OBJ	= 	main.o						\
		Bureaucrat.o				\
		AForm.o						\
		PresidentialPardonForm.o	\
		RobotomyRequestForm.o		\
		ShrubberyCreationForm.o		\
		Intern.o					\
		

HEADER	=	AForm.hpp						\
			Bureaucrat.hpp					\
			PresidentialPardonForm.hpp		\
			RobotomyRequestForm.hpp			\
			ShrubberyCreationForm.hpp		\
			Intern.hpp						\
			

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