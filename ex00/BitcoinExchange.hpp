/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:43:04 by codespace         #+#    #+#             */
/*   Updated: 2024/12/03 17:15:55 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <map>
#include <iomanip>
#include <exception>

class BitcoinExchange
{
	public:
	std::map<std::string, double>	data;

	/* Orthodox canonical form */
	BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
	~BitcoinExchange();
    BitcoinExchange	&operator=(const BitcoinExchange &other);

	/* Other methods */
	void	loadData(const std::string &file);
	void	processInfile(const std::string &file);

	/* Debugger methods */
	void	printData() const;

	class InvalidFileException : public std::exception
	{
		public:
			char const *what() const throw();
	};
};

#endif
