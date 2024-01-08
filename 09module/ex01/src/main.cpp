/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:02:50 by pcoimbra          #+#    #+#             */
/*   Updated: 2024/01/08 15:09:38 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Rpn.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "The N of arguments must be 1 which contains the expression" << std::endl;
		return 1;
	}
	RPN	solving;
	solving.Solve_loop(argv);
}