#include <cstdlib>
#include <iostream>
#include <string>
int main (int argc, char *argv[]) {
  std::string str = "-0";
  double res = std::strtod(str.c_str(), NULL);
  if (res < 0)
    std::cout << res << std::endl;
  return 0;
}
