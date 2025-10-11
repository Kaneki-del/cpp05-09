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
  int getTopValue();

private:
  long checkOverFlow(long result);
  void doAdd();
  void doSubtract();
  void doMultiply();
  void doDiv();
  std::stack<int> st;
};
#endif
