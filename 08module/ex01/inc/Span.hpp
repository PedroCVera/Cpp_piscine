/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:48:29 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/09/19 16:25:50 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>

class	Span
{
	private:
			std::vector<int>	_vector;
			unsigned int		_N;

	public:
			Span();
			Span(Span const &other);
			Span &operator=(Span const &cpy);
			~Span();
			Span(unsigned int N);

			
			void				addNumber(int n);
			void				addListNumber(unsigned int n);
			int					shortestSpan();
			int					longestSpan();
			std::vector<int>	getVector();

		class ArrayEmptyOrTooShort : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class LimitArrayException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif