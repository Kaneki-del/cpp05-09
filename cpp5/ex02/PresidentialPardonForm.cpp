#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::~PresidentialPardonForm() {
  std::cout << "PresidentialPardonForm destructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("defaultPresidentialPardon", 25, 5), target("default") {
  std::cout << "PresidentialPardonForm Default Constructor called."
            << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other)
    : AForm(other), target(other.target) {
  std::cout << "PresidentialPardonForm Copy Constructor called for "
            << std::endl;
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
  if (this != &other) {
    AForm::operator=(other);
    target = other.target;
  }
  return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("defaultPresidentialPardon", 25, 5), target(target) {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  if (!isSigned()) {
    throw AForm::FormNotSignedException();
  }
  if (executor.getGrade() > GetgradeToExecute()) {
    throw AForm::GradeTooLowException();
  }
  std::cout << target << " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
}
