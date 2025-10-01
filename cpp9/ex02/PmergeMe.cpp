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
int PmergeMe::getJacobsthalNumber(int n) {

  if (n == 0)
    return 0;

  if (n == 1)
    return 1;

  return getJacobsthalNumber(n - 1) + 2 * getJacobsthalNumber(n - 2);
}

void PmergeMe::sortVector() {
  long leftOver = -1;
  std::vector<long> largest;
  std::vector<long long> index;
  std::vector<long> lowest;
  if (_vectorSequence.size() % 2 != 0) {
    leftOver = _vectorSequence.back();
    _vectorSequence.pop_back();
  }
  for (unsigned long i = 1; i < _vectorSequence.size(); i += 2) {
    if (_vectorSequence[i - 1] < _vectorSequence[i])
      std::swap(_vectorSequence[i - 1], _vectorSequence[i]);
  }
  displaySequence(_vectorSequence, "after: ");
  for (unsigned long i = 1; i < _vectorSequence.size(); i += 2) {
    largest.push_back(_vectorSequence[i - 1]);
    lowest.push_back(_vectorSequence[i]);
  }
  // displaySequence(largest, "largest: ");
  // displaySequence(lowest, "lowest: ");
  std::vector<long long> jacob_sequence =
      generateJacobsthalSequence<std::vector<long long>>(lowest.size());

  displaySequence(jacob_sequence, "sequence: ");
  index = generateindex<std::vector<long long>>(jacob_sequence);
  displaySequence(index, "index: ");
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
