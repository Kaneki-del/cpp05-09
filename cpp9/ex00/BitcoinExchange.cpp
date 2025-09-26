#include "BitcoinExchange.hpp"
#include <iostream>

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const std::string &db_filename) {
  std::ifstream db_file(db_filename.c_str());
  if (!db_file.is_open()) {
    throw std::runtime_error("Error: could not open database file.");
  }
  std::string line;
  std::getline(db_file, line);
  while (getline(db_file, line)) {
    size_t delimiter_pos = line.find(',');
    std::string date_key = line.substr(0, delimiter_pos);
    std::string rate_str = line.substr(delimiter_pos + 1);
    double exchange_rate;
    exchange_rate = std::stod(rate_str);
    this->exchange_rates[date_key] = exchange_rate;
  }
}
std::string trim(const std::string &str) {
  size_t first = str.find_first_not_of(" \t\n\r");
  if (std::string::npos == first) {
    return str;
  }
  size_t last = str.find_last_not_of(" \t\n\r");
  return str.substr(first, (last - first + 1));
}

double BitcoinExchange::getRate(const std::string &date) {
  std::map<std::string, double>::const_iterator it = exchange_rates.find(date);

  if (it != exchange_rates.end()) {
    return it->second;
  }
  it = exchange_rates.upper_bound(date);
  if (it == exchange_rates.begin()) {
    std::cerr << "Warning: No date found before " << date << ". Using rate 0."
              << std::endl;
    return 0.0;
  }
  it--;
  return it->second;
}

void BitcoinExchange::processInputFile(const std::string &input_filename) {
  std::ifstream input(input_filename.c_str());
  if (!input.is_open()) {
    throw std::runtime_error("Error: could not open input file.");
  }
  std::string line;
  std::getline(input, line);

  while (getline(input, line)) {
    size_t delimiter_pos = line.find('|');
    if (delimiter_pos == std::string::npos) {
      std::cerr << "Error: bad input => " << line << std::endl;
      continue;
    }
    std::string date = line.substr(0, delimiter_pos);
    std::string value = line.substr(delimiter_pos + 1);
    date = trim(date);
    value = trim(value);
    double amount;
    try {
      amount = std::stod(value);

    } catch (const std::exception &e) {
      std::cerr << "Error: bad input => " << line << std::endl;
      return;
    }
    if (amount < 0) {
      std::cerr << "Error: not a positive number." << std::endl;
      return;
    }
    if (amount > 1000) {
      std::cerr << "Error: too large a number." << std::endl;
      return;
    }
    double result = amount * getRate(date);
    std::cout << date << "=>" << value << result << std::endl;
  }
}
