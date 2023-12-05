/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:00:18 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/12/04 15:29:51 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Base.hpp>

int	main(void)
{
	Base *base = NULL;
	
	base = base->generate();
	base->identify(base);

	delete (base);

	base = base->generate();
	base->identify(*base);

	delete(base);
	return (1);
}