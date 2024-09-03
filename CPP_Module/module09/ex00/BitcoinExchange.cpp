#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string csv)
	: csv(csv)
{
	try
	{
		loadFile();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
	: csv(copy.csv) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	if (this != &copy)
		csv = copy.csv;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadFile()
{
	std::ifstream file(csv);

	if (!file.is_open() && csv.substr(csv.find_last_of(".") + 1) != "csv")
		throw std::runtime_error("Error: could not open file.");

	std::string line;
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string date;
		double price;

		std::getline(ss, date, ',');
		ss >> price;

		map[date] = price;
	}
	file.close();
}

bool BitcoinExchange::checkDate(std::string dateStr)
{
	int year, month, day;
	int daysInMonth[] = {-1,31,28,31,30,31,30,31,31,30,31,30,31};

	if (dateStr[4] != '-' || dateStr[7] != '-')
		return false;
	std::replace(dateStr.begin(), dateStr.end(), '-', ' ');
	std::stringstream ss(dateStr);
	if (!(ss >> year >> month >> day))
		return false;

	if (year < 0 || month < 0 || month > 12 || day < 0 || day > 31)
		return false;
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		daysInMonth[2] = 29;
	if (day > daysInMonth[month])
		return false;
	return true;
}

void BitcoinExchange::checkValue(const double value)
{
	if (value < 0)
		throw std::runtime_error("Error: not a positive number.");
	else if (value > 1000)
		throw std::runtime_error("Error: too large a number.");
}

std::string BitcoinExchange::getBitcoinDate(const std::string& date)
{
	std::map<std::string, double>::iterator it = map.begin();
	int compare;

	if (date.compare("2009-01-02") < 0)
		throw std::runtime_error("Error: too early date.");
	for (; it != map.end(); it++)
	{
		compare = it->first.compare(date);
		if (compare >= 0)
			break ;
	}
	if (compare != 0)
		--it;
	return it->first;
}

double BitcoinExchange::getBitcoinPrice(const std::string& date, const double value)
{
	std::map<std::string, double>::iterator it = map.find(date);
	double price = it->second;

	return (price * value);
}