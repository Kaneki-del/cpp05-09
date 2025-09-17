
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

class ScalarConverter;
#include <cctype>
#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

enum e_type { CHAR, INT, FLOAT, DOUBLE, UNKNOWN };

class ScalarConverter {
public:
  static void convert(std::string input);

private:
  static e_type getType(std::string input);
  ScalarConverter();
  ScalarConverter(const ScalarConverter &other);
  ~ScalarConverter();
  ScalarConverter &operator=(const ScalarConverter &other);
  bool static isChar(std::string input);
  bool static isInt(std::string input);
  bool static isFloat(std::string input);
  bool static isDouble(std::string input);
  void static printFromChar(char c);
  void static printFromInt(std::string input);
  void static printFromFloat(std::string input);
  void static printFromDouble(std::string input);
  bool static checkINt(std::string i);
};
#endif
