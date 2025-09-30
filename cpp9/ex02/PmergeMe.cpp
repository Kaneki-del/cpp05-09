#include "PmergeMe.hpp"
#include <vector>

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
    : _vectorSequence(other._vectorSequence),
      _dequeSequence(other._dequeSequence) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
  if (this != &other) {
    _vectorSequence = other._vectorSequence;
    _dequeSequence = other._dequeSequence;
  }
  return *this;
}

void PmergeMe::sortVector() {
  // first check the size if not pair to remove the last element and have it
  // ther
  //  sort the pairs that explained from the guide  by swaping theme
  //  split the the smal one and the largest one in two container
  //  generate the squenece and try to implement the insertion
}

long PmergeMe::parseAndValidate(const std::string &str) {
  const char *nptr = str.c_str();
  char *endptr;
  errno = 0;
  long amount = std::strtol(nptr, &endptr, 10);

  if (endptr == nptr) {
    throw std::invalid_argument("Error: Input is not a valid number.");
  }
  if (*endptr != '\0') {
    throw std::invalid_argument(
        "Error: Input contains non-numeric characters.");
  }
  if (errno == ERANGE) {
    throw std::out_of_range(
        "Error: Number exceeds the system's long integer range.");
  }
  if (amount < 1) {
    throw std::invalid_argument(
        "Error: Input must be a positive integer (>= 1).");
  }
  if (amount > std::numeric_limits<int>::max()) {
    throw std::out_of_range(
        "Error: Number exceeds the allowed max integer value (INT_MAX).");
  }
  return amount;
}
void PmergeMe::processSequence(char **av, int count) {
  std::vector<long> initialSequence;
  for (int i = 0; i < count; ++i) {
    long num = parseAndValidate(av[i]);
    initialSequence.push_back(num);
  }
  displaySequence(initialSequence, "Before: ");

  _vectorSequence.assign(initialSequence.begin(), initialSequence.end());
  _dequeSequence.assign(initialSequence.begin(), initialSequence.end());

  sortVector();
}

void displayUsage() {
  std::cerr << "Error: Usage: ./PmergeMe < positive_integer_sequence > "
            << std::endl;
  std::cerr << "Example: ./PmergeMe 3 5 9 7 4 " << std::endl;
}
