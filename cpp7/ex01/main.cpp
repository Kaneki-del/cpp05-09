#include "iter.hpp"

template <typename T> void printing(T x) { std::cout << x << std::endl; }
int main(void) {
  int numbers[] = {1, 2, 3, 4, 5};
  const char string[] = "ahmed";
  size_t len = sizeof(numbers) / sizeof(numbers[0]);
  iter(string, len, printing<char>);
}
