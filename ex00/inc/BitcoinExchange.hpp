/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:31:02 by jyap              #+#    #+#             */
/*   Updated: 2024/11/17 15:12:11 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <map>

class BitcoinExchange {
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &copy);
		~BitcoinExchange(void);
		void readInternalDataBase(std::ifstream &internal_db);
		float getRateFromDataBase(const std::string &date);
		bool isDateInCorrectFormat(const std::string &date);
		bool isValidDate(const std::string &date);
		bool isRateInCorrectFormat(const std::string &rate);

	private:
		std::map<std::string, float> dataBase;
};

#endif
