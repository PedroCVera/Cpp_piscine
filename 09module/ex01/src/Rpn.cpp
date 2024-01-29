/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rpn.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:18:12 by pcoimbra          #+#    #+#             */
/*   Updated: 2024/01/29 12:27:34 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Rpn.hpp"


RPN::RPN()
{
}

RPN::RPN(const RPN &copy)
{
	_Stack = copy._Stack;
	std::cout << "Copy constructor." << std::endl;
}

RPN &RPN::operator=(RPN const &copy)
{
	_Stack = copy._Stack;
	std::cout << "= constructor." << std::endl;
	return *this;
}

RPN::~RPN()
{
}

int	RPN::Solve_formula(int n1, int n2, char oper)
{
	switch (oper)
	{
		case '/':
			return (n1 / n2);
		case '*':
			return (n1 * n2);
		case '+':
			return (n1 + n2);
		case '-':
			return (n1 - n2);
		default:
			return 0;
	};
	return 0;
}

int	RPN::Solve_loop(char **argv)
{
	int n1, n2;
	
	for (int i = 0; argv[1][i] != '\0'; i++)
	{
		if ((argv[1][i] < '0' || argv[1][i] > '9') && argv[1][i] != '/' && argv[1][i] != '+' && argv[1][i] != '-' && argv[1][i] != '*' && argv[1][i] != ' ')
		{
			std::cout << "Error: Parenthisis and decimal numbers arent supported. Nor are letters or other special characters" << std::endl;
			return 1;
		}
		if (argv[1][i] >= '0' && argv[1][i] <= '9')
			_Stack.push(argv[1][i] - '0');
		else if (argv[1][i] == '/' || argv[1][i] == '+' || argv[1][i] == '-' || argv[1][i] == '*')
		{
				if (_Stack.size() < 2)
				{
					std::cout << "Error: Not enough numbers for the operation on:" << argv[1][i] << " operator!" << std::endl;
					return 0;
				}
				n1 = _Stack.top();	_Stack.pop();
				n2 = _Stack.top();	_Stack.pop();

				// std:: cout << "Conta e: " << n2 << argv[1][i] << n1 << std::endl;
				if (n1 == 0 && argv[1][i] == '/')
				{
					std::cout << "Error: Divisions by 0 aren't possible!" << std::endl;
					return 1;
				}
				_Stack.push(Solve_formula(n2, n1, argv[1][i]));
		}
	}
	if (_Stack.size() != 1)
	{
		std::cout << "Error: The operation misses key operators" << std::endl;
		return 0;
	}
	std::cout << _Stack.top() << std::endl;
	return 1;
}