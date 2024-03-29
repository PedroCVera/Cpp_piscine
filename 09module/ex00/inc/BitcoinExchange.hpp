/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:39:21 by pcoimbra          #+#    #+#             */
/*   Updated: 2024/01/08 12:38:40 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <limits>
#include <cstdlib>
#include <ctype.h>
#include <map>

#define BITC_DATABASE "data.csv"

bool	isValidDate(std::string date);
void	btcExchange(std::ifstream &input, std::ifstream &database_file);

#endif
