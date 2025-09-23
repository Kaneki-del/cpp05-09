#ifndef SPAN_HPP
#define SPAN_HPP
#include <algorithm>
#include <exception>
#include <iostream>
#include <iterator>
#include <vector>
class Span {
public:
  Span(unsigned int N);
  Span(const Span &other);
  ~Span();
  Span &operator=(const Span &other);
  void addNumber(int n);
  int shortestSpan(void) const;
  int longestSpan(void) const;
  template <typename T> void addRange(T b, T e) {
    if (num.size() + std::distance(b, e) >= N)
      throw std::logic_error("The size is biger than N. ");
    num.insert(num.end(), b, e);
  }

private:
  unsigned int N;
  std::vector<int> num;
};
#endif
