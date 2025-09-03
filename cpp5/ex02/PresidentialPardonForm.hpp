#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
  PresidentialPardonForm();
  PresidentialPardonForm(const PresidentialPardonForm &other);
  ~PresidentialPardonForm();
  PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
  PresidentialPardonForm(const std::string &name, int grade);
  void execute(Bureaucrat const &executor) const;

private:
  std::string target;
};
#endif
