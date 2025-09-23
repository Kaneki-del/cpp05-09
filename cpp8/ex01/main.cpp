#include "Span.hpp"

int main() {
  try {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  std::cout << "---------------------------------------" << std::endl;

  try {
    Span largeSpan(20000);
    std::vector<int> numbersToAdd;
    for (int i = 0; i < 15000; ++i) {
      numbersToAdd.push_back(i);
    }

    largeSpan.addRange(numbersToAdd.begin(), numbersToAdd.end());
    largeSpan.addNumber(25000);

    std::cout << "Shortest Span (large): " << largeSpan.shortestSpan()
              << std::endl;
    std::cout << "Longest Span (large): " << largeSpan.longestSpan()
              << std::endl;

  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  std::cout << "---------------------------------------" << std::endl;

  try {
    Span fullSpan(3);
    fullSpan.addNumber(1);
    fullSpan.addNumber(2);
    fullSpan.addNumber(3);
    fullSpan.addNumber(4); // This should throw an exception
  } catch (const std::exception &e) {
    std::cerr << "Caught exception (full span): " << e.what() << std::endl;
  }

  // 2. Finding span in an empty Span
  try {
    Span emptySpan(5);
    std::cout << "Shortest Span (empty): " << emptySpan.shortestSpan()
              << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Caught exception (empty span): " << e.what() << std::endl;
  }

  // 3. Finding span with one number
  try {
    Span singleSpan(5);
    singleSpan.addNumber(42);
    std::cout << "Longest Span (single): " << singleSpan.longestSpan()
              << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Caught exception (single number): " << e.what() << std::endl;
  }

  return 0;
}
