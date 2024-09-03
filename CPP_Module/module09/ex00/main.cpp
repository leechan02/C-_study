#include "BitcoinExchange.hpp"

void getInput(BitcoinExchange &btc, std::string file)
{
	std::ifstream input(file);
	std::string line;

	if (input.is_open())
	{
		std::getline(input, line);
		if (line != "date | value")
			throw std::runtime_error("Error: invalid file format.");
		while (std::getline(input, line))
		{
			std::string date;
			double value;

			std::stringstream ss(line);
			try
			{
				if (!std::getline(ss, date, '|') || !(ss >> value) || ss.peek() != EOF
					|| btc.checkDate(date) == false)
					throw std::runtime_error("Error: bad input => " + line);
				btc.checkValue(value);
				std::cout << date;
				date = btc.getBitcoinDate(date);
				std::cout << "=> " << value << " = ";
				value = btc.getBitcoinPrice(date, value);
				std::cout << value << std::endl;

			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
	}
	else
		throw std::runtime_error("Error: could not open file.");
	input.close();
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}

	BitcoinExchange btc;

	try
	{
		getInput(btc, av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}