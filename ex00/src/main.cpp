/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:47:42 by jyap              #+#    #+#             */
/*   Updated: 2024/11/17 15:57:30 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include "../inc/BitcoinExchange.hpp"

#define BAD_INPUT_ERR "Error: bad input => "
#define FILE_OPEN_ERR "Error: could not open file"
#define INTERNAL_DB_OPEN_ERR "Error: fatal: could not open internal database file"
#define INTERNAL_DB_FILE "./src/data.csv"

float ft_stof(const std::string &str);

static int print_err_msg(std::string err_msg)
{
	std::cerr << err_msg << "\n";
	return (EXIT_FAILURE);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (print_err_msg(FILE_OPEN_ERR));

	std::ifstream input_db(argv[1]);
	if (!input_db.is_open())
		return (print_err_msg(FILE_OPEN_ERR));

	std::ifstream internal_db(INTERNAL_DB_FILE);
	if (!internal_db.is_open())
		return (print_err_msg(INTERNAL_DB_OPEN_ERR));

	BitcoinExchange btc;
	btc.readInternalDataBase(internal_db);

	std::string line;

	// skip first line
	std::getline(input_db, line);
	while (std::getline(input_db, line))
	{
		size_t delim = line.find('|');
		if (delim == std::string::npos
		||	line.length() < delim + 2)
		{
			std::cerr << BAD_INPUT_ERR << "\"" << line << "\"" << '\n';
			continue ;
		}

		std::string date = line.substr(0, delim - 1);
		if (!btc.isDateInCorrectFormat(date) || !btc.isValidDate(date))
			continue;

		std::string rate_as_str = line.substr(delim + 2);
		if (!btc.isRateInCorrectFormat(rate_as_str))
			continue;
		float rate = ft_stof(rate_as_str);

		std::cout << date << " => " << rate << " = " << std::setprecision(2) << rate * btc.getRateFromDataBase(date) << std::endl;
	}
	input_db.close();
	internal_db.close();
	return (EXIT_SUCCESS);
}
