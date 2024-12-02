/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:42:39 by codespace         #+#    #+#             */
/*   Updated: 2024/12/02 15:37:50 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange::~BitcoinExchange()
{

}

BitcoinExchange  &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this == &other)
        return *this;
//TO DO
    return *this;
}

void	BitcoinExchange::initData(char *file)
{
	std::ifstream infile;
	infile.open(file);
	if (!infile.is_open())
	{
		std::cout << "Error opening input file" << std::endl;
		return ;
	}
		std::string	line;
	size_t	aux1;
	size_t	aux2;

	std::string line;
	while (std::getline(infile, line))
	{

	}
}