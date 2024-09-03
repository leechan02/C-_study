#pragma once

#include <iostream>
#include <sstream>
#include <stack>
#include <cstdlib>

class RPN
{
	private:
		std::stack<int> stack;
		int result;
	public:
		RPN();
		RPN(RPN const &other);
		RPN &operator=(RPN const &other);
		~RPN();

		void parse(std::string const &str);
		int getResult() const;
};