#ifndef PMERGEME
#define PMERGEME

#include <deque>
#include <iostream>
#include <vector>

class PmergeMe {
public:
  PmergeMe();
  ~PmergeMe();
  PmergeMe(const PmergeMe &other);
  PmergeMe &operator=(const PmergeMe &other);
  void processSequence(char **av, int count);

private:
  std::vector<long> _vectorSequence;
  std::deque<long> _dequeSequence;
  long parseAndValidate(const std::string &num);
};
void displayUsage();
#endif
