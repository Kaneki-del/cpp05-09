#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::~ShrubberyCreationForm() {
  std::cout << "ShrubberyCreationForm destructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
  : AForm("defaultShrubbery", 145, 137), target(target){
}

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("defaultShrubbery", 145, 137), target("default") {

  std::cout << "ShrubberyCreationForm Default Constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target(other.target) {
  std::cout << "ShrubberyCreationForm Copy Constructor called for "
            << std::endl;
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
  if (this != &other) {
    AForm::operator=(other);
    target = other.target;
  }
  return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {

  if (!isSigned())
    throw AForm::FormNotSignedException();
  if (executor.getGrade() > GetgradeToExecute())
    throw AForm::GradeTooLowException();
  std::string filename = this->target + "_shrubbery";
  std::ofstream outFile(filename.c_str());

  if (!outFile.is_open()) {
    throw AForm::FileCreationException();
  }

  outFile << "    /\\    \n";
  outFile << "   /  \\   \n";
  outFile << "  /    \\  \n";
  outFile << " /______\\ \n";
  outFile << "    ||    \n";
  outFile << "    ||    \n";
  outFile.close();
  std::cout << "Shrubbery creation form executed. File '" << filename
            << "' created." << std::endl;
}
