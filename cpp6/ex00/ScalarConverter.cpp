#include "ScalarConverter.hpp"
#include <cctype>

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

// printFromInt(int i)

// printFromFloat(float f)

// printFromDouble(double d)

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
    std::cout << "a int type" << std::endl;
    break;
  case FLOAT_TYPE:
    std::cout << "a float type" << std::endl;
    break;
  case DOUBLE_TYPE:
    std::cout << "a doble type" << std::endl;
    break;
  }
}
