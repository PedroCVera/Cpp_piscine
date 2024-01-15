/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:00:00 by pcoimbra          #+#    #+#             */
/*   Updated: 2024/01/11 12:01:43 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PMergeMe.hpp"

int main(int ac, char **av)
{
	PmergeMe merging;

	if (ac > 1)
	{
		merging.Parse(ac, av);
	}	
	else
		std::cout << "bad arguments" << std::endl;
	return 1;
}