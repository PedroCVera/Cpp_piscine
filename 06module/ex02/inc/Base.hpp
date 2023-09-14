/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:35:04 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/09/14 17:39:22 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <string.h>
# include <stdint.h>
# include <iostream>
# include <cstdlib>

class	Base
{
	public:
	
		virtual	~Base();
		
		Base * generate(void);
		void identify(Base* p);
		void identify(Base& p);
};

class	A : public Base{};
class	B : public Base{};
class	C : public Base{};

#endif