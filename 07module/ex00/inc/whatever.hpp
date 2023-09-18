/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:31:35 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/09/18 12:57:17 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <stdint.h>
# include <iostream>

template<typename T>

void	swap(T &A, T &B)
{
	T	temp = A;
	A = B;
	B = temp;
}

template<typename T>

T min(T A, T B)
{
	if (A > B)
		return (B);
	else if (B > A)
		return (A);
	else
		return (B);
}

template<typename T>

T max(T A, T B)
{
	if (A > B)
		return (A);
	else if (B > A)
		return (B);
	else
		return (B);
}


#endif