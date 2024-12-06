/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:30:15 by eviscont          #+#    #+#             */
/*   Updated: 2024/12/06 15:28:31 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: try ./RPN <inverted Polish expression in quotes>" << std::endl;
		return 1;
	}
	RPN rpn;
	try
	{
		rpn.calculateRPN(argv[1]);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
