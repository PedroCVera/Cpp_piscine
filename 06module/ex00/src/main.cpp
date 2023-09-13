/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:02:10 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/09/13 17:02:20 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ScalarConverter.hpp>

int	main (int ac, char **av)
{
	if (ac != 2)
		return 0;
	ScalarConverter::convert(av[1]);
	return 1;	
}