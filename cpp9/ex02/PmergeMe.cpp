/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-nac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 14:28:15 by sait-nac          #+#    #+#             */
/*   Updated: 2025/10/05 14:57:22 by sait-nac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

  largest.clear();
  lowest.clear();

  // sorting pears
  for (unsigned long i = 1; i < contains.size(); i += 2) {
    if (contains[i - 1] < contains[i])
      std::swap(contains[i - 1], contains[i]);
  }

  if (contains.size() % 2 != 0) {
    leftOver = contains.back();
    // contains.pop_back();
  }

  for (unsigned long i = 1; i < contains.size(); i += 2) {
    largest.push_back(contains[i - 1]);
    lowest.push_back(contains[i]);
  }

  if (largest.size() >= 2)
    sortVector(largest);

  if (lowest.size() == 1) {
    largest.insert(std::lower_bound(largest.begin(), largest.end(), lowest[0]),
                   lowest[0]);
  } else {
    std::vector<long long> jacob_sequence =
        generateJacobsthalSequence<std::vector<long long>>(lowest.size() +
                                                           largest.size());
    index = generateindex<std::vector<long long>>(jacob_sequence);

    largest.insert(std::lower_bound(largest.begin(), largest.end(), lowest[0]),
                   lowest[0]);

    for (unsigned long i = 0; i < index.size(); i++) {
      long long calculated_index_ll = index[i] - 1;

      std::size_t calculated_index =
          static_cast<std::size_t>(calculated_index_ll);

      if (calculated_index >= lowest.size()) {
        continue;
      }

      long value_to_insert = lowest[calculated_index];

      std::vector<long>::iterator insert_pos =
          std::lower_bound(largest.begin(), largest.end(), value_to_insert);

      largest.insert(insert_pos, value_to_insert);
    }
  }

  if (leftOver != -1) {
    auto insert_pos =
        std::lower_bound(largest.begin(), largest.end(), leftOver);
    largest.insert(insert_pos, leftOver);
  }

  contains = largest;
}

void PmergeMe::sortDeque(std::deque<long> &contains) {

  long leftOver = -1;
  std::deque<long long> index;
  std::deque<long> largest;
  std::deque<long> lowest;

  largest.clear();
  lowest.clear();

  // sorting pears
  for (unsigned long i = 1; i < contains.size(); i += 2) {
    if (contains[i - 1] < contains[i])
      std::swap(contains[i - 1], contains[i]);
  }

  if (contains.size() % 2 != 0) {
    leftOver = contains.back();
    // contains.pop_back();
  }

  for (unsigned long i = 1; i < contains.size(); i += 2) {
    largest.push_back(contains[i - 1]);
    lowest.push_back(contains[i]);
  }

  if (largest.size() >= 2)
    sortDeque(largest);

  if (lowest.size() == 1) {
    largest.insert(std::lower_bound(largest.begin(), largest.end(), lowest[0]),
                   lowest[0]);
  } else {
    std::deque<long long> jacob_sequence =
        generateJacobsthalSequence<std::deque<long long>>(lowest.size() +
                                                          largest.size());
    index = generateindex<std::deque<long long>>(jacob_sequence);

    largest.insert(std::lower_bound(largest.begin(), largest.end(), lowest[0]),
                   lowest[0]);

    for (unsigned long i = 0; i < index.size(); i++) {
      long long calculated_index_ll = index[i] - 1;

      std::size_t calculated_index =
          static_cast<std::size_t>(calculated_index_ll);

      if (calculated_index >= lowest.size()) {
        continue;
      }

      long value_to_insert = lowest[calculated_index];

      std::deque<long>::iterator insert_pos =
          std::lower_bound(largest.begin(), largest.end(), value_to_insert);

      largest.insert(insert_pos, value_to_insert);
    }
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

void printTimeMeasurement(timeval start, timeval end, size_t size,
                          const std::string &containerType) {
  double duration =
      (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);

  std::cout << "Time to process a range of " << size << " elements with "
            << containerType << " : " << std::fixed << std::setprecision(5)
            << duration << " us" << std::endl;
}

void PmergeMe::processSequence(char **av, int count) {
  struct timeval start_vec;
  struct timeval end_vec;
  struct timeval start_deque;
  struct timeval end_deque;
  std::vector<long> initialSequence;
  for (int i = 0; i < count; ++i) {
    long num = parseAndValidate(av[i]);
    initialSequence.push_back(num);
  }

  _vectorSequence.assign(initialSequence.begin(), initialSequence.end());
  _dequeSequence.assign(initialSequence.begin(), initialSequence.end());

  displaySequence(_vectorSequence, "Before: ");
  gettimeofday(&start_vec, NULL);
  sortVector(_vectorSequence);
  gettimeofday(&end_vec, NULL);

  displaySequence(_vectorSequence, "After: ");

  gettimeofday(&start_deque, NULL);
  sortDeque(_dequeSequence);
  gettimeofday(&end_deque, NULL);
  printTimeMeasurement(start_vec, end_vec, _vectorSequence.size(),
                       "std::vector");

  printTimeMeasurement(start_deque, end_deque, _dequeSequence.size(),
                       "std::deque");
}

void displayUsage() {
  std::cerr << "Error: Usage: ./PmergeMe < positive_integer_sequence > "
            << std::endl;
  std::cerr << "Example: ./PmergeMe 3 5 9 7 4 " << std::endl;
}
