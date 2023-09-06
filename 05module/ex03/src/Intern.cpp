/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:25:33 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/09/06 15:14:06 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

Intern::Intern()
{
	std::cout << "intern has been created." << std::endl;
}

Intern::Intern(Intern const & copy)
{
	(void)copy;
	std::cout << "intern has been created (copy)." << std::endl;
}

Intern &Intern::operator=(Intern const &other)
{
	(void)other;
	std::cout << "intern has been created (=)." << std::endl;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern has been deleted." << std::endl;
}

AForm* Intern::makeForm(std::string form, std::string target)
{
	int i = 0;
	std::string Map[3] = {"Shrubbery request", "Presidential request", "Robotomy request"};

	for (; i < 3; i++)
		if (Map[i] == form)
			break;
	switch (i)
	{
		case 0:
			return new ShrubberyCreationForm(target);
		case 1:
			return new PresidentialPardonForm(target);
		case 2:
			return new RobotomyRequestForm(target);
	}
	throw Intern::FormDoesntExist();
}

const char *Intern::FormDoesntExist::what() const throw()
{
	return "This name doesn't correspond with that of any form.";
}
