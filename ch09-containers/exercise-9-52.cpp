// Exercise 9.52, page 471
//
// Use a stack to process parenthesized expressions. When you see an
// open parenthesis, note that it was seen. When you see a close
// parenthesis after an open parenthesis, pop elements down to and
// including the open parenthesis off the stack. push a value onto the
// stack to indicate that a parenthesized expression was replaced.

#include <iostream>
#include <string>
#include <stack>

int main(int argc, char *argv[argc])
{
  std::string parenthesized_expression;
  getline(std::cin, parenthesized_expression);

  std::stack<char> parenthesis_balance_tracker;

  bool parenthesis_are_balanced = true;

  for (auto ch : parenthesized_expression) {
    if (ch == '(') {
      parenthesis_balance_tracker.push('(');
    } else if (ch == ')') {
      if (parenthesis_balance_tracker.empty()) {
        parenthesis_are_balanced = false;
        break;
      } else if (parenthesis_balance_tracker.top() == '(') {
        parenthesis_balance_tracker.pop();
      }
    }
  }

  parenthesis_are_balanced = parenthesis_are_balanced && parenthesis_balance_tracker.empty();

  if (parenthesis_are_balanced) {
    std::cout << "The expressions parenthesis are balanced." << std::endl;
  } else {
    std::cout << "The expressions parenthesis are NOT balanced." << std::endl;
  }
  
  return 0;
}
