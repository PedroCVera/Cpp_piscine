/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:54:21 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/12/05 12:48:21 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <string>
# include <iostream>
# include <sstream>
# include <stdio.h>
# include <cstring>
# include <limits>
# include <cmath>
# include <stdlib.h>

class ScalarConverter
{
	private:
			static	int		_try_int(std::string str);
			static	int		_try_double(std::string str);
			static	int		_try_float(std::string str);
			static	int		_try_char(std::string str);
			ScalarConverter();
			ScalarConverter(ScalarConverter const & cpy);
			ScalarConverter &operator=(ScalarConverter const& other);
			~ScalarConverter();
	
	public:

			static	void	convert(std::string str);
			static	int		lib_id(std::string str);
			
			static	void	norm_print(char type);
			static	void	norm_print(int type);
			static	void	norm_print(double type);
			static	void	norm_print(float type);
			static	void	norm_print(std::string type, std::string tp);
			static	void	impo_print(void);
			
};

#endif