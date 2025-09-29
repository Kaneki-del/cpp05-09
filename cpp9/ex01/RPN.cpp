#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other) : st(other.st) {}

RPN &RPN::operator=(const RPN &other) {
  if (this != &other) 
    st = other.st;
  return *this;
}

long long RPN::getTopValue(){
  return st.top();
}

bool RPN::doAdd() {
  if (st.size() < 2) {
    std::cerr << "EROOR: couldnt the operation the stack should have two numbers"
      << std::endl;
    return false;
  }
  long long B = st.top();
  st.pop();
  long long A = st.top();
  st.pop();

  if ((B > 0 && A > (std::numeric_limits<long long>::max() - B)) ||
      (B < 0 && A < (std::numeric_limits<long long>::min() - B))) {
    std::cerr << "Error: addition resulted in overflow or underflow."
      << std::endl;
    return false;
  }
  st.push(A + B);
  return true;
}

bool RPN::doSubtract() {
  if (st.size() < 2) {
    std::cerr << "EROOR: couldnt the operation the stack should have two numbers"
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
bool RPN::doMultiply(){
  if (st.size() < 2) {
    std::cerr << "EROOR: couldnt the operation the stack should have two numbers"
      << std::endl;
    return false;
  }

  long long B = st.top();
  st.pop();
  long long A = st.top();
  st.pop();
  if (A != 0 && B != 0 &&
      ((A > 0 && B > 0 && A > (std::numeric_limits<long long>::max() / B)) ||
       (A < 0 && B < 0 && A < (std::numeric_limits<long long>::max() / B)) ||
       (A > 0 && B < 0 && A > (std::numeric_limits<long long>::min() / B)) ||
       (A < 0 && B > 0 && A < (std::numeric_limits<long long>::min() / B))))
  {
    std::cerr << "Error: Multiplication resulted in overflow or underflow." << std::endl;
    return false;
  }
  st.push(A * B);
  return true;
}

bool RPN::doDiv(){
  if (st.size() < 2) {
    std::cerr << "EROOR: couldnt the operation the stack should have two numbers"
      << std::endl;
    return false;
  }
  long long B = st.top();
  st.pop();
  long long A = st.top();
  st.pop();
  if (B == 0){
    std::cerr << "ERROR: cant devide on 0" << std::endl;
    return false;
  }
  st.push(A / B);
  return true;

}

bool RPN::processInput(const std::string &input) {
    std::stringstream ss(input);
    std::string segment;
    
    while (std::getline(ss, segment, ' ')) {
        if (segment.empty())
            continue; 
        if (segment.length() == 1) {
            char token = segment[0];

            if (token >= '0' && token <= '9') {
                st.push(token - '0');
            } 
            else if (token == '+') {
                if (!doAdd()) return false;
            } 
            else if (token == '-') {
                if (!doSubtract()) return false;
            }
            else if (token == '*') {
                if (!doMultiply()) return false;
            }
            else if (token == '/') {
                if (!doDiv()) return false;
            }
            else {
                std::cerr << "Error: Invalid single-character token." << std::endl;
                return false;
            }
        } 
        else if (segment.length() == 2) {
            if (segment[0] == '-' && (segment[1] >= '1' && segment[1] <= '9')) {
                int value = -(segment[1] - '0');
                st.push(value);
            } 
            else {
                std::cerr << "Error: Invalid multi-character token format (must be negative digit)." << std::endl;
                return false;
            }
        }
        else {
            std::cerr << "Error: Invalid token length or format (must be 1 or 2)." << std::endl;
            return false;
        }
    }
    if (st.size() != 1) {
        std::cerr << "Error: Invalid RPN expression. Stack must contain exactly one result." << std::endl;
        return false;
    }
    
    return true;
}
