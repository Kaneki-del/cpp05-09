#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
  // (void)argv;
  if (argc != 2) {
    // TODO print a message show how to use
    return 1;
  }

  try {
    BitcoinExchange btc("data.csv");
    btc.processInputFile(argv[1]);

  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}
