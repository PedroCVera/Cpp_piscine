/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:57:21 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/09/05 14:34:58 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <fstream> 
# include "AForm.hpp"

class AForm;

class PresidentialPardonForm : public AForm
{
	private:
	
			std::string	_target;
	
	public:

	PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm const & copy);
	PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
	~PresidentialPardonForm();

	PresidentialPardonForm(const std::string target);
	
	void	execute(Bureaucrat const & executor) const;
};

#endif