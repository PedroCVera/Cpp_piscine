/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrovera <pedrovera@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:28:56 by pedrovera         #+#    #+#             */
/*   Updated: 2023/05/26 16:00:48 by pedrovera        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string &name, int grade) : _name(name)
{
	std::cout << "Bureaucrat has been created!" << _name << std::endl;
	if (grade <= 150 || grade >= 1)
	{
		_grade = grade;
	}
	else if (grade > 150)
	{
		std::cout << "Exception one, grade too low" << std::endl;
	}
	else if (grade < 1)
	{
		std::cout << "Exception two, grade too high" << std::endl;
	}
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const & copy) : _name(copy._name) , _grade(copy._grade)
{
	std::cout << "Bureaucrat has been copied!" << _name << std::endl;
	return ;
}
Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat " << _name << " has been destroyed." << std::endl;
	return ;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	if (this != other)
	{
		_name = other._name;
		_grade = other._grade;	
	}
	
}