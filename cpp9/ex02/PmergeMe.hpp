#ifndef PMERGEME
#define PMERGEME

#include <cerrno>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <vector>

class PmergeMe {
public:
  PmergeMe();
  ~PmergeMe();
  PmergeMe(const PmergeMe &other);
  PmergeMe &operator=(const PmergeMe &other);
  void processSequence(char **av, int count);
  template <typename Container>
  void displaySequence(const Container &seq, const std::string &prefix) {
    std::cout << prefix;

    if (!seq.empty()) {
      std::copy(seq.begin(), seq.end(),
                std::ostream_iterator<typename Container::value_type>(std::cout,
                                                                      " "));
    }
    std::cout << std::endl;
  }

private:
  std::vector<long> _vectorSequence;
  std::deque<long> _dequeSequence;
  long parseAndValidate(const std::string &num);
  void sortVector();
  void sortDeque();
};
void displayUsage();
#endif
