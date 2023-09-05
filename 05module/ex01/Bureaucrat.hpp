/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:31:25 by pedrovera         #+#    #+#             */
/*   Updated: 2023/09/05 14:54:04 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
	
	const std::string	_name;
	int					_grade;
	
	public:
		Bureaucrat();
		Bureaucrat(Bureaucrat const & copy);
		Bureaucrat &operator=(Bureaucrat const &other);
		~Bureaucrat();

		Bureaucrat(const std::string name, int grade);

		std::string	getName() const;
		int			getGrade() const;

		void	incrementGrade();
		void	decrementGrade();

		
		void	signForm(Form &form) const;

		//exceptions class (new concept)
		class	GradeTooHighException : std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class	GradeTooLowException : std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif