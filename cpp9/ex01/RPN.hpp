#ifndef Rpn_HPP
#define Rpn_HPP

#include <cctype>
#include <iostream>
#include <limits>
#include <sstream>
#include <stack>
#include <string>

class Rpn {
public:
  Rpn();
  ~Rpn();
  Rpn(const Rpn &other);
  Rpn &operator=(const Rpn &other);
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
