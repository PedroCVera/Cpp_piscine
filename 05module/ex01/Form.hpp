/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:02:48 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/07/14 16:22:36 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Form
{
	private:
		const std::string	_fname;
		int					_sign_grade;
		int					_exec_grade;
		bool				_sign;

	public:
		Form();
		Form(Form const & copy);
		Form &operator=(Form const &other);
		~Form();

		Form(const std::string name, int sign_grade, int exec_grade);

		std::string getName() const;
		int			getSignGrade() const;
		int			getExecGrade() const;
		bool		getSign() const;

		void		beSigned(Bureaucrat const &Bur);
		
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