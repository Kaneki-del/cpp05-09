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

void PmergeMe::sortVector(std::vector<long> &contains) {
  long leftOver = -1;
  std::vector<long long> index;
  std::vector<long> largest;
  std::vector<long> lowest;

  for (unsigned long i = 1; i < contains.size(); i += 2) {
    if (contains[i - 1] < contains[i])
      std::swap(contains[i - 1], contains[i]);
  }

  if (contains.size() % 2 != 0) {
    leftOver = contains.back();
    contains.pop_back();
  }

  for (unsigned long i = 1; i < contains.size(); i += 2) {
    largest.push_back(contains[i - 1]);
    lowest.push_back(contains[i]);
  }

  if (largest.size() >= 2)
    sortVector(largest);

  if (!lowest.empty()) {
    largest.insert(largest.begin(), lowest.front());
    lowest.erase(lowest.begin());
  }

  std::vector<long long> jacob_sequence =
      generateJacobsthalSequence<std::vector<long long>>(lowest.size());

  index = generateindex<std::vector<long long>>(jacob_sequence);

  for (unsigned long i = 0; i < index.size(); i++) {
    long long calculated_index_ll = index[i] - 2;

    if (calculated_index_ll < 0)
      continue;

    std::size_t calculated_index =
        static_cast<std::size_t>(calculated_index_ll);

    if (calculated_index >= lowest.size())
      continue;

    long value_to_insert = lowest[calculated_index];

    std::vector<long>::iterator insert_pos =
        std::lower_bound(largest.begin(), largest.end(), value_to_insert);

    largest.insert(insert_pos, value_to_insert);
  }

  if (leftOver != -1) {
    auto insert_pos =
        std::lower_bound(largest.begin(), largest.end(), leftOver);
    largest.insert(insert_pos, leftOver);
  }

  contains = largest;
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
  // displaySequence(initialSequence, "Before: ");

  _vectorSequence.assign(initialSequence.begin(), initialSequence.end());
  _dequeSequence.assign(initialSequence.begin(), initialSequence.end());

  // displaySequence(_vectorSequence, "Before: ");
  sortVector(_vectorSequence);
  _vectorSequence.push_back(-1);
  displaySequence(_vectorSequence, "After: ");
}

void displayUsage() {
  std::cerr << "Error: Usage: ./PmergeMe < positive_integer_sequence > "
            << std::endl;
  std::cerr << "Example: ./PmergeMe 3 5 9 7 4 " << std::endl;
}
