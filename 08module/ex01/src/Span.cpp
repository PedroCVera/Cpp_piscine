/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:48:30 by pcoimbra          #+#    #+#             */
/*   Updated: 2024/01/09 16:10:58 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Span.hpp>

Span::Span() : _N(0)
{
	std::cout << "Default constructor was called, the range is 0." << std::endl;
}

Span::Span(Span const &other) : _N(other._N)
{
	std::cout << "copy constructor called." << std::endl;
	if (_vector != other._vector)
	{
		_vector.clear();
		for (unsigned int i = 0; i < other._vector.size(); i++)
			_vector.push_back(other._vector[i]);
	}
}

Span&	Span::operator=(Span const &cpy)
{
	_N = cpy._N;
	std::cout << "= constructor called." << std::endl;
	if (_vector != cpy._vector)
	{
		_vector.clear();
		for (unsigned int i = 0; i < cpy._vector.size(); i++)
			_vector.push_back(cpy._vector[i]);
	}
	return *this;
}

Span::~Span()
{
	std::cout << "Destructor called." << std::endl;
}

Span::Span(unsigned int N) : _N(N)
{
	std::cout << "constructor was called, the range is " << _N << "." << std::endl;
}

void	Span::addNumber(int n)
{
	if (_vector.size() + 1 > _N)
		throw LimitArrayException();
	else
		_vector.push_back(n);
}

int	Span::shortestSpan()
{
	if (_vector.empty() || _vector.size() == 1)
		throw ArrayEmptyOrTooShort();
	int	diff = _vector[0] - _vector[1];
	if (diff < 0)
		diff = diff * -1;
	int	temp;	

	for (unsigned int j = 0; j < _vector.size(); j++)
	{
		for (unsigned int i = j + 1; i < _vector.size(); i++)
		{
			if(_vector[i] - _vector[j] < 0)
				temp = (_vector[i] - _vector[j]) * -1;
			else
				temp = _vector[i] - _vector[j];
			if (temp < diff)
				diff = temp;
		}
	}
	return (diff);
}

int	Span::longestSpan()
{
	if (_vector.empty() || _vector.size() == 1)
		throw ArrayEmptyOrTooShort();
	int	diff = _vector[0] - _vector[1];
	if (diff < 0)
		diff = diff * -1;
	int	temp;	

	for (unsigned int j = 0; j < _vector.size(); j++)
	{
		for (unsigned int i = j + 1; i < _vector.size(); i++)
		{
			if(_vector[i] - _vector[j] < 0)
				temp = (_vector[i] - _vector[j]) * -1;
			else
				temp = _vector[i] - _vector[j];
			if (temp > diff)
				diff = temp;
		}
	}
	return (diff);
}

std::vector<int>	Span::getVector()
{
	return (_vector);
}

void	Span::addListNumber(unsigned int n)
{
	if (n > _N)
		throw LimitArrayException();
	int	randomValue;
	srand(time(NULL));
	unsigned int	amount = n;
	while (amount > 0)
	{
		randomValue = rand();
		randomValue = randomValue % 50;
		addNumber(randomValue);
		amount--;
	}
}

const char	*Span::LimitArrayException::what() const throw () {
	return "\e[0;31mLimit of numbers in array excedded \e[0m";
}

const char	*Span::ArrayEmptyOrTooShort::what() const throw () {
	return "\e[0;31mThe vector is empty or too short cannot calculate Span \e[0m";
}