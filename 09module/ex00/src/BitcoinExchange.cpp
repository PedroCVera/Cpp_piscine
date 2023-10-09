/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:39:19 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/10/09 17:48:18 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitCoinExchange.hpp>

bool	check_csv(std::string line) 
{
	bool	dot = false;
	bool	number = false;
	int		i;
	double	test;
	

	if (line.length() < 11)
		return false;
	for (i = 0; i <= 10; i++)
	{
		if ((i == 4 || i == 7) && line[i] != '-')
			return false;
		else if ((i == 10) && line[i] != ',')
			return false;
		else if (line[i] < '0' && line[i] > '9')
			return false;
	}
	test = std::atof(line.substr(11).c_str());
	if (test > std::numeric_limits<float>::max() || test < 0)
		return false;
	for (i = 11; line[i] && ((line[i] >= '0' && line[i] <= '9') || line[i] == '.'); i++)
	{
		if (line[i] == '.')
		{
			if (dot)
				return false;
			dot = true;
		}
		if (line[i] >= '0' && line[i] <= '9')
			number = true;
	}
	if (line[i] || !number || !isValidDate(line))
		return false;
	return true;
}

bool	isValidDate(std::string date) {
	int year = std::atoi(date.c_str());
	std::string buffer = date.substr(date.find_first_not_of("0123456789") + 1);
	int month = std::atoi(buffer.c_str());
	buffer =  date.substr(date.find_first_not_of("0123456789", date.find_first_not_of("0123456789") + 1) + 1);
	int day = std::atoi(buffer.c_str());
	bool isLeapYear = false;

	// std::cout << "Year: " << year << " Month: " << month << " Day: " << day << std::endl;
	if (year <= 0 || month <= 0 || day <= 0 || month > 12 || day > 31)
		return false;
	if ( ( ano % 4 == 0 && ano % 100 != 0 ) || ano % 400 == 0 )
	    isLeapYear = true;
	if ((month == 4 || month == 6 | month == 9 || month == 11) && day > 30)
		return false;
	if (month == 2 && isLeapYear && day > 29)
			return false;
	if (month == 2 && !isLeapYear && day > 28)
			return false;
	return (true);
}

int	isRightFormat(std::string line) {
	bool	dot = false;
	bool	number = false;
	int		i;
	double	test;

	if (line.length() < 14)
		return false;
	for (i = 0; i <= 12; i++)
	{
		if ((i == 4 || i == 7) && line[i] != '-')
			return 0;
		else if ((i == 10 || i == 12) && line[i] != ' ')
			return 0;
		else if ((i == 11) && line[i] != '|')
			return 0;
		else if (line[i] < '0' && line[i] > '9')
			return 0;
	}
	test = std::atof(line.substr(13).c_str());
	if (test < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return 1;
	}
	else if (test == 0 || test > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return 1;
	}
	for (i = 13; line[i] && ((line[i] >= '0' && line[i] <= '9') || line[i] == '.'); i++)
	{
		if (line[i] == '.')
		{
			if (dot)
				return 0;
			dot = true;
		}
		if (line[i] >= '0' && line[i] <= '9')
			number = true;
	}
	if (line[i] || !number)
		return 0;
	return 2;
}

void	btcExchange(std::ifstream &input_file, std::ifstream &database_file)
{	
	int	format;
	std::string buffer;
	std::string tmp_buff;
	const char *tmp;
	std::map<std::string, double> database;
	std::map<std::string, double>::iterator iter;

	std::getline(database_file, buffer);
	while (std::getline(database_file, buffer))
	{
		if (!check_csv(buffer))
		{
			std::cerr << "Error on csv file, line: " << buffer << std::endl;
			return ;
		}
		tmp_buff = buffer.substr(buffer.find(",") + 1);
		tmp = tmp_buff.c_str();
		// std::cout << "inserting: " << buffer.substr(0, 10) << " and " << tmp << std::endl;
		database.insert(std::make_pair(buffer.substr(0, 10), std::atof(tmp)));
	}
	std::getline(input, buffer);
	while (std::getline(input, buffer))
	{
		format = isRightFormat(buffer);
		if (!format)
			std::cout << "Error: bad input -> " << buffer << std::endl;
		else if (format == 1)
			;
		else if (!isValidDate(buffer/*.substr(0, 10)*/))
		{
			std::cout << "Error: invalid date -> " << buffer.substr(0, 10) << std::endl;
		}
		else
		{
			// std::cout << "testing for: " << buffer.substr(0, 10) << std::endl;
			iter = database.upper_bound(buffer.substr(0, 10));
			if (iter != database.begin())
			{
				iter--;
				std::cout << buffer.substr(0, 11) << "=>" << buffer.substr(12) \
				<< " = " << (iter)->second * std::atof(buffer.substr(13).c_str()) << std::endl;
				//<< " Using - Date = " << iter->first << " Value = " << iter->second << std::endl;
			}
			else
			{
				std::cerr << "Error: no matching or closest lower date -> " << buffer << std::endl;
			}
		}
	}
}
