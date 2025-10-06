#include "Rpn.hpp"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Error: Usage: " << argv[0] << " \"<RPN_EXPRESSION>\""
              << std::endl;
    return 1;
  }
  try {
    Rpn rpn;
    rpn.processInput(argv[1]);
    std::cout << rpn.getTopValue() << std::endl;

  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  } catch (...) {
    std::cerr << "Error: An unknown exception occurred during RPN processing."
              << std::endl;
    return 1;
  }
  return 0;
}
