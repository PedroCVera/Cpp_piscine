/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:46:45 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/09/05 17:05:09 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

int main(void)
{
	{
		try{
			std::cout << "\e[1;35m===========Constructing===========\033[0m" << std::endl;
			Bureaucrat exec("Bexec", 145);
			Bureaucrat signer("Bsigner", 145);
			ShrubberyCreationForm A("ze manel");
			std::cout << "\e[1;35m===========Testing===========\033[0m" << std::endl;
			std::cout << A;
			exec.decrementGrade();
			signer.decrementGrade();
			A.beSigned(signer);
			std::cout << A;
			A.execute(exec);
			std::cout << "\e[1;35m===========Destructing===========\033[0m" << std::endl;
		}
		catch (AForm::GradeTooLowException &e) {
			std::cout << e.what() << std::endl;
		}
		catch (AForm::GradeTooHighException &e) {
			std::cout << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e) {
			std::cout << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException &e) {
			std::cout << e.what() << std::endl;
		}
		catch (AForm::AlreadySignedException &e) {
			std::cout << e.what() << std::endl;
		}
		catch (AForm::NotSignedException &e) {
			std::cout << e.what() << std::endl;
		}
		catch (Bureaucrat::AlreadySignedException &e) {
			std::cout << e.what() << std::endl;
		}
		catch (Bureaucrat::NotSignedException &e) {
			std::cout << e.what() << std::endl;
		}

	}
	{
		try{
			std::cout << "\e[1;35m===========Constructing===========\033[0m" << std::endl;
			Bureaucrat exec("execer", 45);
			Bureaucrat signer("signer", 72);
			RobotomyRequestForm A("roboto");
			std::cout << "\e[1;35m===========Testing===========\033[0m" << std::endl;
			std::cout << A;
			A.beSigned(signer);
			std::cout << A;
			A.execute(exec);
			std::cout << "\e[1;35m===========Destructing===========\033[0m" << std::endl;
		}
		catch (AForm::GradeTooLowException &e) {
			std::cout << e.what() << std::endl;
		}
		catch (AForm::GradeTooHighException &e) {
			std::cout << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e) {
			std::cout << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException &e) {
			std::cout << e.what() << std::endl;
		}
		catch (AForm::AlreadySignedException &e) {
			std::cout << e.what() << std::endl;
		}
		catch (AForm::NotSignedException &e) {
			std::cout << e.what() << std::endl;
		}
		catch (Bureaucrat::AlreadySignedException &e) {
			std::cout << e.what() << std::endl;
		}
		catch (Bureaucrat::NotSignedException &e) {
			std::cout << e.what() << std::endl;
		}
		
	}
	{
		try{
			std::cout << "\e[1;35m===========Constructing===========\033[0m" << std::endl;
			Bureaucrat exec("execer", 6);
			Bureaucrat signer("signer", 4);
			PresidentialPardonForm A("roboto");
			std::cout << "\e[1;35m===========Testing===========\033[0m" << std::endl;
			std::cout << A;
			//A.beSigned(signer);
			//std::cout << A;
			exec.signForm(A);
			exec.incrementGrade();
			exec.executeForm(A);
			//A.execute(exec);
			std::cout << "\e[1;35m===========Destructing===========\033[0m" << std::endl;
		}
		catch (AForm::GradeTooLowException &e) {
			std::cout << e.what() << std::endl;
		}
		catch (AForm::GradeTooHighException &e) {
			std::cout << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e) {
			std::cout << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException &e) {
			std::cout << e.what() << std::endl;
		}
		catch (AForm::AlreadySignedException &e) {
			std::cout << e.what() << std::endl;
		}
		catch (AForm::NotSignedException &e) {
			std::cout << e.what() << std::endl;
		}
		catch (Bureaucrat::AlreadySignedException &e) {
			std::cout << e.what() << std::endl;
		}
		catch (Bureaucrat::NotSignedException &e) {
			std::cout << e.what() << std::endl;
		}	
	}

}