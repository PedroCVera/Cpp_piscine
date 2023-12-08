/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:17:39 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/12/05 14:55:33 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>

template <typename T>
class	Array
{
	private:
		
		T				*_arr;
		unsigned int	_size;

	public:

		Array()
		{
			_arr = NULL;
			_size = 0;
		}
		
		Array(Array const &cpy)
		{
			_arr = new T[cpy._size]();
			_size = cpy._size;
			for (unsigned int i = 0; i < _size; i++)
				_arr[i] = cpy._arr[i];	
		}
		
		Array &operator=(Array const &other)
		{
			if (this != &other)
			{
				delete[] _arr;
				_size = other._size;
				_arr = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					_arr[i] = other._arr[i];
			}
			return *this;
		}
		
		~Array()
		{
			delete[] _arr;
		}

		Array(unsigned int n)
		{
			_arr = new T[n]();
			_size = n;
		}
		
		unsigned int	size()
		{ 
			return (_size);
		}
		
		T &operator[](unsigned int index)
		{
			if (index >= _size || index < 0)
				throw std::out_of_range("Index is out of range");
			return _arr[index];
		}
};

#endif