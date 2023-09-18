/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:47:44 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/09/18 14:08:28 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/iter.hpp"

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    char doubleArray[] = {'a', 'b', 'c', 'd', 'e', 'f'};

    ::iter(intArray, 5, ::customFunction);
    std::cout << std::endl;
    ::iter(doubleArray, 6, ::customFunction);
	std::cout << std::endl;

    return 0;
}