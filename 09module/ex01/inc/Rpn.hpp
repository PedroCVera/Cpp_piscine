/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rpn.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:11:13 by pcoimbra          #+#    #+#             */
/*   Updated: 2024/01/08 15:08:44 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <fstream>
#include <limits>
#include <cstdlib>
#include <stack>

class RPN
{
	private:
		std::stack<int> _Stack;
		
	public:
		RPN();
		RPN(const RPN &copy);
		RPN	&operator=(RPN const &copy);
		~RPN();

		int Solve_formula(int n1, int n2, char Oper);
		int	Solve_loop(char **argv);
};

#endif