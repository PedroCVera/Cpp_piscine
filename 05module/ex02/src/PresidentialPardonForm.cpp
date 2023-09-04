/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:33:08 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/09/04 17:27:30 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"
#include <cstdlib>

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Form creation", 25, 5), _target("default")
{
	std::cout << "PresidentialPardonForm has called default constructor!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & copy) : AForm("Presidential Form creation", 25, 5), _target(copy._target)
{
	std::cout << "PresidentialPardonForm has called copy constructor!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("Presidential Form creation", 25, 5), _target(target)
{
	std::cout << "Presidential Form constructor was called for: " << target << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Shrubbery destructor." << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!getSign())
		throw AForm::NotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw AForm::GradeTooLowException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}