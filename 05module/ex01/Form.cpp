/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:02:32 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/07/14 16:31:51 by pcoimbra         ###   ########.fr       */
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
	_grade = other.getGrade();
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