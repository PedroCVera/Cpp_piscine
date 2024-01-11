/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:17:52 by pcoimbra          #+#    #+#             */
/*   Updated: 2024/01/09 16:04:52 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <algorithm>

template<typename T>

int	easyfind(T &cont, int needle)
{
	typename T::iterator Temp = std::find(cont.begin(), cont.end(), needle);

	if (Temp != cont.end())
		return (1);
	return (0);
}

#endif