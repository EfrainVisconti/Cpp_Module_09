/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:43:04 by codespace         #+#    #+#             */
/*   Updated: 2024/12/04 17:08:33 by eviscont         ###   ########.fr       */
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
#include <ctime>

class BitcoinExchange
{
	private:
	double	_auxValue;
	int	_auxCurrentDate[3];

	/* Private methods */
	void processLine(const std::string &line);
	void processValidLine(const std::string &line);
	void processValue(const std::string &strValue);
	void processDate(const std::string &date);
	bool isValidDate(const std::string &date);
	void currentDate();

	public:
	std::map<std::string, double>	data;

	/* Orthodox canonical form */
	BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
	~BitcoinExchange();
    BitcoinExchange	&operator=(const BitcoinExchange &other);

	/* Other public methods */
	void	loadData(const std::string &file);
	void	processInfile(const std::string &file);

	/* Debugger methods */
	void	printData() const;

	/* Exception */
	class InvalidFileException : public std::exception
	{
		public:
			char const *what() const throw();
	};
};

#endif
