/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:43:04 by codespace         #+#    #+#             */
/*   Updated: 2024/12/02 15:37:35 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <exception>

class BitcoinExchange
{
	public:
	static std::map<std::string, float>	data;

	/* Orthodox canonical form */
	BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
	~BitcoinExchange();
    BitcoinExchange	&operator=(const BitcoinExchange &other);

	/* Other methods */
	void	initData(char *file);
};

#endif
