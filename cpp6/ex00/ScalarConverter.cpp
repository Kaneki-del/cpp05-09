#include "ScalarConverter.hpp"
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

void printFromChar(char c) {
  std::cout << "char: ";
  if (isprint(c))
    std::cout << c << std::endl;
  else
    std::cout << "Non displayable" << std::endl;
  std::cout << "int: " << static_cast<int>(c) << std::endl;
  std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
  std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void printFromInt(std::string input) {
  int num = std::atoi(input.c_str());
  if (std::numeric_limits<char>::min() > num ||
      std::numeric_limits<char>::max() < num)
    std::cout << "impossible" << std::endl;

  else if (!isprint(num))
    std::cout << "char: Non displayable" << std::endl;
  else
    std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
  std::cout << "int: " << num << std::endl;
  std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
  std::cout << "double: " << static_cast<double>(num) << std::endl;
}

void printFromFloat(std::string input) {
  float num = std::strtof(input.c_str(), NULL);
  int error = 0;
  if (std::numeric_limits<char>::min() > num ||
      std::numeric_limits<char>::max() < num)
    std::cout << "impossible" << std::endl;

  else if (!isprint(num))
    std::cout << "char: Non displayable" << std::endl;
  else
    std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
  if (error == ERANGE)
    std::cout << "float: impossible" << std::endl;

  if (std::isinf(num) || std::isnan(num) ||
      std::numeric_limits<int>::min() > static_cast<int>(num) ||
      std::numeric_limits<int>::max() < static_cast<int>(num))
    std::cout << "int: impossible" << std::endl;
  else {
    std::cout << "int: " << static_cast<int>(num) << std::endl;
  }
  std::cout << "float: " << num << "f" << std::endl;
  std::cout << "double: " << static_cast<double>(num) << std::endl;
}

void printFromDouble(std::string input) {
  double d = std::strtod(input.c_str(), NULL);

  if (std::numeric_limits<char>::min() > d ||
      std::numeric_limits<char>::max() < d)
    std::cout << "impossible" << std::endl;
  else if (!isprint(d))
    std::cout << "char: Non displayable" << std::endl;
  else
    std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

  if (std::isinf(d) || std::isnan(d) ||
      std::numeric_limits<int>::min() > static_cast<int>(d) ||
      std::numeric_limits<int>::max() < static_cast<int>(d))
    std::cout << "int: impossible" << std::endl;
  else {
    std::cout << "int: " << static_cast<int>(d) << std::endl;
  }
  std::cout << "float: " << static_cast<double>(d) << "f" << std::endl;
  std::cout << "double: " << d << std::endl;
}

bool isChar(std::string input) {
  if (input.length() == 1 && !isdigit(input[0]))
    return true;
  return false;
}

bool isInt(std::string input) {
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

bool isFloat(std::string input) {
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

bool isDouble(std::string input) {
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

int trueType(std::string input) {
  int error = 0;
  long num = std::strtol(input.c_str(), NULL, 10);
  if (error == ERANGE)
    return DOUBLE_TYPE;
  if (num > std::numeric_limits<int>::max() ||
      num < std::numeric_limits<int>::min()) {
    return FLOAT_TYPE;
  }
  return INT_TYPE;
}
int ScalarConverter::getType(std::string input) {
  if (isChar(input))
    return CHAR_TYPE;
  else if (isInt(input))
    return trueType(input);
  else if (isFloat(input))
    return FLOAT_TYPE;
  else if (isDouble(input))
    return DOUBLE_TYPE;
  return UNKNOWN_TYPE;
}

void ScalarConverter::convert(std::string input) {
  int type = getType(input);
  switch (type) {
  case CHAR_TYPE:
    printFromChar(input[0]);
    break;
  case INT_TYPE:
    printFromInt(input);
    break;
  case FLOAT_TYPE:
    printFromFloat(input);
    break;
  case DOUBLE_TYPE:
    printFromDouble(input);
    break;
  }
}
