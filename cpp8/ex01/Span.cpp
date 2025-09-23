#include "Span.hpp"

Span::~Span() {}

Span::Span(unsigned int N) : N(N) {}

Span::Span(const Span &other) : N(other.N), num(other.num) {}

Span &Span::operator=(const Span &other) {
  if (this != &other) {
    N = other.N;
    num = other.num;
  }
  return *this;
}

void Span::addNumber(int n) {
  if (num.size() >= N) {
    throw std::out_of_range("Cannot add number. Span is full.");
  }
  num.push_back(n);
}

int Span::shortestSpan(void) const {
  if (num.size() < 2) {
    throw std::logic_error(
        "Cannot find a span: fewer than two numbers stored.");
  }
  std::vector<int> copy = num;
  std::sort(copy.begin(), copy.end());
  int temp = copy[1] - copy[0];
  int value = 0;
  for (unsigned long i = 2; i < num.size(); i++) {
    value = copy[i] - copy[i - 1];
    if (value < temp)
      temp = value;
  }
  return temp;
}

int Span::longestSpan(void) const {
  if (num.size() < 2) {
    throw std::logic_error(
        "Cannot find a span: fewer than two numbers stored.");
  }

  std::vector<int>::const_iterator min_it =
      std::min_element(num.begin(), num.end());
  std::vector<int>::const_iterator max_it =
      std::max_element(num.begin(), num.end());
  return *max_it - *min_it;
}
