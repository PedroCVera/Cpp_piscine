/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:54:14 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/09/11 16:21:50 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Intern.hpp"

int main()
{
	// SHRUBBERY CREATION FORM =================================================
	AForm* scf = NULL;
	try
	{
		Intern someRandomIntern;
		scf = someRandomIntern.makeForm(" request", "home");

		Bureaucrat b1("jardineiro", 137);
		b1.signForm(*scf);
		b1.executeForm(*scf);
		delete scf;
	}
	// catch (std::exception &e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	catch (Intern::FormDoesntExist &e)
	{
		std::cout << "Failed because: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
		delete scf;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
		delete scf;
	}
	catch (AForm::NotSignedException &e)
	{
		std::cout << e.what() << std::endl;
		delete scf;
	}
	// =========================================================================

	// ROBOTOMY REQUEST FORM ===================================================
	std::cout << std::endl;
	AForm* rrf;
	try
	{
		Intern someRandomIntern;
		rrf = someRandomIntern.makeForm("Robotomy request", "Bender");

		Bureaucrat b1("DoctorRobotomizer", 45);
		b1.signForm(*rrf);
		b1.executeForm(*rrf);
		delete rrf;
	}
	// catch (std::exception &e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	catch (Intern::FormDoesntExist  &e)
	{
		std::cout << "Failed because: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
		delete rrf;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
		delete rrf;
	}
	// =========================================================================

	// PRESIDENTIAL PARDON FORM ================================================
	std::cout << std::endl;
	AForm* ppf;
	try
	{
		Intern someRandomIntern;
		ppf = someRandomIntern.makeForm("Presidential request", "condemned");

		Bureaucrat b1("Presidente", 5);
		b1.signForm(*ppf);
		b1.executeForm(*ppf);
		delete ppf;
	}
	// catch (std::exception &e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	catch (Intern::FormDoesntExist  &e)
	{
		std::cout << "Failed because: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
		delete ppf;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
		delete ppf;
	}
	// =========================================================================

	// WRONG FORM ==============================================================
	std::cout << std::endl;
	AForm* wrong;
	try
	{
		Intern someRandomIntern;
		wrong = someRandomIntern.makeForm("wrong", "doesn't really matter");

		Bureaucrat b1("burocrata", 1);
		b1.signForm(*wrong);
		b1.executeForm(*wrong);
		delete wrong;
	}
	// catch (std::exception &e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	catch (Intern::FormDoesntExist  &e)
	{
		std::cout << "Failed because: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
		delete wrong;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
		delete wrong;
	}
	// =========================================================================
}