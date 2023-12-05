/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:37:03 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/12/05 13:01:11 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"

Base::~Base()
{
}

Base*	Base::generate(void)
{
	Base *base;
	srand(time(NULL));
	int	i = rand() % 3;

	switch (i)
	{
		case 1:
			base = new A;
			break ;
		case 2:
			base = new B;
			break ;
		default:
			base = new C;
	}
	return base;
}

void	Base::identify(Base *p)
{
	A* a;
	B* b;
	C* c;
	
	a = dynamic_cast<A*>(p);
	b = dynamic_cast<B*>(p);
	c = dynamic_cast<C*>(p);
	
	if (a)
		std::cout << "A" << std::endl;
	else if (b)
		std::cout << "B" << std::endl;
	else if (c)
		std::cout << "C" << std::endl;
		
	return ;
}

void	Base::identify(Base &p)
{
	try
	{
		A a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (const std::exception &e)
	{

		//std::cout << e.what() << std::endl;
	}

	try
	{
		B b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (const std::exception &e)
	{

		//std::cout << e.what() << std::endl;
	}
	
	try
	{
		C c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (const std::exception &e)
	{

		//std::cout << e.what() << std::endl;
	}
	
	return ;
}