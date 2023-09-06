/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:00:33 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/09/04 12:01:53 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class AForm {
private:
    const std::string   _fname;
    int                 _sign_grade;
    int                 _exec_grade;
    bool                _sign;

public:
    AForm();
    AForm(AForm const & copy);
    AForm &operator=(AForm const &other);
    virtual ~AForm(); // Make the destructor virtual

    AForm(const std::string name, int sign_grade, int exec_grade);

    std::string getName() const;
    int         getSignGrade() const;
    int         getExecGrade() const;
    bool        getSign() const;

    void beSigned(Bureaucrat const &Bur);
    virtual void 	execute(Bureaucrat const &executor)const = 0;

    class GradeTooHighException : std::exception 
    {
        public:
            virtual const char *what(void) const throw();
    };
    class GradeTooLowException : std::exception
    {
        public:
            virtual const char *what(void) const throw();
    };
    class NotSignedException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class AlreadySignedException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	// class TooLowToExecuteException : public std::exception
	// {
	// 	public:
	// 		virtual const char* what() const throw();
	// };
};

std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif