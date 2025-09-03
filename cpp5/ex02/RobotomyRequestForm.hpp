#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"
#include <cstdlib>
class RobotomyRequestForm : public AForm {
public:
  RobotomyRequestForm();
  RobotomyRequestForm(const RobotomyRequestForm &other);
  ~RobotomyRequestForm();
  RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
  RobotomyRequestForm(const std::string &name, int grade);
  void execute(Bureaucrat const &executor) const;

private:
  std::string target;
};
#endif
