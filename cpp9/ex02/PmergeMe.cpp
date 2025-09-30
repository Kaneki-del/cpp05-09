#include "PmergeMe.hpp"
#include <vector>

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other) {}
PmergeMe &PmergeMe::operator=(const PmergeMe &other) {}

long parseAndValidate(const std::string &str) {
  char *endptr;
  errno = 0;
  long amount = std::strtol(str.c_str(), &endptr, 10);
  if (endptr == str.c_str() || *endptr != '\0' || errno == ERANGE) {
  }

  void processSequence(char **av, int count) {
    std::vector<long> initialSequence;
    for (int i = 0; i < count; ++i) {
      long num = parseAndValidate(av[i]);
      initialSequence.push_back(num);
    }
  }

  void displayUsage() {
    std::cerr << "Error: Usage: ./PmergeMe < positive_integer_sequence > "
              << std::endl;
    std::cerr << "Example: ./PmergeMe 3 5 9 7 4 " << std::endl;
  }
