/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:59:55 by pcoimbra          #+#    #+#             */
/*   Updated: 2024/01/09 16:23:46 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>

template <typename T>

class	MutantStack : public std::stack<T>
{
	public:
			MutantStack(void) : std::stack<T>()
			{
				std::cout << "MutantStack constructor was called." << std::endl;
			};
			MutantStack(MutantStack const &cpy) : std::stack<T>(cpy)
			{
				(void) cpy;
				std::cout << "Copy constructor was called" << std::endl;
			};
			MutantStack& operator=(const MutantStack& other)
			{
				std::cout << "\e[0;33mAssignment Operator Constructor called of MutantStack \e[0m" << std::endl;
				if (this == &other)
        			return *this;
				static_cast<std::stack<T>&>(*this) = static_cast<const std::stack<T>&>(other);
				return *this;
    		};
			~MutantStack( void )
			{
				std::cout << "Destructor was called" << std::endl;
			};

			typedef typename std::deque<T>::iterator iterator;
			
			iterator begin() 
			{
				return this->c.begin();
			};
			iterator end() 
			{
				return this->c.end();
			};
			
};

#endif