/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:28:56 by pedrovera         #+#    #+#             */
/*   Updated: 2023/07/11 14:02:11 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "Default bureaucrat has been created!" << "Default" << std::endl;
	_grade = 1;
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
	_grade = other.getGrade();
	return (*this);
}

//start with name and grade

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
	std::cout << "Constructor with input." << std::endl;
}

//increment / decrement

void	Bureaucrat::incrementGrade()
{
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
	std::cout << "Increment function." << std::endl;
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
	std::cout << "Increment function." << std::endl;
}

//Error handlers from try

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade Too High!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade Too Low!";
}

//Getters

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int	Bureaucrat::getGrade() const
{
	return this->_grade;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << "'s grade is: " << bureaucrat.getGrade() << "." << std::endl;
	return out;
}