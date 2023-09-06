/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:15:28 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/09/04 17:27:25 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy creation", 72, 45), _target("default")
{
	std::cout << "RobotomyRequestForm has called default constructor!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & copy) : AForm("Robotomy creation", 72, 45), _target(copy._target)
{
	std::cout << "RobotomyRequestForm has called copy constructor!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("Robotomy creation", 72, 45), _target(target)
{
	std::cout << "Robotomy constructor was called for: " << target << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Shrubbery destructor." << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!getSign())
		throw AForm::NotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw AForm::GradeTooLowException();
	std::cout << "Drilling noises..." << std::endl;
	int	ind = (rand() % 2);
	if (ind == 1)
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy has failed..." << std::endl;
}