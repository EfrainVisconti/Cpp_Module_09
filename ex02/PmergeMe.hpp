/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:46:34 by eviscont          #+#    #+#             */
/*   Updated: 2024/12/05 17:48:11 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <exception>

class PmergeMe
{
	private:

	/* Private methods */

	public:

	/* Orthodox canonical form */
	PmergeMe();
    PmergeMe(const PmergeMe &other);
	~PmergeMe();
    PmergeMe	&operator=(const PmergeMe &other);

	/* Other public methods */
};

#endif
