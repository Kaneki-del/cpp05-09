#include "ScalarConverter.hpp"

int isChar(std::string input) {
  if (input.length() == 1 && !isdigit(input[0]))
    return 1;
  return 0;
}

int isInt(std::string input) {
  int i = 0;
  if (!input.empty()) {
    if (input[i] == '+' || input[i] == '-')
      i++;
    for (; i < input.length(); i++) {
      if (!isdigit(input[i]))
        return 0;
    }

    return 1;
  }
  return 0; // check if here we shoud have an error message
}

int isFloat(std::string input) {
  int i = 0;
  if (!input.empty()) {
    if (input[i] == '+' || input[i] == '-')
      i++;
    for (; i < input.length(); i++) {
      if (!isdigit(input[i]) && input[i] != '.')
        return 0;
      if (input[i] == '.')
        if (input[input.length() - 1] != 'f')
          return 0;
    }
    return 1;
  }
  return 0; // check if here we shoud have an error message
}

int isDouble(std::string input) {
  int i = 0;
  if (!input.empty()) {
    if (input[i] == '+' || input[i] == '-')
      i++;
    for (; i < input.length(); i++) {
      if (!isdigit(input[i]) && input[i] != '.')
        return 0;
    }
    return 1;
  }
  return 0; // check if here we shoud have an error message
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
    std::cout << "a char type" << std::endl;
    break;
  case INT_TYPE:
    std::cout << "a int type" << std::endl;
    // print the char type etc
    break;
  case FLOAT_TYPE:
    std::cout << "a float type" << std::endl;
    // print the char type etc
    break;
  case DOUBLE_TYPE:
    std::cout << "a doble type" << std::endl;
    // print the char type etc
    break;
  }
}
// cin
