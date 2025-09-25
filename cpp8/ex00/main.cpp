#include "easyfind.hpp"

int main() {
  std::vector<int> numbers = {10, 20, 30, 40, 50};
  int value_to_find = 50;

  try {
    std::vector<int>::const_iterator it;
    it = easyfind(numbers, value_to_find);
    std::cout << "Found value: " << *it << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  return 0;
}
