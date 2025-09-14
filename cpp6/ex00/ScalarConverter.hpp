
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

class ScalarConverter;
#include <iostream>
#include <string>

#define CHAR_TYPE 2
#define INT_TYPE 3
#define FLOAT_TYPE 4
#define DOUBLE_TYPE 5
#define UNKNOWN_TYPE 6

class ScalarConverter {
public:
  static void convert(std::string input);

private:
  static int getType(std::string input);
  ScalarConverter();
  ScalarConverter(const ScalarConverter &other);
  ~ScalarConverter();
  ScalarConverter &operator=(const ScalarConverter &other);
};
#endif
