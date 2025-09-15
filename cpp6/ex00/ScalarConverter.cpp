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

void printFromInt(int i) {
  if (i > 127 || i < 0)
    std::cout << "char: impossible" << std::endl;
  else if (!isprint(i))
    std::cout << "char: Non displayable" << std::endl;
  else
    std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
  std::cout << "int: " << i << std::endl;
  std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
  std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void printFromFloat(float f) {
  if (std::isinf(f) || std::isnan(f) || f < std::numeric_limits<char>::min() ||
      f > std::numeric_limits<char>::max()) {
    std::cout << "char: impossible" << std::endl;
  } else if (!isprint(static_cast<char>(f))) {
    std::cout << "char: Non displayable" << std::endl;
  } else {
    std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
  }

  if (std::isinf(f) || std::isnan(f))
    std::cout << "int: impossible" << std::endl;
  else {
    std::cout << "int: " << static_cast<int>(f) << std::endl;
  }

  if (std::isinf(f)) {
    if (std::signbit(f))
      std::cout << "float: -inff" << std::endl;
    else
      std::cout << "float: +inff" << std::endl;
  } else if (std::isnan(f)) {
    std::cout << "float: nanf" << std::endl;
  } else {
    std::cout << "float: " << f << "f" << std::endl;
  }
  if (std::isinf(f)) {
    if (std::signbit(f))
      std::cout << "double: -inf" << std::endl;
    else
      std::cout << "double: +inf" << std::endl;
  } else if (std::isnan(f)) {
    std::cout << "double: nan" << std::endl;
  } else {
    std::cout << "double: " << static_cast<double>(f) << std::endl;
  }
}

void printFromDouble(double d) {
  if (std::isinf(d) || std::isnan(d) || d < std::numeric_limits<char>::min() ||
      d > std::numeric_limits<char>::max()) {
    std::cout << "char: impossible" << std::endl;
  } else if (!isprint(static_cast<char>(d))) {
    std::cout << "char: Non displayable" << std::endl;
  } else {
    std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
  }

  if (std::isinf(d) || std::isnan(d))
    std::cout << "int: impossible" << std::endl;
  else {
    std::cout << "int: " << static_cast<int>(d) << std::endl;
  }

  if (std::isinf(d)) {
    if (std::signbit(d))
      std::cout << "float: -inff" << std::endl;
    else
      std::cout << "float: +inff" << std::endl;
  } else if (std::isnan(d)) {
    std::cout << "float: nanf" << std::endl;
  } else {
    std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
  }
  if (std::isinf(d)) {
    if (std::signbit(d))
      std::cout << "double: -inf" << std::endl;
    else
      std::cout << "double: +inf" << std::endl;
  } else if (std::isnan(d)) {
    std::cout << "double: nan" << std::endl;
  } else {
    std::cout << "double: " << d << std::endl;
  }
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

int ScalarConverter::getType(std::string input) {
  if (isChar(input))
    return CHAR_TYPE;
  else if (isInt(input))
    return INT_TYPE;
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
    printFromInt(atoi(input.c_str()));
    break;
  case FLOAT_TYPE:
    printFromFloat(strtof(input.c_str(), NULL));
    break;
    char *end;
  case DOUBLE_TYPE:
    printFromDouble(strtod(input.c_str(), &end));
    break;
  }
}
