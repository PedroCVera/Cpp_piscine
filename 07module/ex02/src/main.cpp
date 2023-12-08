/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:17:36 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/12/05 14:56:52 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Array.hpp"

int main()
{
	// Default constructor -----------------------------------------------------
	Array<int> arr1;
	std::cout << "arr1 size: " << arr1.size() << std::endl;

	
	// Constructor with an unsigned int parameter ------------------------------
	Array<int> arr2(5);
	std::cout << "arr2 size: " << arr2.size() << std::endl;


	// Copy constructor --------------------------------------------------------
	Array<int> arr3(arr2);
	std::cout << "arr3 size: " << arr3.size() << std::endl;
	for (unsigned int i = 0; i < arr3.size(); i++)
		std::cout << arr3[i] << " ";
	std::cout << std::endl;


	// Assignment operator overload --------------------------------------------
	Array<int> arr4;
	arr4 = arr3;
	std::cout << "arr4 size: " << arr4.size() << std::endl;
	for (unsigned int i = 0; i < arr4.size(); i++)
		std::cout << arr4[i] << " ";
	std::cout << std::endl;


	// Index operator overload -------------------------------------------------
	try
	{
		arr2[-5] = 1;
	}
	catch (const std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	for (unsigned int i = 0; i < arr2.size(); i++)
	{
		arr2[i] = i;
		std::cout << arr2[i] << " ";
	}
	std::cout << std::endl;

	Array<char> arr7(26);
	for (unsigned int i = 0; i < arr7.size(); i++)
	{
		arr7[i] = 'a' + i;
		std::cout << arr7[i] << " ";
	}
	std::cout << std::endl;
	

	return 0;
}