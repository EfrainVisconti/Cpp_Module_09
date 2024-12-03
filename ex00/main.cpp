/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:43:09 by codespace         #+#    #+#             */
/*   Updated: 2024/12/03 17:29:34 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: try ./btc <input_file>" << std::endl;
		return 1;
	}
	(void)argv;
	BitcoinExchange btc;
	btc.loadData("data.csv");
	btc.processInfile(argv[1]);
}
