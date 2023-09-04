/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:57:25 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/09/04 16:39:40 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream> 
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
	
			std::string	_target;
	
	public:

	ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm const & copy);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
	~ShrubberyCreationForm();

	ShrubberyCreationForm(const std::string target);

	
	void	execute(Bureaucrat const & executor) const;
};

#endif