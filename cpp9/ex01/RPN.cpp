#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other) {}

RPN &RPN::operator=(const RPN &other) {
  if (this != &other) {
    // exchange_rates = other.exchange_rates;
  }
  return *this;
}
bool RPN::doAdd() {
  if (st.size() < 2) {
    std::cerr << "couldnt the operation the stach should have two numbers"
              << std::endl;
    return false;
  }
  long long B = st.top();
  st.pop();
  long long A = st.top();
  st.pop();

  if ((B > 0 && A > (std::numeric_limits<long long>::max() - B)) ||
      (B < 0 && A < (std::numeric_limits<long long>::min() - B))) {
    std::cerr << "Error: Calculation resulted in overflow/underflow."
              << std::endl;
    return false;
  }
  st.push(A + B);
  return true;
}

bool RPN::doSubtract() {
  if (st.size() < 2) {
    std::cerr << "couldnt the operation the stach should have two numbers"
              << std::endl;
    return false;
  }
  long long B = st.top();
  st.pop();
  long long A = st.top();
  st.pop();
  if ((B < 0 && A > std::numeric_limits<long long>::max() + B) ||
      (B > 0 && A < std::numeric_limits<long long>::min() + B)) {
    std::cerr << "Error: Subtraction resulted in overflow or underflow."
              << std::endl;
    return false;
  }
  st.push(A - B);
  return true;
}
// bool RPN::doMultiply(){
//
// }
//
// bool RPN::doDiv(){
//
// }
void RPN::processInput(const std::string &input) {
  std::stringstream ss(input);
  std::string segment;
  while (std::getline(ss, segment, ' ')) {
    if (segment.empty()) {
      continue;
    }
    if (segment.length()) {
      if (segment[0] >= '0' && segment[0] <= '9') {
        st.push(segment[0] - '0');
      } else if (segment[0] == '+') {
        if (!doAdd())
          return;
      } else if (segment[0] == '-') {
        if (!doSubtract())
          return;
      }

      else if (segment[0] == '/') {
      } else
        std::cerr << "ERROR" << std::endl;
    }
    // if (stack.size() != 1)
    // #TODO check if the size is not 1 error
  }
}
