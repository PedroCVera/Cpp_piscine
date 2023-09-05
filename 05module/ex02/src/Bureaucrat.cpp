/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:41:45 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/09/05 17:04:07 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

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
	std::cout << "Constructor with input " << _name << "." << std::endl;
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
	std::cout << "decrement function." << std::endl;
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

const char *Bureaucrat::NotSignedException::what() const throw()
{
	return "Form is not signed yet.";
}

const char *Bureaucrat::AlreadySignedException::what() const throw()
{
	return "Form is already signed.";
}

// const char *Bureaucrat::TooLowToExecuteException::what() const throw()
// {
// 	return "Burecraut's grade is too low to execute this form.";
// }

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

//Form Sign

void	Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " GradeTooLowExceptionsigned " << form.getName() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cout << this->_name << " couldn't sign " << form.getName() 
		<< " because of " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " GradeTooLowExceptionsigned " << form.getName() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cout << this->_name << " couldn't sign " << form.getName() 
		<< " because of " << e.what() << std::endl;
	}	
}