#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <sstream>
#include <ctime>
#include <algorithm>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

class BitcoinExchange
{
	private:
		std::map<std::string, double> map;
		std::string csv;
		void loadFile();
	public:
		BitcoinExchange(std::string csv = "data.csv");
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &copy);
		~BitcoinExchange();

		std::string getBitcoinDate(const std::string& date);
		double getBitcoinPrice(const std::string& date, const double value);
		bool checkDate(std::string dateStr);
		void checkValue(const double value);
};