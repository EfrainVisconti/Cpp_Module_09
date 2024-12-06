/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:46:34 by eviscont          #+#    #+#             */
/*   Updated: 2024/12/06 20:50:25 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <deque>
#include <ctime>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <iomanip>

class PmergeMe
{
	private:
	std::vector<int>	_vector;
	std::deque<int>		_deque;
	double	_vecTime;
	double	_deqTime;

	/* Private methods */
	bool	validArgs(char **argv);
	void	vectorFill(char **argv);
	void	dequeFill(char **argv);
	void	displayInfo(const std::vector<int> &sorted);

	public:
	/* Orthodox canonical form */
	PmergeMe();
    PmergeMe(const PmergeMe &other);
	~PmergeMe();
    PmergeMe	&operator=(const PmergeMe &other);

	/* Other public methods */
	void				sortArgs(char **argv);
	std::vector<int>	vectorMergeInsertion(std::vector<int> X);
	std::deque<int>		dequeMergeInsertion(std::deque<int> X);
};

#endif
