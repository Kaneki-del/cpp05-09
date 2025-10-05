#ifndef PMERGEME
#define PMERGEME

#include <cerrno>
#include <deque>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <sys/time.h>
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
  template <typename Container>
  Container generateJacobsthalSequence(std::size_t lent) {

    Container sequence;

    for (size_t i = 3; i < lent; i++) {

      size_t jacob = getJacobsthalNumber(i);

      if (jacob > lent) {

        sequence.push_back(jacob);

        break;
      }
      sequence.push_back(jacob);
    }
    return sequence;
  }

  template <typename Container> Container generateindex(Container sequence) {
    Container index;
    index.push_back(3);
    index.push_back(2);
    for (unsigned long i = 1; i < sequence.size(); i++) {
      for (long y = sequence[i]; y > sequence[i - 1]; y--) {
        index.push_back(y);
      }
    }
    return index;
  }

private:
  std::vector<long> _vectorSequence;
  std::deque<long> _dequeSequence;
  long parseAndValidate(const std::string &num);
  void sortVector(std::vector<long> &contains);
  void sortDeque(std::deque<long> &contains);
  int getJacobsthalNumber(int n);
};
void displayUsage();
#endif
