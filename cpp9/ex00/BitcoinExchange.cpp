#include "BitcoinExchange.hpp"
#include <iostream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
    : exchange_rates(other.exchange_rates) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
  if (this != &other) {
    exchange_rates = other.exchange_rates;
  }
  return *this;
}

std::string trim(const std::string &str) {
  size_t first = str.find_first_not_of(" \t\n\r");
  if (std::string::npos == first) {
    return str;
  }
  size_t last = str.find_last_not_of(" \t\n\r");
  return str.substr(first, (last - first + 1));
}

BitcoinExchange::BitcoinExchange(const std::string &db_filename) {

  std::ifstream db_file(db_filename.c_str());
  if (!db_file.is_open()) {
    throw std::runtime_error("Error: could not open database file.");
  }
  std::string line;
  std::getline(db_file, line);

  if (trim(line) != "date,exchange_rate") {
    throw std::runtime_error("Error: database file dont have header.");
  }

  while (getline(db_file, line)) {
    size_t delimiter_pos = line.find(',');
    std::string date_key = line.substr(0, delimiter_pos);
    std::string rate_str = line.substr(delimiter_pos + 1);
    double exchange_rate;
    exchange_rate = std::strtod(rate_str.c_str(), NULL);
    this->exchange_rates[date_key] = exchange_rate;
  }
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

bool BitcoinExchange::isValidDate(const std::string &date) {

  std::stringstream ss(date);
  int i = 0;
  splitedStr splitedDate;
  std::string segment;
  char *endptr;

  if (date.length() != 10) {
    return false;
  }

  while (std::getline(ss, segment, '-') && i < 3) {
    splitedDate.strHolder[i] = segment;
    i++;
  }

  if (i != 3 || !ss.eof())
    return false;
  long year, month, day;

  year = std::strtol(splitedDate.strHolder[0].c_str(), &endptr, 10);
  if (*endptr != '\0' || year < 2000)
    return false;

  month = std::strtol(splitedDate.strHolder[1].c_str(), &endptr, 10);
  if (*endptr != '\0' || month < 1 || month > 12)
    return false;

  day = std::strtol(splitedDate.strHolder[2].c_str(), &endptr, 10);
  if (*endptr != '\0' || day < 1 || day > 31)
    return false;

  struct tm time_struct = {};
  time_struct.tm_year = year - 1900;
  time_struct.tm_mon = month - 1;
  time_struct.tm_mday = day;
  time_struct.tm_isdst = -1;

  int original_month = time_struct.tm_mon;
  int original_day = time_struct.tm_mday;

  if (std::mktime(&time_struct) == (std::time_t)-1) {
    return false;
  }

  if (time_struct.tm_mon != original_month ||
      time_struct.tm_mday != original_day) {
    return false;
  }

  if (time_struct.tm_year + 1900 < 2000) {
    return false;
  }

  return true;
}

void BitcoinExchange::processInputFile(const std::string &input_filename) {

  std::ifstream input(input_filename.c_str());

  if (!input.is_open()) {
    throw std::runtime_error("Error: could not open input file.");
  }

  std::string line;
  char *endptr;
  errno = 0;

  std::getline(input, line);

  if (trim(line) != "date | value") {
    throw std::runtime_error("Error: input file dont have header.");
  }

  while (getline(input, line)) {

    size_t delimiter_pos = line.find('|');
    if (delimiter_pos == std::string::npos) {
      std::cerr << "Error: bad input => " << line << std::endl;
      continue;
    }
    std::string date = line.substr(0, delimiter_pos);
    std::string value = line.substr(delimiter_pos + 1);
    date = trim(date);

    if (!isValidDate(date)) {
      std::cerr << "Error: bad input (invalid date) => " << date << std::endl;
      continue;
    }

    value = trim(value);
    double amount = std::strtod(value.c_str(), &endptr);

    if (endptr == value.c_str() || *endptr != '\0' || errno == ERANGE) {
      std::cerr << "Error: bad input (invalid amount format) => " << line
                << std::endl;
      continue;
    }

    if (amount < 0) {
      std::cerr << "Error: not a positive number." << std::endl;
      continue;
    }

    if (amount > 1000) {
      std::cerr << "Error: too large a number." << std::endl;
      continue;
    }
    double result = amount * getRate(date);
    std::cout << date << " => " << value << " = " << result << std::endl;
  }
}
