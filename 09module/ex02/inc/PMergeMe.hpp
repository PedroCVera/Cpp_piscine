/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:52:10 by pcoimbra          #+#    #+#             */
/*   Updated: 2024/01/15 17:03:29 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

# include <string>
# include <iostream>
# include <list>
# include <sstream>
# include <iterator>
# include <deque>
# include <ctime>

class PmergeMe
{
	private:
		clock_t 		l_start;
		clock_t 		l_end;
		std::list<int>	_lis;
		
		clock_t 		d_start;
		clock_t 		d_end;
    	std::deque<int>	_deq;
	
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(PmergeMe const &copy);
		PmergeMe&operator=(PmergeMe const &copy);
		
		int Parse(int ac, char **av);
		int	CheckRepeat(void);
		
		void	l_Divide(void);
		void	l_Swap(std::list<std::pair<int, int> >& pair_lst);
		void	l_insertMain(std::list<std::pair<int, int> >& pair_lst);
		void	l_insertPend(std::list<std::pair<int, int> >& pair_lst, std::list<int>& main);
		void	l_printList(void);
		void	l_printList(std::list<int>);
		// void l_printPairs(std::list<std::pair<int, int> > pair_lst);
		

		void	d_Divide(void);
		void	d_Swap(std::deque<std::pair<int, int> >& pair_lst);
		void	d_insertMain(std::deque<std::pair<int, int> >& pair_lst);
		void	d_insertPend(std::deque<std::pair<int, int> >& pair_lst, std::deque<int>& main);
		void	d_printList(std::deque<int> lst);
		void	d_printList(void);
		
		// void d_printPairs(std::deque<std::pair<int, int> > pair_lst);
};

#endif