/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:54:21 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/09/11 16:03:07 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <string>
# include <iostream>
# include <sstream>
# include <stdio.h>
# include <cstring>

class ScalarConverter
{
	private:
			static	int		_try_int(std::string *str);
			static	int		_try_double(std::string *str);
			static	int		_try_float(std::string *str);
			static	int		_try_char(std::string *str);
			static	int		_try_pseudo(std::string *str);
			static	char	_char;
			static	int		_int;
			static	float	_float;
			static	double	_double;
	
	public:
			ScalarConverter();
			ScalarConverter(ScalarConverter const & cpy);
			ScalarConverter &operator=(ScalarConverter const& other);
			~ScalarConverter();

			static	void	convert(std::string *str);
			static	int		lib_id(std::string *str);


			
			class InvalidInputException : std::exception
			{
				public:
					const char *what() const throw();
			};
			
};

#endif