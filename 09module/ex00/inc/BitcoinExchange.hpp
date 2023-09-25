/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:39:21 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/09/25 15:42:43 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

class BitcoinExchange
{
	public:
			BitcoinExchange(void);
			BitcoinExchange(const BitcoinExchange &cpy);
			BitcoinExchange &operator=(const BitcoinExchange &other);
			~BitcoinExchange(void);
};

#endif