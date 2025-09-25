#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <fstream>
#include <iostream>
#include <map>
#include <string>

class BitcoinExchange {
public:
  BitcoinExchange();
  ~BitcoinExchange();
  BitcoinExchange(const std::string &db_filename);
  void processInputFile(const std::string &input_filename);

private:
  std::map<std::string, double> exchange_rates;
  bool isValidDate(const std::string &date);
  bool isValidValue(double value);
  double getRate(const std::string &date);
};
#endif
