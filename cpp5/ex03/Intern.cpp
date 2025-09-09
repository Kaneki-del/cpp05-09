#include "Intern.hpp"

Intern::~Intern() { std::cout << "Intern destructor called." << std::endl; }

Intern::Intern() {
  std::cout << "Intern Default Constructor called." << std::endl;
}

Intern::Intern(const Intern &other) {
  (void)other;
}

Intern &Intern::operator=(const Intern &other) {
  (void)other;
  return *this;
}

AForm *Intern::createShrubberyForm(const std::string &target) {
  return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyForm(const std::string &target) {
  return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(const std::string &target) {
  return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName,
                        const std::string &targetName) {
  const std::string formsNames[] = {"shrubbery creation", "robotomy request",
                                    "presidential pardon"};
  AForm *(*forms[])(const std::string &) = {
      &Intern::createShrubberyForm, &Intern::createRobotomyForm,
      &Intern::createPresidentialPardonForm};

  for (int i = 0; i < 3; i++) {
    if (formsNames[i] == formName) {
      std::cout << "Intern creates " << formName << std::endl;
      return forms[i](targetName);
    }
  }
  std::cerr << "Error: Intern couldn’t create form " << formName
            << " because the form name does not exist." << std::endl;
  return NULL;
}
