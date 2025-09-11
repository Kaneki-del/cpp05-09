#include "ScalarConverter.hpp"

int getType(std::string input){
  int value;
  if (isChar(input))
    return CHAR_TYPE;
  else if (isFloat(input))
    return FLOAT_TYPE;
  else if (isDouble(input))
    return DOUBLE_TYPE;
  else if (isInt(input))
    return INT_TYPE;
  return UNKNOWN_TYPE;

}
void ScalarConverter::convert(std::string input){
  int type = getType(input);  
}
