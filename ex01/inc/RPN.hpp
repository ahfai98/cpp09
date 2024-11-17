/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:31:02 by jyap              #+#    #+#             */
/*   Updated: 2024/11/17 16:08:47 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <exception>

class RPN
{
	public:
		RPN(void);
		RPN(const RPN &copy);
		RPN &operator=(const RPN &copy);
		~RPN(void);
		static bool valid_expression(const std::string &expr);
		static long calculate(const std::string &expr);
		class NoResultException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class DivisionByZeroException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
