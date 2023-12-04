/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:23:56 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/12/04 13:31:00 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"
# include <stdint.h>
# include <iostream>

class Serializer
{
	private:
	
		Serializer();
		Serializer(Serializer const &cpy);
		Serializer &operator=(Serializer const &other);
		~Serializer();
		
	public:

		static uintptr_t serialize(Data* ptr);
		static Data *deserialize(uintptr_t raw);
};

#endif
