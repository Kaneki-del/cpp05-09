#include "ScalarConverter.hpp"
#include <cerrno>

bool ScalarConverter::checkINt(std::string i) {
  errno = 0;
  long num = std::strtol(i.c_str(), NULL, 10);
  if (((num == std::numeric_limits<long>::max() ||
        num == std::numeric_limits<long>::min()) &&
       errno == ERANGE) ||
      num > std::numeric_limits<int>::max() ||
      num < std::numeric_limits<int>::min()) {
    return true;
  }
  return false;
}
void ScalarConverter::printFromChar(char c) {
  std::cout << "char: ";
  if (isprint(c))
    std::cout << c << std::endl;
  else
    std::cout << "char: Non displayable" << std::endl;
  std::cout << "int: " << static_cast<int>(c) << std::endl;
  std::cout << "float: " << std::fixed << std::setprecision(1)
            << static_cast<float>(c) << "f" << std::endl;
  std::cout << "double: " << std::fixed << std::setprecision(1)
            << static_cast<double>(c) << std::endl;
}

void ScalarConverter::printFromInt(std::string input) {
  int num = std::atoi(input.c_str());

  if (checkINt(input) || std::numeric_limits<char>::min() > num ||
      std::numeric_limits<char>::max() < num)
    std::cout << "char: impossible" << std::endl;

  else if (!isprint(num))
    std::cout << "char: Non displayable" << std::endl;
  else
    std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
  if (checkINt(input))
    std::cout << "int: impossible" << std::endl;
  else {
    std::cout << "int: " << num << std::endl;
  }
  std::cout << "float: " << std::fixed << std::setprecision(1)
            << static_cast<float>(num) << "f" << std::endl;
  std::cout << "double: " << std::fixed << std::setprecision(1)
            << static_cast<double>(num) << std::endl;
}

void ScalarConverter::printFromFloat(std::string input) {
  float f = std::strtof(input.c_str(), NULL);
  if (std::isinf(f) || std::isnan(f) || std::numeric_limits<char>::min() > f ||
      std::numeric_limits<char>::max() < f)
    std::cout << "char: impossible" << std::endl;

  else if (!isprint(f))
    std::cout << "char: Non displayable" << std::endl;
  else
    std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
  if (std::isinf(f) || std::isnan(f) || checkINt(input))
    std::cout << "int: impossible" << std::endl;
  else
    std::cout << "int: " << static_cast<int>(f) << std::endl;
  errno = 0;
  if (errno == ERANGE)
    std::cout << "float: impossible" << std::endl;
  else
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f"
              << std::endl;
  std::cout << "double: " << std::fixed << std::setprecision(1)
            << static_cast<double>(f) << std::endl;
}

void ScalarConverter::printFromDouble(std::string input) {
  double d = std::strtod(input.c_str(), NULL);

  if (std::isinf(d) || std::isnan(d) || std::numeric_limits<char>::min() > d ||
      std::numeric_limits<char>::max() < d)
    std::cout << "char: impossible" << std::endl;
  else if (!isprint(d))
    std::cout << "char: Non displayable" << std::endl;
  else
    std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
  if (std::isinf(d) || std::isnan(d) || checkINt(input))
    std::cout << "int: impossible" << std::endl;
  else {
    std::cout << "int: " << static_cast<int>(d) << std::endl;
  }
  std::cout << "float: " << std::fixed << std::setprecision(1)
            << static_cast<float>(d) << "f" << std::endl;
  std::cout << "double: " << std::fixed << std::setprecision(1) << d
            << std::endl;
}

bool ScalarConverter::isChar(std::string input) {
  if (input.length() == 1 && !isdigit(input[0]))
    return true;
  return false;
}

bool ScalarConverter::isInt(std::string input) {
  unsigned int i = 0;
  if (input.empty())
    return false;
  if (input[i] == '+' || input[i] == '-')
    i++;
  for (; i < input.length(); i++) {

    if (!isdigit(input[i]))
      return false;
  }
  return true;
}

bool ScalarConverter::isFloat(std::string input) {
  unsigned int i = 0;
  int doteCount = 0;
  if (input.empty()) {
    return false;
  }
  if (input == "nanf" || input == "+inff" || input == "-inff") {
    return true;
  }
  if (input[i] == '+' || input[i] == '-')
    i++;
  for (; i < input.length(); i++) {
    if (input[i] == '.')
      doteCount++;
    else if (input[i] != 'f' && !isdigit(input[i]))
      return false;
  }
  if (doteCount == 1 && input[input.length() - 1] == 'f')
    return true;
  return false;
}

bool ScalarConverter::isDouble(std::string input) {
  unsigned int i = 0;
  int doteCount = 0;
  if (input.empty()) {
    return false;
  }
  if (input == "nan" || input == "+inf" || input == "-inf") {
    return true;
  }
  if (input[i] == '+' || input[i] == '-')
    i++;
  for (; i < input.length(); i++) {
    if (input[i] == '.')
      doteCount++;
    else if (!isdigit(input[i]))
      return false;
  }
  if (doteCount == 1)
    return true;
  return false;
}
