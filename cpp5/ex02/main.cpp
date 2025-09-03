#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
  try {
    Bureaucrat b("Bob", 50);
    Form f("Vacation Request", 75, 100);

    std::cout << b << std::endl;
    std::cout << f << std::endl;
    b.signForm(f);
    std::cout << f << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Caught an exception: " << e.what() << std::endl;
  }

  std::cout << "\n------------------\n";

  try {
    Bureaucrat b("Alice", 100);
    Form f("Expense Report", 50, 60);

    std::cout << b << std::endl;
    std::cout << f << std::endl;
    b.signForm(f);
    std::cout << f << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Caught an exception: " << e.what() << std::endl;
  }

  return 0;
}
