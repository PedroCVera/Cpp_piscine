/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:15:34 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/09/06 14:54:59 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

class Aform;

class Intern
{
	public:
		Intern();
		Intern(Intern const & copy);
		Intern &operator=(Intern const &other);
		~Intern();

		AForm* makeForm(std::string form, std::string target);

		class FormDoesntExist : std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif
