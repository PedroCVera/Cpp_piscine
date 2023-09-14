/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:23:56 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/09/14 12:27:20 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"
# include <stdint.h>
# include <iostream>

class Serializer
{
		Serializer();
		Serializer(Serializer const &cpy);
		Serializer &operator=(Serializer const &other);
		~Serializer();
	public:

		static uintptr_t serialize(Data* ptr);
		static Data *deserialize(uintptr_t raw);
};

#endif