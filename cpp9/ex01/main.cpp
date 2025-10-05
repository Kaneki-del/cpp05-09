#include "RPN.hpp"

int main(int argc, char *argv[]) {

  if (argc == 2) {
    RPN rpn;
    if (!rpn.processInput(argv[1])) {
      return 1;
    }
    std::cout << rpn.getTopValue() << std::endl;
  }
  return 0;
}
