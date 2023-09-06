/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:45:22 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/09/04 16:46:09 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/AForm.hpp"

AForm::AForm()
{
	std::cout << "Default AForm has been created!" << std::endl;
	_exec_grade = 1;
	_sign = false;
	_sign_grade = 1;
}

AForm::AForm(AForm const & copy) : _fname(copy._fname) , _sign_grade(copy._sign_grade) , _exec_grade(copy._exec_grade) , _sign(copy._sign)
{
	std::cout << "AForm has been copied!" << _fname << std::endl;
	return ;
}

AForm::~AForm(void)
{
	std::cout << "AForm " << _fname << " has been destroyed." << std::endl;
	return ;
}

AForm &AForm::operator=(AForm const &other)
{
	_sign_grade = other.getSignGrade();
	_exec_grade = other.getExecGrade();
	return (*this);
}

AForm::AForm(const std::string name, int sign_grade, int exec_grade) : _fname(name)
{
	if (sign_grade < 1 || exec_grade < 1)
		throw AForm::GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw AForm::GradeTooLowException();
	_sign_grade = sign_grade;
	_exec_grade = exec_grade;
	_sign = false;
	std::cout << "Constructor with input " << _fname << "." << std::endl;
	return ;
}

//Exception Functions

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade Too High!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade Too Low!";
}

const char *AForm::NotSignedException::what() const throw()
{
	return "Form is not signed yet.";
}

const char *AForm::AlreadySignedException::what() const throw()
{
	return "Form is already signed.";
}

// const char *AForm::TooLowToExecuteException::what() const throw()
// {
// 	return "Burecraut's grade is too low to execute this form.";
// }

//Get stuff

std::string AForm::getName() const
{
	return (this->_fname);
}

int	AForm::getSignGrade() const
{
	return (this->_sign_grade);
}

int	AForm::getExecGrade() const
{
	return (this->_exec_grade);
}

bool	AForm::getSign() const
{
	return (this->_sign);
}

//Sign

void	AForm::beSigned(Bureaucrat const &Bur)
{
	if (Bur.getGrade() <= this->getSignGrade())
		_sign = true;
	else
		throw AForm::GradeTooLowException();
}

//operator overload

std::ostream &operator<<(std::ostream &out, const AForm &f)
{
	out << "Name: " << f.getName() << std::endl << "Status: " << f.getSign() << std::endl <<
	"Required grade for signing: " << f.getSignGrade() << std::endl <<
	"Required grade for executing: " << f.getExecGrade() << std::endl;
	return out;
}