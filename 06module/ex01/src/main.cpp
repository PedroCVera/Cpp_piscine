/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:31:31 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/09/14 12:35:01 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"

int main()
{
	Data *data = new Data;
	data->data1 = 1;
	data->data2 = 2;
	std::cout << "data1: " << data->data1 << std::endl;
	std::cout << "data2: " << data->data2 << std::endl;
	std::cout << "Serializer..." << std::endl;
	Serializer::deserialize(Serializer::serialize(data));
	std::cout << "data1: " << data->data1 << std::endl;
	std::cout << "data2: " << data->data2 << std::endl;
	delete data;
	return 0;
}