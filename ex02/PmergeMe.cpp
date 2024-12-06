/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:46:43 by eviscont          #+#    #+#             */
/*   Updated: 2024/12/06 21:22:50 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* Orthodox canonical form */
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
}

PmergeMe::~PmergeMe() {}

PmergeMe  &PmergeMe::operator=(const PmergeMe &other)
{
	(void)other;
    return *this;
}

/* Templates */
template <typename T>
void printContainer(const T &container)
{
	for (typename T::const_iterator i = container.begin(); i != container.end(); ++i)
		std::cout << *i << ' ';
    std::cout << std::endl;
}

template <typename T>
void	binaryInsert(T &S, int value)
{
    typename T::iterator pos = std::lower_bound(S.begin(), S.end(), value);
    S.insert(pos, value);
}

/* Private and public methods */
bool	PmergeMe::validArgs(char **argv)
{
	for (int i = 1; argv[i] != NULL; i++)
	{
		if (argv[i][0] == '\0')
			return false;
		for (int j = 0; argv[i][j] != '\0'; j++)
		{
			if (!isdigit(argv[i][j]))
				return false;
		}
		long int number = std::atol(argv[i]);
		if (number > static_cast<long int>(INT_MAX))
			return false;
	}
	return true;
}

void	PmergeMe::vectorFill(char **argv)
{
	std::clock_t start = std::clock();
	for (int i = 1; argv[i] != NULL; i++)
	{
		_vector.push_back(std::atoi(argv[i]));
	}
	std::clock_t end = std::clock();
	_vecTime = double(end - start) / double(CLOCKS_PER_SEC);
}

void	PmergeMe::dequeFill(char **argv)
{
	std::clock_t start = std::clock();
	for (int i = 1; argv[i] != NULL; i++)
	{
		_deque.push_back(std::atoi(argv[i]));
	}
	std::clock_t end = std::clock();
	_deqTime = double(end - start) / double(CLOCKS_PER_SEC);
}

/*	                             Ford–Johnson algorithm

	1º Group the elements of X into n / 2 pairs of elements, arbitrarily, leaving one
	element unpaired if there is an odd number of elements.
    2º Perform n / 2 comparisons, one per pair, to determine the larger of the two elements
	in each pair.
    3º Recursively sort the n / 2 larger elements from each pair, creating a sorted sequence
	S of n / 2 of the input elements, in ascending order, using the merge-insertion sort.
    4º Insert at the start of S the element that was paired with the first and smallest
	element of S. (this step was not implemented)
    5º Insert the remaining (n / 2) − 1 elements of X ∖ S into S, one at a time. Use binary
	search in subsequences of S to determine the position at which each element should be
	inserted. */

std::vector<int>	PmergeMe::vectorMergeInsertion(std::vector<int> X)
{
	std::vector<int> S;
	std::size_t n = X.size();

	if (n == 1)
		return X;

	for (std::size_t i = 0; i < n - 1; i += 2)
	{
		if (X[i] > X[i + 1])
		{
			S.push_back(X[i]);
			X[i] = -1;
		}
		else
		{
			S.push_back(X[i + 1]);
			X[i + 1] = -1;
		}
	}

	if (S.size() > 1)
		S = vectorMergeInsertion(S);

	for (size_t i = 0; i < n; i++)
	{
		if (X[i] != -1)
        	binaryInsert(S, X[i]);
	}

	return S;
}

std::deque<int>	PmergeMe::dequeMergeInsertion(std::deque<int> X)
{
	std::deque<int> S;
	std::size_t n = X.size();

	if (n == 1)
		return X;

	for (std::size_t i = 0; i < n - 1; i += 2)
	{
		if (X[i] > X[i + 1])
		{
			S.push_back(X[i]);
			X[i] = -1;
		}
		else
		{
			S.push_back(X[i + 1]);
			X[i + 1] = -1;
		}
	}

	if (S.size() > 1)
		S = dequeMergeInsertion(S);

	for (size_t i = 0; i < n; i++)
	{
		if (X[i] != -1)
        	binaryInsert(S, X[i]);
	}

	return S;
}

void	PmergeMe::displayInfo(const std::vector<int> &sorted)
{
	std::cout << "Before:  ";
	printContainer(_vector);
	std::cout << "After:  ";
	printContainer(sorted);
	std::cout << std::fixed << std::setprecision(7);
	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector<int> : " << _vecTime << " s" << std::endl;
	std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque<int> : " << _deqTime << " s" << std::endl;
}

void	PmergeMe::sortArgs(char **argv)
{
	if (validArgs(argv) == false)
		throw std::invalid_argument("Error: Invalid argument found");

	vectorFill(argv);
	dequeFill(argv);

	std::clock_t start1 = std::clock();
	std::vector<int> sortedVec = vectorMergeInsertion(_vector);
	std::clock_t end1 = std::clock();
	_vecTime += double(end1 - start1) / double(CLOCKS_PER_SEC);

	std::clock_t start2 = std::clock();
	std::deque<int> sortedDeq = dequeMergeInsertion(_deque);
	std::clock_t end2 = std::clock();
	_deqTime += double(end2 - start2) / double(CLOCKS_PER_SEC);

	displayInfo(sortedVec);
}
