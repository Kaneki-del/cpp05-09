#ifndef MUTANSTACK_HPP
#define MUTANSTACK_HPP
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
template <typename T> class MutantStack : public std::stack<T> {
public:
  typedef typename std::stack<T>::container_type::iterator iterator;
  typedef typename std::stack<T>::container_type::iterator const_iterator;

  iterator begin() { return this->c.begin(); }
  iterator end() { return this->c.end(); }
  const_iterator begin() const { return this->c.begin(); }
  const_iterator end() const { return this->c.end(); }
};
#endif // !MUTANSTACK_HPP
