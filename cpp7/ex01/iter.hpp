#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>
template <typename Ptr, typename F> void iter(Ptr arr, const size_t len, F f) {
  for (size_t i = 0; i < len; i++) {
    f(arr[i]);
  }
};
#endif
