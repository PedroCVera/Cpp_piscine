/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:23:55 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/12/04 13:34:40 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"
#include "../inc/Data.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(Serializer const &cpy)
{
	*this = cpy;
}

Serializer &Serializer::operator=(Serializer const &other)
{
	(void)other;
	return *this;
}

Serializer::~Serializer()
{
}

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t	help;

	help = reinterpret_cast<uintptr_t>(ptr);
	return (help);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	Data	*help;
	help = reinterpret_cast<Data*>(raw);
	return (help);
}
