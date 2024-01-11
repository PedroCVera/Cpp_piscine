/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:23:31 by pcoimbra          #+#    #+#             */
/*   Updated: 2024/01/09 15:05:19 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/easyfind.hpp"

int	main(void)
{
	int	arr[9] = {0, 23, 4, 53, 3, 34, 33, 2, 1};
	std::vector<int> vec(arr, arr  + (sizeof(arr) / sizeof(int)));
	std::cout << "yes: " << easyfind(vec, 2) << std::endl;
	std::cout << "no: " << easyfind(vec, 567) << std::endl;

	std::string abc = "abcdefgijklmnopqrstuvwxyz";
	std::vector<char> checkChar(abc.begin(), abc.end());
	std::cout << "yes: " << easyfind(checkChar, 'w') << std::endl;
	std::cout << "no: " << easyfind(checkChar, 'h') << std::endl;

	std::cout << "no: " << easyfind(checkChar, '2') << std::endl;
}