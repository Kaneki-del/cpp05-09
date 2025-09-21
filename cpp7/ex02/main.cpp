#include "Array.hpp"

int main() {
  std::cout << "--- Testing Array<int> ---" << std::endl;

  Array<int> a(5);
  for (unsigned int i = 0; i < a.size(); ++i) {
    std::cout << "a[" << i << "] = " << a[i] << std::endl;
  }

  a[0] = 10;
  a[2] = 20;
  a[4] = 30;
  std::cout << "\nModified a[0], a[2], and a[4]." << std::endl;

  Array<int> b = a;
  b[0] = 99;
  std::cout << "\nTesting copy constructor: b[0] is now " << b[0]
            << ", a[0] is " << a[0] << std::endl;

  Array<int> c(2);
  c = a;
  c[0] = 55;
  std::cout << "Testing assignment operator: c[0] is now " << c[0]
            << ", a[0] is " << a[0] << std::endl;

  Array<int> d;
  std::cout << "\nTesting default constructor: d.size() = " << d.size()
            << std::endl;

  std::cout << "\nTesting exception handling:" << std::endl;
  try {
    std::cout << a[10] << std::endl;
  } catch (const std::out_of_range &e) {
    std::cerr << "Caught exception: " << e.what() << std::endl;
  }

  std::cout << "\n--- Testing Array<std::string> ---" << std::endl;
  Array<std::string> s(3);
  s[0] = "Hello";
  s[1] = "World";
  s[2] = "!";
  for (unsigned int i = 0; i < s.size(); ++i) {
    std::cout << "s[" << i << "] = " << s[i] << std::endl;
  }

  return 0;
}
