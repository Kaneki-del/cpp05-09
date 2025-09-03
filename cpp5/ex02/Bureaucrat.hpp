#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

class Bureaucrat;
#include "AForm.hpp"
#include <exception>
#include <iostream>
#include <string>

class Bureaucrat {

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Grade is too high!"; }
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Grade is too low!"; }
  };

public:
  Bureaucrat();
  Bureaucrat(const Bureaucrat &other);
  ~Bureaucrat();
  Bureaucrat &operator=(const Bureaucrat &other);
  Bureaucrat(const std::string &name, int grade);
  const std::string getName() const;
  int getGrade() const;
  void increment();
  void decrement();
  void signForm(AForm &f);

private:
  const std::string name;
  int grade;
};
std::ostream &operator<<(std::ostream &o, Bureaucrat const &rth);
#endif
