#include "Bureaucrat.hpp"
#include <iostream>

int main() {
  // Test valid object creation and `<<` operator
  try {
    Bureaucrat b1("Alice", 1);
    Bureaucrat b2("Bob", 150);
    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Caught exception: " << e.what() << std::endl;
  }

  std::cout << "\n--- Testing Exception Cases ---\n";

  try {
    Bureaucrat b3("Charlie", 0);
  } catch (const std::exception &e) {
    std::cerr << "Caught exception: " << e.what() << std::endl;
  }

  try {
    Bureaucrat b4("Dave", 1);
    b4.increment();
  } catch (const std::exception &e) {
    std::cerr << "Caught exception: " << e.what() << std::endl;
  }

  try {
    Bureaucrat b5("Eve", 150);
    b5.decrement();
  } catch (const std::exception &e) {
    std::cerr << "Caught exception: " << e.what() << std::endl;
  }

  return 0;
}
