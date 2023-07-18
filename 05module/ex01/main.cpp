/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:29:00 by pedrovera         #+#    #+#             */
/*   Updated: 2023/07/18 15:56:52 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <stdio.h>

int main()
{
	// Form with grade requirements out of bonds ===============================
	try
	{
		Form f1("f1", 0, 30);
//		Form f1("f1", 27, 172);
//		Form f1 ("f1", 0, 234);
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	// =========================================================================

	// Show Form attributes ====================================================
	Form f2("f2", 30, 30); // create form
	std::cout << std::endl;
	std::cout << f2 << std::endl;
	std::cout << std::endl;
	// =========================================================================

	// Bureaucrat without sufficient grade =====================================
	Bureaucrat b1("Senhor Burocrata", 75);
	std::cout << b1 << std::endl; // bureaucrat info
	b1.signForm(f2);
	std::cout << f2 << std::endl;
	std::cout << std::endl;
	// =========================================================================

	// Bureaucrat with sufficient grade ========================================
	Bureaucrat b2("Burocrata melhor", 30);
	std::cout << b2 << std::endl; // bureaucrat info
	b2.signForm(f2);
	std::cout << f2 << std::endl;
	std::cout << std::endl;
	// =========================================================================
}