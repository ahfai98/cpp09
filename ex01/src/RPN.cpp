/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:29:28 by jyap              #+#    #+#             */
/*   Updated: 2024/11/17 16:33:00 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include "../inc/RPN.hpp"

static int ft_stoi(const std::string &str)
{
	int num;
	std::stringstream ss(str);
	ss >> num;
	return (num);
}

RPN::RPN(void){}

RPN::RPN(const RPN &copy)
{
	*this = copy;
}

RPN &RPN::operator=(const RPN &copy)
{
	(void)copy;
	return (*this);
}

RPN::~RPN(void){}

bool RPN::valid_expression(const std::string &expr)
{
	if (expr.find_first_not_of("0123456789+-/* \t") != std::string::npos)
		return false;

	std::istringstream ss(expr);
	std::string token;
	int operands = 0, operators = 0;

	while (ss >> token)
	{
		if (token.length() == 1 && std::isdigit(token[0]))
			operands++;
		else if (token.length() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'))
			operators++;
		else
			return (false); // Invalid token (not a single digit or operator)
	}

	// Ensure the number of operands and operators is valid
	if (operands < 2 || operators != operands - 1)
		return (false);

	return (true);
}

long RPN::calculate(const std::string &expr)
{
	int left;
	int right;
	int result;
	std::stringstream ss(expr);
	std::stack<int> temp;
	std::string s;

	while (ss >> s)
	{
		if (s == "+" || s == "-" || s == "/" || s == "*")
		{
			if (temp.size() < 2)
				throw NoResultException();
			right = temp.top();
			temp.pop();
			left = temp.top();
			temp.pop();
			switch (s.at(0))
			{
				case '+':
					result = left + right;
					break;
				case '-':
					result = left - right;
					break;
				case '/':
					if (right != 0)
						result = left / right;
					else
						throw DivisionByZeroException();
					break;
				case '*':
					result = left * right;
					break;
			}
			temp.push(result); // push the result of the above operation
		}
		else
			temp.push(ft_stoi(s));
	}
	// last element on the stack is the answer
	return (temp.top());
}

const char*	RPN::NoResultException::what() const throw()
{
	return ("RPN exception: No result. Wrongly formatted expression");
}

const char*	RPN::DivisionByZeroException::what() const throw()
{
	return ("RPN exception: division by zero");
}
