/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:31:08 by eviscont          #+#    #+#             */
/*   Updated: 2024/12/05 17:30:31 by eviscont         ###   ########.fr       */
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
	(void)other;
    return *this;
}

/* Private and public methods */
bool	validNumber(const std::string &token)
{
	if ((token.length() == 2 && token[0] == '-' && isdigit(token[1]))
	|| (token.length() == 1 && isdigit(token[0])))
		return true;
	return false;
}

long	getFromStack(std::stack<long> &stack)
{
	long val;

	if (stack.empty())
		throw std::logic_error("Error");
	val = stack.top();
	stack.pop();
	return val;
}

void	RPN::caseSum()
{
	long val1, val2;

	val1 = getFromStack(this->_stack);
	val2 = getFromStack(this->_stack);
	this->_stack.push(val2 + val1);
}

void	RPN::caseMin()
{
	long val1, val2;

	val1 = getFromStack(this->_stack);
	val2 = getFromStack(this->_stack);
	this->_stack.push(val2 - val1);
}

void	RPN::caseDiv()
{
	long val1, val2;

	val1 = getFromStack(this->_stack);
	val2 = getFromStack(this->_stack);
	if (val1 == 0)
		throw std::logic_error("Error: Division by 0");
	this->_stack.push(val2 / val1);
}

void	RPN::caseMult()
{
	long val1, val2;

	val1 = getFromStack(this->_stack);
	val2 = getFromStack(this->_stack);
	this->_stack.push(val2 * val1);
}

void	RPN::applyOperator(const std::string &token)
{
	switch (token[0])
	{
	case '+':
		caseSum();
		break;
	case '-':
		caseMin();
		break;
	case '/':
		caseDiv();
		break;
	case '*':
		caseMult();
		break;
	default:
		throw std::logic_error("Error");
	}
}

void	RPN::calculateRPN(const std::string &input)
{
	std::size_t found = input.find_first_not_of("0123456789 +-/*");
	if (found != std::string::npos)
		throw std::invalid_argument("Error: Invalid character " + input.substr(found, 1) + " found");

	std::string token;
	std::stringstream ss(input);
	while (getline(ss, token, ' '))
	{
		if (token.length() == 0)
			continue ;
		if (validNumber(token))
			this->_stack.push(std::atol(token.c_str()));
		else if (token.length() == 1 && token.find_first_not_of("+-/*") == std::string::npos)
			applyOperator(token);
		else
			throw std::logic_error("Error: Unexpected token " + token);
	}

	long aux = getFromStack(this->_stack);
	if (!this->_stack.empty())
		throw std::logic_error("Error");
	std::cout << aux << std::endl;
}