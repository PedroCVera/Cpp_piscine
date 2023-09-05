/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:57:24 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/09/05 14:34:47 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <fstream> 
# include "AForm.hpp"

class AForm;

class RobotomyRequestForm : public AForm
{
	private:
	
			std::string	_target;
	
	public:

	RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm const & copy);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
	~RobotomyRequestForm();

	RobotomyRequestForm(const std::string target);
	
	void	execute(Bureaucrat const & executor) const;
};

#endif