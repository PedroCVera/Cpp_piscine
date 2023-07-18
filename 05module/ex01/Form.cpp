/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:02:32 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/07/18 15:54:13 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


Form::Form()
{
	std::cout << "Default Form has been created!" << std::endl;
	_exec_grade = 1;
	_sign = false;
	_sign_grade = 1;
}

Form::Form(Form const & copy) : _fname(copy._fname) , _sign_grade(copy._sign_grade) , _exec_grade(copy._exec_grade) , _sign(copy._sign)
{
	std::cout << "form has been copied!" << _fname << std::endl;
	return ;
}

Form::~Form(void)
{
	std::cout << "Form " << _fname << " has been destroyed." << std::endl;
	return ;
}

Form &Form::operator=(Form const &other)
{
	_sign_grade = other.getSignGrade();
	_exec_grade = other.getExecGrade();
	return (*this);
}

Form::Form(const std::string name, int sign_grade, int exec_grade) : _fname(name)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw Form::GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw Form::GradeTooLowException();
	_sign_grade = sign_grade;
	_exec_grade = exec_grade;
	std::cout << "Constructor with input " << _fname << "." << std::endl;
	return ;
}

//Exception Functions

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade Too High!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade Too Low!";
}

//Get stuff

std::string Form::getName() const
{
	return (this->_fname);
}

int	Form::getSignGrade() const
{
	return (this->_sign_grade);
}

int	Form::getExecGrade() const
{
	return (this->_exec_grade);
}

bool	Form::getSign() const
{
	return (this->_sign);
}

//Sign

void	Form::beSigned(Bureaucrat const &Bur)
{
	if (Bur.getGrade() <= this->getSignGrade())
		_sign = true;
	else
		throw Form::GradeTooLowException();
}

//operator overload

std::ostream &operator<<(std::ostream &out, const Form &f)
{
	out << "Name: " << f.getName() << std::endl << "Status: " << f.getSign() << std::endl <<
	"Required grade for signing: " << f.getSignGrade() << std::endl <<
	"Required grade for executing: " << f.getExecGrade();
	return out;
}