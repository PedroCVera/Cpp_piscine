/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:55:19 by pcoimbra          #+#    #+#             */
/*   Updated: 2024/01/16 12:44:03 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PMergeMe.hpp"

PmergeMe::PmergeMe()
{
	std::cout << "Constructor noises" << std::endl;
}

PmergeMe::~PmergeMe()
{
	std::cout << "Destructor noises" << std::endl;
}

PmergeMe::PmergeMe(PmergeMe const &copy)
{
	l_start = copy.l_start;
	l_end = copy.l_end;
	d_start = copy.d_start;
	d_end = copy.d_end;
	
	std::cout << "Cpy constructor called" << std::endl;
}

PmergeMe &PmergeMe::operator=(PmergeMe const & copy)
{
	l_start = copy.l_start;
	l_end = copy.l_end;
	d_start = copy.d_start;
	d_end = copy.d_end;
	return (*this);
}

int l_findPair(int value, std::list<std::pair<int, int> > &pair_lst)
{
	int	result;
	
	for (std::list<std::pair<int, int> >::iterator it = pair_lst.begin(); it != pair_lst.end(); it++)
	{
		result = (value == it->first) ? it->second : (value == it->second) ? it->first : -2;
		if (result != -2)
			return (result);
	}
	return (result);
}

void PmergeMe::l_printList(std::list<int> listinha)
{
	std::list<int>::iterator ite = listinha.begin();
	for (; ite != listinha.end(); ite++)
		std::cout << *ite << " ";
	std::cout << " " << std::endl;
}


void PmergeMe::l_printList(void)
{
	std::list<int>::iterator ite = _lis.begin();
	for (; ite != _lis.end(); ite++)
		std::cout << *ite << " ";
	std::cout << " " << std::endl;
}

void PmergeMe::l_Divide(void)
{
	std::list<std::pair<int, int> > pair_lst;
	int	st, nd;
	l_start = clock();
	std::list<int>::iterator ite = _lis.begin();
	while (ite != _lis.end())
	{
		st = *(ite++);
		if (std::distance(ite, _lis.end()) > 0)
		{
			nd = *(ite++);
			pair_lst.push_back(std::make_pair(st, nd));
		}
		else
			pair_lst.push_back(std::make_pair(st, -1));    
	}
	l_Swap(pair_lst);
}

void PmergeMe::l_Swap(std::list<std::pair<int, int> >& pair_lst)
{
	for (std::list<std::pair<int, int> >::iterator ite = pair_lst.begin(); ite != pair_lst.end(); ite++)
		(ite->first > ite->second ? std::swap(ite->first, ite->second) : void());
	l_insertMain(pair_lst);
}

void PmergeMe::l_insertMain(std::list<std::pair<int, int> >& pair_lst)
{
	std::list<int> main;
	
	main.push_back(pair_lst.begin()->second);
	for (std::list<std::pair<int,int> >::iterator pair_it = ++pair_lst.begin(); pair_it != pair_lst.end(); pair_it++)
	{
		std::list<int>::iterator main_it = main.begin();
		while (main_it != main.end())
		{
			if (pair_it->second < *main_it)
			{
				main.insert(main_it, pair_it->second);
				break ;
			}
			else
				main_it++;
		}
		if (main_it == main.end())
			main.push_back(pair_it->second);     
	}
	l_insertPend(pair_lst, main);
}

void PmergeMe::l_insertPend(std::list<std::pair<int, int> >& pair_lst, std::list<int>& main)
{
	int	pair;
	for (std::list<std::pair<int,int> >::iterator pair_it = pair_lst.begin(); pair_it != pair_lst.end(); pair_it++)
	{
		pair = l_findPair(pair_it->first, pair_lst);
		std::list<int>::iterator main_it = main.begin();
		while (*main_it != pair && *main_it < pair_it->first)
			main_it++;
		if (pair_it->first != -1)
			main.insert(main_it, pair_it->first);
	}
	l_end = clock();
	std::cout << "After: ";
	l_printList(main);
}

int	PmergeMe::CheckRepeat(void)
{
	std::list<int>::iterator ite = _lis.begin();
	std::list<int>::iterator it;

	for (; ite != _lis.end(); ite++)
	{
		it = _lis.begin();
		while (it != ite)
			it++;
		it++;
		for (; it != _lis.end(); it++)
			if (*it == *ite)
			{
				std::cout << "Problem was in number: " << *ite << std::endl;
				return 0;
			}
	}
	return 1;
}

int	ft_atoi(char *str)
{
	int ret = 0;
	int j = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '+' && i == 0)
			j++;
		else if (str[i] > '9' || str[i] < '0')
			return -1;
	}
	while (str[j] != '\0')
	{
		ret = ret * 10 + (str[j] - '0');
		j++;
	}
	return ret;
}

int PmergeMe::Parse(int ac, char **av)
{
	for (unsigned int i = 1; i < (unsigned int)ac; i++)
	{
		int test = ft_atoi(av[i]);
		
		if (test == -1)
		{
			std::cout << "Error: the argument n." << i << " wasn't valid." << std::endl;
			return (-1);
		}
		_lis.push_back(test);
		_deq.push_back(test);
		std::cout << "n:" << test << std::endl;
	}
	if (CheckRepeat() == 0)
	{
		std::cout << "Error: there are repeated arguments." << std::endl;
		return (-1);
	}
	std::cout << "Before: ";
	l_printList();
	l_Divide();
	// std::cout << "Before: ";
	// d_printList();
	d_Divide();
	return 1;
}

int	d_findPair(int value, std::deque<std::pair<int, int> > &pair_lst)
{
	int	result;
	
	for (std::deque<std::pair<int, int> >::iterator it = pair_lst.begin(); it != pair_lst.end(); it++)
	{
		result = (value == it->first) ? it->second : (value == it->second) ? it->first : -2;
		if (result != -2)
			return (result);
	}
	return (result);
}

void PmergeMe::d_printList(void)
{
	std::deque<int>::iterator ite = _deq.begin();
	for (; ite != _deq.end(); ite++)
		std::cout << *ite << " ";
	std::cout << " " << std::endl;
}


void PmergeMe::d_printList(std::deque<int> dequezinho)
{
	std::deque<int>::iterator ite = dequezinho.begin();
	for (; ite != dequezinho.end(); ite++)
		std::cout << *ite << " ";
	std::cout << " " << std::endl;
}


void PmergeMe::d_Divide(void)
{
	std::deque<std::pair<int, int> > pair_deq;
	int	st, nd;
	d_start = clock();
	std::deque<int>::iterator ite = _deq.begin();
	while (ite != _deq.end())
	{
		st = *(ite++);
		if (std::distance(ite, _deq.end()) > 0)
		{
			nd = *(ite++);
			pair_deq.push_back(std::make_pair(st, nd));
		}
		else
			pair_deq.push_back(std::make_pair(st, -1));    
	}
	d_Swap(pair_deq);
}

void PmergeMe::d_Swap(std::deque<std::pair<int, int> >& pair_deq)
{
	for (std::deque<std::pair<int, int> >::iterator ite = pair_deq.begin(); ite != pair_deq.end(); ite++)
		(ite->first > ite->second ? std::swap(ite->first, ite->second) : void());
	d_insertMain(pair_deq);
}

void PmergeMe::d_insertMain(std::deque<std::pair<int, int> >& pair_deq)
{
	std::deque<int> main;
	
	main.push_back(pair_deq.begin()->second);
	for (std::deque<std::pair<int,int> >::iterator pair_it = ++pair_deq.begin(); pair_it != pair_deq.end(); pair_it++)
	{
		std::deque<int>::iterator main_it = main.begin();
		while (main_it != main.end())
		{
			if (pair_it->second < *main_it)
			{
				main.insert(main_it, pair_it->second);
				break ;
			}
			else
				main_it++;
		}
		if (main_it == main.end())
			main.push_back(pair_it->second);     
	}
	d_insertPend(pair_deq, main);
}

void PmergeMe::d_insertPend(std::deque<std::pair<int, int> >& pair_deq, std::deque<int>& main)
{
	int	pair;
	
	for (std::deque<std::pair<int,int> >::iterator pair_it = pair_deq.begin(); pair_it != pair_deq.end(); pair_it++)
	{
		pair = d_findPair(pair_it->first, pair_deq);
		std::deque<int>::iterator main_it = main.begin();
		while (*main_it != pair && *main_it < pair_it->first)
			main_it++;
		if (pair_it->first != -1)
			main.insert(main_it, pair_it->first);
	}
	l_end = clock();
	std::cout << "After: ";
	d_printList(main);
}