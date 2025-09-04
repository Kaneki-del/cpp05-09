#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
public:
  Intern();
  Intern(const Intern &other);
  virtual ~Intern();
  Intern &operator=(const Intern &other);
  AForm *makeForm(const std::string &formName, const std::string &targetName);

private:
  static AForm *createShrubberyForm(const std::string &target);
  static AForm *createRobotomyForm(const std::string &target);
  static AForm *createPresidentialPardonForm(const std::string &target);
};
#endif
