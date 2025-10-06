#include "Rpn.hpp"

Rpn::Rpn() {}

Rpn::~Rpn() {}

Rpn::Rpn(const Rpn &other) : st(other.st) {}

Rpn &Rpn::operator=(const Rpn &other) {
  if (this != &other)
    st = other.st;
  return *this;
}

int Rpn::getTopValue() { return st.top(); }

long Rpn::checkOverFlow(long result) {
  if (result > std::numeric_limits<int>::max() ||
      result < std::numeric_limits<int>::min())
    throw std::out_of_range(
        "Error: The result value is outside the range of a standard integer.");
  return result;
}

void Rpn::doAdd() {
  if (st.size() < 2) {
    throw std::invalid_argument(
        "Error: Operation requires two numbers on the stack.");
  }
  long B = st.top();
  st.pop();
  long A = st.top();
  st.pop();
  st.push(checkOverFlow(A + B));
}

void Rpn::doSubtract() {
  if (st.size() < 2) {
    throw std::invalid_argument(
        "Error: Operation requires two numbers on the stack.");
  }
  long B = st.top();
  st.pop();
  long A = st.top();
  st.pop();

  st.push(checkOverFlow(A - B));
}

void Rpn::doMultiply() {
  if (st.size() < 2) {
    throw std::invalid_argument(
        "Error: Operation requires two numbers on the stack.");
  }

  long B = st.top();
  st.pop();
  long A = st.top();
  st.pop();
  st.push(checkOverFlow(A * B));
}

void Rpn::doDiv() {
  if (st.size() < 2) {
    throw std::invalid_argument(
        "Error: Operation requires two numbers on the stack.");
  }
  long B = st.top();
  st.pop();
  long A = st.top();
  st.pop();
  if (B == 0) {
    throw std::invalid_argument("Error: Cannot divide by zero.");
  }
  st.push(A / B);
}

void Rpn::processInput(const std::string &input) {
  std::stringstream ss(input);
  std::string segment;
  while (std::getline(ss, segment, ' ')) {
    if (segment.empty())
      continue;
    if (segment.length() != 1) {
      throw std::invalid_argument(
          "Error: Invalid token length. Numbers must be single digits (0-9).");
    }

    char token = segment[0];

    if (token >= '0' && token <= '9') {
      st.push(token - '0');
    } else if (token == '+') {
      doAdd();
    } else if (token == '-') {
      doSubtract();
    } else if (token == '*') {
      doMultiply();
    } else if (token == '/') {
      doDiv();
    } else {
      throw std::invalid_argument("Error: Invalid single-character token.");
    }
  }

  if (st.size() != 1) {
    throw std::invalid_argument("Error: Invalid Rpn expression. Stack must "
                                "contain exactly one result.");
  }
}
