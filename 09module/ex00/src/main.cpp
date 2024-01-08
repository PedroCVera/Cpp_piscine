/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:39:20 by pcoimbra          #+#    #+#             */
/*   Updated: 2024/01/08 12:16:06 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

int	main(int ac, char *av[]) {
	if (ac != 2)
	{
		std::cout << "Error: There must be one, and only one argument as a parameter" << std::endl;
		return (1);
	}
	std::ifstream database(BITC_DATABASE);
	std::ifstream input(av[1]);
	if (!database.is_open() || !input.is_open())
	{
		if (!database.is_open())
		{
			std::cout << "Error: Couldn't open database file: [" << av[1] << "]" << std::endl;
		}
		else
			database.close();
		if (!input.is_open())
		{
			std::cout << "Error: Couldn't open input file: [" << BITC_DATABASE << "]" << std::endl;
		}
		else
			input.close();
		return (1);
	}
	btcExchange(input, database);
}