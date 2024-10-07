/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:13:27 by jdenis            #+#    #+#             */
/*   Updated: 2024/06/11 22:35:18 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool isInputValid(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/' && (str[i] < '0' || str[i] > '9'))
			return false;
		if ((str[i] >= '0' && str[i] <= '9') && (str[i + 1] >= '0' && str[i + 1] <= '9'))
			return false;
		i++;
	}
	return true;
}

int	do_op(std::stack<int> &stack, char op)
{
	if (stack.size() < 2)
	{
		std::cerr << "Invalid input" << std::endl;
		return -1;
	}
	int a = stack.top();
	stack.pop();
	int b = stack.top();
	stack.pop();
	if (op == '+')
		stack.push(a + b);
	else if (op == '-')
		stack.push(b - a);
	else if (op == '*')
		stack.push(a * b);
	else if (op == '/')
		stack.push(b / a);
	return 0;
}

void calculate(char *str)
{
	std::stack<int> stack;
	int i = 0;

	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			stack.push(str[i] - '0');
		else if (strchr("+-*/", str[i]) )
			if (do_op(stack, str[i]) == -1)
				return;
		i++;
	}
	if (stack.size() != 1)
	{
		std::cerr << "Invalid input" << std::endl;
		return;
	}
	std::cout << stack.top() << std::endl;
}
