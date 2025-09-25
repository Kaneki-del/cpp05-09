#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <algorithm>

#include <exception>
#include <iostream>
#include <vector>

template <typename T> typename T::const_iterator easyfind(T &c, int i) {
  typename T::const_iterator it = std::find(c.begin(), c.end(), i);
  if (it == c.end())
    throw std::logic_error("The occurrence was not found.");
  return it;
};
#endif
