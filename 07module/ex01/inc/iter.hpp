/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:40:07 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/12/05 14:51:30 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <stdint.h>
# include <iostream>

template <typename T>

void	iter(T *arr, int len, void (*func)(T const &))
{
	for (int i = 0; i < len; i++)
		func(arr[i]);
}

template <typename T>

void customFunction(const T& element)
{
    std::cout << element << std::endl;
}

#endif