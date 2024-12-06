/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:47:09 by eviscont          #+#    #+#             */
/*   Updated: 2024/12/06 20:34:24 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: try ./PmergeMe <arg1> <arg2> <arg3> ..." << std::endl;
		return 1;
	}
	try
	{
		PmergeMe pmergeme;
		pmergeme.sortArgs(argv);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
