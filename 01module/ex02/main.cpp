/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:47:17 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/03/21 13:58:05 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "memory address of str " << &str << " !" << std::endl;
	std::cout << "memory address of strPTR " << stringPTR << " !" << std::endl;
	std::cout << "memory address of strREF " << &stringREF << " !" << std::endl;
	std::cout << "\n\nNow contents!\n" << std::endl << std::endl;
	std::cout << "Content of Variable string is:" << str << "!" << std::endl; 
	std::cout << "Content of stringPTR is:" << *stringPTR << "!" << std::endl;
	std::cout << "Content of stringREF is:" << stringREF << "!" << std::endl;
	return (1);
}