#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
  if (argc != 2) {
        std::cerr << "Error: Usage: " << argv[0] << " <input_file>" << std::endl;
        std::cerr << "Example: " << argv[0] << " input.txt" << std::endl;
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
