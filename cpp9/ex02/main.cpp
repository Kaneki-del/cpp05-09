#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {
  if (argc < 3) {
    displayUsage();
    return 1;
  }
  try {
    PmergeMe sorter;
    sorter.processSequence(argv + 1, argc - 1);

  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  } catch (...) {
    std::cerr << "An unknown error occurred." << std::endl;
    return 1;
  }
  return 0;
}
