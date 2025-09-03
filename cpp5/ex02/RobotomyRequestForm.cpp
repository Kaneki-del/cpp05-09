#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::~RobotomyRequestForm() {
  std::cout << "RobotomyRequestForm destructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("defaultRobotomyRequest", 72, 45), target("default") {

  std::cout << "RobotomyRequestForm Default Constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), target(other.target) {
  std::cout << "RobotomyRequestForm Copy Constructor called for " << std::endl;
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
  if (this != &other) {
    AForm::operator=(other);
    target = other.target;
  }
  return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  if (!isSigned()) {
    throw AForm::FormNotSignedException();
  }
  if (executor.getGrade() > GetgradeToExecute()) {
    throw AForm::GradeTooLowException();
  }

  std::cout << "Drilling noises... Bzzzzzzzzzzzz!" << std::endl;
  int randomNumber = rand() % 2;

  if (randomNumber == 0) {
    std::cout << target << " has been robotomized successfully." << std::endl;
  } else {
    std::cout << "The robotomy failed." << std::endl;
  }
}
