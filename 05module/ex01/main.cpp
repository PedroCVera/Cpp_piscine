/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:29:00 by pedrovera         #+#    #+#             */
/*   Updated: 2023/07/11 14:02:07 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	// GRADE TOO HIGH ON CONSTRUCTOR ===========================================
	try
	{
		Bureaucrat Francisco("Francisco", 0);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	// GRADE TOO LOW ON CONSTRUCTOR ============================================
	try
	{
		Bureaucrat Lourenco("Lourenco", 151);
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	// Incrementing when at max grade ==========================================
	try
	{
		Bureaucrat Eugene("Eugene", 1);
		std::cout << Eugene;
		Eugene.incrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	// Decrementing when at min grade ==========================================
	try
	{
		Bureaucrat Antonio("Antonio", 150);
		std::cout << Antonio;
		Antonio.decrementGrade();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	// Normal behavior =========================================================
	try
	{
		Bureaucrat Eu("Eu", 9);
		std::cout << Eu;
		Eu.incrementGrade();
		std::cout << Eu;
		Eu.decrementGrade();
		std::cout << Eu;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}