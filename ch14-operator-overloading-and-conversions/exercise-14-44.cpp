// Exercise 14.44, page 717
//
// 14.44: Write your own version of a simple desk calculator that can
// handle binary operations.

#include <iostream>
#include <map>
#include <functional>
#include <cctype>
#include <stack>
#include <vector>
#include <sstream>

std::string operators = "+-*/";
std::string digits = "0123456789";

std::map<std::string, std::function<double(double, double)>> operations = {
  {"+", std::plus<double>()},
  {"-", std::minus<double>()},
  {"*", std::multiplies<double>()},
  {"/", std::divides<double>()}
};

bool is_operator(std::string s) {
  return operators.find(s) != std::string::npos;
}

bool is_digit(std::string s) {
  return digits.find(s) != std::string::npos;
}

int main(int argc, char *argv[argc])
{
  std::stack<std::string> symbols_stack;

  std::cout << "Welcome to the c++ calculator." << std::endl;
  std::cout << "Type an arithmetic expression or q to quit." << std::endl;
  std::cout << "You may use the operators ( ) + - * / %" << std::endl;

  std::string expression;

  while(std::getline(std::cin, expression)) {
    if (expression == "q") return 0;

    std::stringstream ss(expression);
    std::string token;

    double result;

    while (ss >> token) {
      if (is_digit(token)) {

        if (!symbols_stack.empty() && is_operator(symbols_stack.top())) {
          std::string op = symbols_stack.top();
          symbols_stack.pop();
          std::string lhs = symbols_stack.top();
          symbols_stack.pop();

          double result = operations[op](std::stod(lhs), std::stod(token));
          symbols_stack.push(std::to_string(result));
        } else {
          symbols_stack.push(token);
        }

      } else if(is_operator(token)) {
        symbols_stack.push(token);
      }

    }

    std::cout << "= " << symbols_stack.top() << std::endl;
  }
  
  return 0;
}

