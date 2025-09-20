#include "Identify.hpp"
#include <ctime>

int main() {
  srand(time(0));
  Base *test = generate();
  identify(test);
  identify(*test);
  delete test;
}
