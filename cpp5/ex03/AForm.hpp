#ifndef AFROM_HPP
#define AFROM_HPP

class AForm;
#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <string>

class AForm {
public:
  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Grade is too high!"; }
  };
  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Grade is too low!"; }
  };
  class FormNotSignedException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Form is not signed!"; }
  };
  class FileCreationException : public std::exception {
  public:
    virtual const char *what() const throw() {
      return "Could not create or open file!";
    }
  };
  AForm();
  AForm(const AForm &other);
  virtual ~AForm();
  AForm &operator=(const AForm &other);
  AForm(const std::string &name, int gradeToSign, int gradeToExecute);
  const std::string getName() const;
  bool isSigned() const;
  int GetgradeToSign() const;
  int GetgradeToExecute() const;
  void beSigned(const Bureaucrat &b);
  virtual void execute(Bureaucrat const &executor) const = 0;

private:
  const std::string name;
  bool _isSigned;
  const int _gradeToSign;
  const int _gradeToExecute;
};
std::ostream &operator<<(std::ostream &o, AForm const &rth);
#endif
