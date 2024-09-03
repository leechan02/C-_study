#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(RPN const &other)
	: stack(other.stack), result(other.result) {}

RPN &RPN::operator=(RPN const &other)
{
	if (this != &other)
	{
		this->stack = other.stack;
		this->result = other.result;
	}
	return *this;
}

RPN::~RPN() {}

void RPN::parse(std::string const &str)
{
	std::stringstream ss(str);
	std::string token;

	while (ss >> token)
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (stack.size() < 2)
				throw std::runtime_error("Error: not enough values");
			int a = stack.top();
			stack.pop();
			int b = stack.top();
			stack.pop();
			if (token == "+")
				stack.push(b + a);
			else if (token == "-")
				stack.push(b - a);
			else if (token == "*")
				stack.push(b * a);
			else if (token == "/")
			{
				if (a == 0)
					throw std::runtime_error("Error: division by zero");
				stack.push(b / a);
			}
		}
		else
		{
			std::stringstream ss(token);
			std::string remaining;
			int num;

			if ((ss >> num) && !(ss >> remaining))
				stack.push(num);
			else
				throw std::runtime_error("Error: invalid value");
		}
	}
	if (stack.size() != 1)
		throw std::runtime_error("Error: too many values");
	result = stack.top();
}

int RPN::getResult() const
{
	return result;
}