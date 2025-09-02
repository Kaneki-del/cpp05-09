#ifndef FROM_HPP
#define FROM_HPP

class Form;
#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <string>

class Form {
  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Grade is too high!"; }
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Grade is too low!"; }
  };

public:
  Form();
  Form(const Form &other);
  ~Form();
  Form &operator=(const Form &other);
  Form(const std::string &name, int gradeToSign, int gradeToExecute);
  const std::string getName() const;
  bool isSigned() const;
  int GetgradeToSign() const;
  int GetgradeToExecute() const;
  void beSigned(const Bureaucrat &b);

private:
  const std::string name;
  bool _isSigned;
  const int _gradeToSign;
  const int _gradeToExecute;
};
std::ostream &operator<<(std::ostream &o, Form const &rth);
#endif
