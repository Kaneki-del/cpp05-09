#ifndef RPN_HPP
#define RPN_HPP

#include <cctype>
#include <iostream>
#include <limits>
#include <sstream>
#include <stack>
#include <string>

class RPN {
public:
  RPN();
  ~RPN();
  RPN(const RPN &other);
  RPN &operator=(const RPN &other);
  void processInput(const std::string &input);
  // RPN::RPN() { std::string & input };

private:
  // bool isValidValue(int value);
  bool doAdd();
  bool doSubtract();
  bool doMultiply();
  bool doDiv();
  std::stack<long long> st;
};
#endif
