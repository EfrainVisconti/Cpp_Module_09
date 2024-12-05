/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:31:31 by eviscont          #+#    #+#             */
/*   Updated: 2024/12/05 15:12:01 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <cstdlib>
#include <exception>

class RPN
{
	private:
	std::stack<long> _stack;

	/* Private methods */
	void	applyOperator(const std::string &token);
	void	caseMult();
	void	caseDiv();
	void	caseMin();
	void	caseSum();

	public:

	/* Orthodox canonical form */
	RPN();
    RPN(const RPN &other);
	~RPN();
    RPN	&operator=(const RPN &other);

	/* Other public methods */
	void	calculateRPN(const std::string &input);
};

#endif
