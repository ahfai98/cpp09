/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:47:42 by jyap              #+#    #+#             */
/*   Updated: 2024/11/17 16:08:19 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "../inc/RPN.hpp"

# define err_msg_PREFFIX "RPN: error: "
# define ARGC_ERR "invalid number of arguments"
# define INVALID_EXPR_ERR "invalid expression"

static int print_err_msg(const std::string &err_msg)
{
	std::cerr << err_msg_PREFFIX << err_msg << '\n';
	return (EXIT_FAILURE);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (print_err_msg(ARGC_ERR));

	if (!RPN::valid_expression(argv[1]))
		return (print_err_msg(INVALID_EXPR_ERR));
	try
	{
		std::cout << RPN::calculate(argv[1]) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << "\n";
	}
	return (EXIT_SUCCESS);
}
