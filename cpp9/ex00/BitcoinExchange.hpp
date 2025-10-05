#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

struct splitedStr {
  std::string strHolder[3];
};

class BitcoinExchange {
public:
  BitcoinExchange();
  ~BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &other);
  BitcoinExchange &operator=(const BitcoinExchange &other);
  BitcoinExchange(const std::string &db_filename);
  void processInputFile(const std::string &input_filename);

private:
  std::map<std::string, double> exchange_rates;
  bool isValidDate(const std::string &date);
  bool isValidValue(double value);
  double getRate(const std::string &date);
};
#endif
