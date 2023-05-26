/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrovera <pedrovera@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:31:25 by pedrovera         #+#    #+#             */
/*   Updated: 2023/05/26 15:47:34 by pedrovera        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat
{
	private:
	
	std::string	_name;
	int			_grade;
	
	public:
		Bureaucrat(std::string &name, int grade);
		Bureaucrat(Bureaucrat const & copy);
		Bureaucrat &operator=(Bureaucrat const &other);
		~Bureaucrat();
};

#endif