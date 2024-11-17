/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:31:02 by jyap              #+#    #+#             */
/*   Updated: 2024/11/17 16:39:03 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <exception>

class PmergeMe
{
	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &copy);
		~PmergeMe(void);
		void sortVec(int argc, char **argv);
		void sortList(int argc, char **argv);
		class InvalidElementException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
