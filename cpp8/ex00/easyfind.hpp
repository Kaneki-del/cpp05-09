#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <algorithm>

#include <exception>
#include <iostream>
#include <vector>

template <typename T> int easyfind(T c, int i) {
  if ((std::find(c.begin(), c.end(), i)) == c.end()) {
    throw std::runtime_error("The occurrence was not found.");
  }
  return i;
};
#endif
