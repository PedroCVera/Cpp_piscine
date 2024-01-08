/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rpn.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:18:12 by pcoimbra          #+#    #+#             */
/*   Updated: 2024/01/08 15:29:26 by pcoimbra         ###   ########.fr       */
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
		if (argv[1][i] >= '0' && argv[1][i] <= '9')
			_Stack.push(argv[1][i] - '0');
		else if (argv[1][i] == '/' || argv[1][i] == '+' || argv[1][i] == '-' || argv[1][i] == '*')
		{
				if (_Stack.size() < 2)
				{
					std::cout << "Error! Not enough numbers for the operation on:" << argv[1][i] << " operator!" << std::endl;
					return 0;
				}
				n1 = _Stack.top();	_Stack.pop();
				n2 = _Stack.top();	_Stack.pop();		
				std::cout << "n1:" << n1 << " n2:" << n2 << " op:" << argv[1][i] << std::endl;
				_Stack.push(Solve_formula(n1, n2, argv[1][i]));
				std::cout << "result" << _Stack.top() << std::endl;
		}
	}
	if (_Stack.size() != 1)
	{
		std::cout << "Error! The operation misses key operators" << std::endl;
		return 0;
	}
	std::cout << _Stack.top() << std::endl;
	return 1;
}