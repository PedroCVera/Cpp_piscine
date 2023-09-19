/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:17:52 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/09/19 14:49:03 by pcoimbra         ###   ########.fr       */
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
	else
		return (0);
	return (0);
}

#endif