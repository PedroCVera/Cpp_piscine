/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:07:50 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/09/04 17:32:19 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream> 

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery creation", 145, 137), _target("default")
{
	std::cout << "ShrubberyCreationForm has called default constructor!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & copy) : AForm("Shrubbery creation", 145, 137), _target(copy._target)
{
	std::cout << "ShrubberyCreationForm has called copy constructor!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("Shrubbery creation", 145, 137), _target(target)
{
	std::cout << "Shrubbery constructor was called for: " << target << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery destructor." << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!getSign())
		throw AForm::NotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw AForm::GradeTooLowException();
	std::ofstream Myfile(_target);
	Myfile << "       	   _-_               _-_\n    /~~   ~~\         /~~   ~~\\n /~~         ~~\   /~~         ~~\\n{               } {               }\n \  _-     -_  /   \  _-     -_  /\n   ~  \\ //  ~       ~  \\ //  ~\n_- -   | | _- _   _- -   | | _- _\n  _ -  | |   -_     _ -  | |   -_\n      // \\	            // \\ \n";
	Myfile.close();
}