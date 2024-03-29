/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:19:43 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/12/05 12:57:47 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ScalarConverter.hpp>

ScalarConverter::ScalarConverter()
{
	return ;
}

ScalarConverter::ScalarConverter(ScalarConverter const &cpy)
{
	*this = cpy;
	return ;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
	(void)other;
	return *this;
}
ScalarConverter::~ScalarConverter()
{
	return ;
}

void	ScalarConverter::convert(std::string str)
{
	int					type = 0;
	const std::string	Flimits[4] = {"inff", "-inff", "+inff", "nanf"};
	const std::string	Dlimits[4] = {"inf", "-inf", "+inf", "nan"};
	
	for (int i = 0; i < 4; i++ )
	{
		if (str == Flimits[i] || str == Dlimits[i])
			norm_print(Flimits[i], Dlimits[i]);
	}
	type = lib_id(str);
	switch (type)
	{
		case 1:
		{
			std::istringstream	numberStream(str);
			float				valueFloat;
			numberStream >> valueFloat; 
			std::cout << "Type: float" << std::endl;
			norm_print(valueFloat);
			return ;
		}
		case 2:
		{
			std::istringstream numberStream(str);
			double	valueDouble;
			numberStream >> valueDouble; 
			std::cout << "Type: double" << std::endl;
			norm_print(valueDouble);
			return ;
		}
		case 3:
		{
			std::istringstream numberIntStream(str);
			int	valueInt;
			numberIntStream >> valueInt;
			std::cout << "Type: int" << std::endl;
			norm_print(valueInt);
			return ;
		}
		case 4:
			std::cout << "Type: char" << std::endl;
			norm_print(str[0]);
			break ;
		default:
			impo_print();
	}
	return ;
}

int	ScalarConverter::lib_id(std::string str)
{

	if (_try_char(str) != 0)
		return (4);
	else if (_try_int(str) != 0)
		return (3);
	else if (_try_float(str) != 0)
		return (1);
	else if (_try_double(str) != 0)
		return (2);
	else
		return (0);
	return (0);
}

int	ScalarConverter::_try_char(std::string str)
{
	if (std::strlen(str.c_str()) == 1 && !(str[0] >= '0' && str[0] <= '9'))
			return (1);
	return (0);
}

int	ScalarConverter::_try_float(std::string str)
{
	int	i = 1;
	int	dot = 0;
	int	signals = 0;
	int	ff = 0;
	
	if (str[0] == '+' || str[0] == '-')
		signals++;
	if (str[str.size() - 1] == 'f')
		ff++;
	while (str[i])
	{
		if (str[i] == '.')
			dot++;
		else if ((str[i] < '0' || str[i] > '9') && str[str.size() - 1] != str[i])
			return (0);
		i++;
	}
	if (dot > 1 || signals > 1 || ff > 1)
		return (0);
	else if (dot == 0 || ff == 0)
		return (0);
	else if (dot == 1 && signals == 1 && ff == 1 && str.size() == 3 )
		return (0);
	else if (ff == 1 && str.size() == 2)
		return (0);
	double	testing = strtod(str.c_str(), NULL);
	if (testing == HUGE_VAL || testing == -HUGE_VAL)
		return 0;
	if (testing > std::numeric_limits<float>::max() || testing < -std::numeric_limits<float>::max())
		return 0;
	else
		return 1;
	return (0);
}

int	ScalarConverter::_try_double(std::string str)
{
	int	i = 1;
	int	dot = 0;
	int	signals = 0;
	
	if (str[0] == '+' || str[0] == '-')
		signals++;
	while (str[i])
	{
		if (str[i] == '.')
			dot++;
		else if (!std::isdigit(str[i]))
			return (0);
		i++;
	}
	if (dot > 1 || signals > 1)
		return (0);
	double	testing = strtod(str.c_str(), NULL);
	if (testing == HUGE_VAL || testing == -HUGE_VAL)
		return 0;
	else
		return 1;
	return (0);
}

int	ScalarConverter::_try_int(std::string str)
{
	int	i = 1;
	int	signals = 0;

	if (str.size() == 1 && str[0] == '0')
		return 1;
	if (str[0] == '+' || str[0] == '-')
		signals++;
	while (str[i])
	{
		if (!std::isdigit(str[i]))
			return (0);
		i++;
	}
	if (signals > 1)
		return (0);
		
	double	testing = strtod(str.c_str(), NULL);
	
	if (testing == HUGE_VAL || testing == -HUGE_VAL)
		return 0;
	if (testing > std::numeric_limits<int>::max() || testing < std::numeric_limits<int>::min())
		return 0;
	else
		return 1;

	return (0);
}

void	ScalarConverter::norm_print(char c)
{
	std::cout << "char '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
}

void	ScalarConverter::norm_print(std::string Flimit, std::string Dlimit)
{
	std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << Flimit << std::endl;
	std::cout << "double: " << Dlimit << std::endl;

	exit(1);
}

void	ScalarConverter::norm_print(int type)
{
	std::cout << "char: ";
	if (type < 32 || type > 126)
		std::cout << "non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(type) << "'" << std::endl;
	std::cout << "int: " << type << std::endl;
	std::cout << "float: " << static_cast<float>(type) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(type) << ".0" << std::endl;
}

void	ScalarConverter::norm_print(double type)
{
	std::cout << "char: ";
	if (type < 32 || type > 126)
		std::cout << "non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(type) << "'" << std::endl;
	if (type >  std::numeric_limits<int>::max() || type <  std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(type) << std::endl;
	if (type > std::numeric_limits<float>::max() || type < -std::numeric_limits<float>::max())
		std::cout << "float: impossible " << std::endl;
	else
	{
		if (static_cast<double>(type) == static_cast<int>(type))
			std::cout << "float: " << static_cast<float>(type) << ".0f" << std::endl;
		else
			std::cout << "float: " << static_cast<float>(type) << "f" << std::endl;
	}
	if (static_cast<double>(type) == static_cast<int>(type))
		std::cout << "double: " << type << ".0" << std::endl;
	else
		std::cout << "double: " << type << std::endl;
}

void	ScalarConverter::norm_print(float type)
{
	std::cout << "char: ";
	if (type < 32 || type > 126)
		std::cout << "non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(type) << "'" << std::endl;
	if (type > static_cast<float>(std::numeric_limits<int>::max()) || type < static_cast<float>(std::numeric_limits<int>::min()))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(type) << std::endl;
	if (static_cast<double>(type) == static_cast<int>(type))
	{
		std::cout << "float: " << type << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(type) << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << type << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(type) << std::endl;
	}
}

void	ScalarConverter::impo_print(void)
{
	std::cout << "char: " << "impossible" << std::endl;
    std::cout << "int: " << "impossible" << std::endl;
    std::cout << "float: " << "nanf" << std::endl;
    std::cout << "double: " << "nan" << std::endl;

	exit(1);
}