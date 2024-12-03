/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:42:39 by codespace         #+#    #+#             */
/*   Updated: 2024/12/03 17:57:57 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static const std::string inputHeader = "date | value";

/* Orthodox canonical form */
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange  &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		data = other.data;
    return *this;
}

/* Other methods */
void	BitcoinExchange::loadData(const std::string &file)
{
	std::ifstream infile(file.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Error opening Database" << std::endl;
		return ;
	}

	std::string line;
	std::string date;
	double value;
	std::getline(infile, line);
	while (std::getline(infile, line))
	{
		date = line.substr(0, 10);
		value = std::atof(line.substr(11).c_str());
		data[date] = value;
	}
}

static void	processLine(const std::string &line)
{
	if (line.empty())
		return ;
	if (line.size() < 14 || )
	//else
	//	throw BitcoinExchange::InvalidFileException();
}

void	BitcoinExchange::processInfile(const std::string &file)
{
	std::ifstream infile(file.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Error opening input file" << std::endl;
		return ;
	}

	std::string line;
	std::getline(infile, line);
	if (line != inputHeader)
	{
		std::cerr << "Error: input file needs a header." << std::endl;
		std::cerr << "Valid header: " << inputHeader << std::endl;
		return ;
	}
	while (std::getline(infile, line))
	{
		try
		{
			processLine(line);
		}
		catch (const InvalidFileException& e)
		{
			std::cerr << e.what() << std::endl;
			return ;
		}
		catch (const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
}

/* Debugger methods */
void	BitcoinExchange::printData() const
{
	std::map<std::string, double>::const_iterator it;
	for (it = data.begin(); it != data.end(); ++it)
    	std::cout << it->first <<  "," << std::fixed << std::setprecision(2) << it->second << '\n';
}

char const	*BitcoinExchange::InvalidFileException::what() const throw()
{
	return "Invalid input file";
}
