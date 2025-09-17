#include "ScalarConverter.hpp"

// e_type trueType(std::string input) {
//   int error = 0;
//   long num = std::strtol(input.c_str(), NULL, 10);
//   if (error == ERANGE)
//     return DOUBLE;
//   if (num > std::numeric_limits<int>::max() ||
//       num < std::numeric_limits<int>::min()) {
//     return FLOAT;
//   }
//   return INT;
// }
e_type ScalarConverter::getType(std::string input) {
  if (isChar(input))
    return CHAR;
  else if (isInt(input)) {
    return INT;
  } else if (isFloat(input))
    return FLOAT;
  else if (isDouble(input))
    return DOUBLE;
  return UNKNOWN;
}

void ScalarConverter::convert(std::string input) {
  e_type type = getType(input);
  switch (type) {
  case CHAR:
    printFromChar(input[0]);
    break;
  case INT:
    printFromInt(input);
    break;
  case FLOAT:
    printFromFloat(input);
    break;
  case DOUBLE:
    printFromDouble(input);
    break;
  case UNKNOWN:
    std::cerr << "Error: Invalid input. Not a recognized literal type."
              << std::endl;
    break;
  }
}
