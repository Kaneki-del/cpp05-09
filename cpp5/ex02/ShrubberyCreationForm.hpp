
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
class ShrubberyCreationForm : public AForm {
public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(const ShrubberyCreationForm &other);
  ~ShrubberyCreationForm();
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
  ShrubberyCreationForm(const std::string &name, int grade);
  void execute(Bureaucrat const &executor) const;

private:
  std::string target;
};
#endif
