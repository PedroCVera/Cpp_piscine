/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:01:33 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/09/04 16:40:52 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"

class AForm;

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

		
		void	signForm(AForm &form) const;

		void	executeForm(AForm const & form);

		//exceptions class (new concept)
		class	GradeTooHighException : std::exception
		{
			public:
				const char *what() const throw();
		};
		class	GradeTooLowException : std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif