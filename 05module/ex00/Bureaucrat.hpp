/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:31:25 by pedrovera         #+#    #+#             */
/*   Updated: 2023/07/11 13:34:43 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

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