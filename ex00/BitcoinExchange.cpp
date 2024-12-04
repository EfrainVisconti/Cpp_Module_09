/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:42:39 by codespace         #+#    #+#             */
/*   Updated: 2024/12/04 19:54:59 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static const std::string inputHeader = "date | value";
static const int YEAR = 0;
static const int MONTH = 1;
static const int DAY = 2;

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

/* Private and public methods */
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
	infile.close();
}

void	BitcoinExchange::currentDate()
{
    std::time_t now = std::time(NULL);
    std::tm* localTime = std::localtime(&now);

    _auxCurrentDate[YEAR] = 1900 + localTime->tm_year;
    _auxCurrentDate[MONTH] = 1 + localTime->tm_mon;
    _auxCurrentDate[DAY] = localTime->tm_mday;
}

bool	BitcoinExchange::isValidDate(const std::string &date)
{
	int year = std::atoi(date.substr(0, 4).c_str());
	if (year < 2009 || year > _auxCurrentDate[YEAR])
		return false;

	int month = std::atoi(date.substr(5,2).c_str());
	if (month < 1 || month > 12)
		return false;

	int day = std::atoi(date.substr(8, 2).c_str());
	int daysMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		daysMonth[1] = 29;
	if (day < 1 || day > daysMonth[month - 1]
		|| (year == _auxCurrentDate[YEAR] && (month > _auxCurrentDate[MONTH]
		|| (month == _auxCurrentDate[MONTH] && day > _auxCurrentDate[DAY]))))
		return false;

	return true;
}

void	BitcoinExchange::processDate(const std::string &date)
{
	if (isValidDate(date) == true)
	{
		std::map<std::string, double>::iterator it = data.find(date);
		if (it != data.end())
		{
			std::cout << date << " => " << _auxValue << " = " << _auxValue * it->second << std::endl;
			return ;
		}
		it = data.lower_bound(date);
		if (it != data.begin())
			--it;
		std::cout << date << " => " << _auxValue << " = " << _auxValue * it->second << std::endl;
	}
	else
		throw std::runtime_error("invalid input date => " + date);
}

void	BitcoinExchange::processValue(const std::string &strValue)
{
	if (strValue.empty() || strValue.find_first_not_of("0123456789.- ") != std::string::npos)
		throw std::runtime_error("invalid input value => " + strValue);
	_auxValue = std::atof(strValue.c_str());
	if (_auxValue > 1000)
		throw std::runtime_error("too large a number.");
	if (_auxValue < 0)
		throw std::runtime_error("not a positive number.");
}

void	BitcoinExchange::processValidLine(const std::string &line)
{
	std::string date = line.substr(0, 10);
	std::string strValue = line.substr(13);
	processValue(strValue);
	processDate(date);
}

void	BitcoinExchange::processLine(const std::string &line)
{
	if (line.empty())
		return ;
	if (line.size() >= 14 && line[4] == '-' && line[7] == '-'
		&& line[10] == ' ' && line[11] == '|' && line[12] == ' '
		&& line.substr(0, 10).find_first_not_of("0123456789-") == std::string::npos)
		processValidLine(line);
	else
		throw std::runtime_error("bad input => " + line);
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
		infile.close();
		return ;
	}
	currentDate();
	while (std::getline(infile, line))
	{
		try
		{
			processLine(line);
		}
		catch (const std::exception& e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	infile.close();
}

/* Debugger methods */
void	BitcoinExchange::printData() const
{
	std::map<std::string, double>::const_iterator it;
	for (it = data.begin(); it != data.end(); ++it)
    	std::cout << it->first <<  "," << std::fixed << std::setprecision(2) << it->second << '\n';
}
