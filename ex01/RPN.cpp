/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:31:08 by eviscont          #+#    #+#             */
/*   Updated: 2024/12/04 18:47:01 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/* Orthodox canonical form */
RPN::RPN() {}

RPN::RPN(const RPN &other)
{
    *this = other;
}

RPN::~RPN() {}

RPN  &RPN::operator=(const RPN &other)
{
	if (this != &other)
		//TO DO
    return *this;
}