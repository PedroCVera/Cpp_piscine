/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:19:43 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/09/11 16:06:56 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	void ;
}

ScalarConverter::ScalarConverter(ScalarConverter const &cpy)
{
	(void) cpy;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
	(void) other;
}
ScalarConverter::~ScalarConverter()
{
	void ;
}

void	ScalarConverter::convert(std::string *str)
{
	int	i;

	i = lib_id(str);
	switch (i)
	{
		case 0:
			throw ScalarConverter::InvalidInputException();
		case 1:
			Convert_float(str);
		case 2:
			Convert_double(str);
		case 3:
			convert_int(str);
		case 4:
			convert_char(str);
		case 5:
			convert_pseudos(str);
	}
}

int	ScalarConverter::lib_id(std::string *str)
{
	int	i = 0;

	if (i = _try_pseudo(str) != 0)
		return (5);
	if (i = _try_float(str) != 0)
		return (1);
	else if (i = _try_double(str) != 0)
		return (2);
	else if (i = _try_int(str) != 0)
		return (3);
	else if (i = _try_char(str) != 0)
		return (4);
	else
		return (0);
	return (i);
}

int	ScalarConverter::_try_pseudo(std::string *str)
{
	if (strcmp(str->c_str(), "-inf") == 0 || strcmp(str->c_str(), "+inf") == 0 || strcmp(str->c_str(), "nan") == 0)
		return (1);
	return (0);
}

int	ScalarConverter::_try_char(std::string *str)
{
	if (strlen(str->c_str()) == 1)
		return (1);
	return (0);
}

int	ScalarConverter::_try_float(std::string *str)
{
	double	test;
	
	try
	{
		std::istringstream sstr(str);
	}
	
}