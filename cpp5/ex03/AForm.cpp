#include "AForm.hpp"

AForm::~AForm() { std::cout << "AForm destructor called." << std::endl; }

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), _isSigned(false), _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute) {
  if (this->_gradeToSign < 1 || this->_gradeToExecute < 1) {
    throw GradeTooHighException();
  }
  if (this->_gradeToSign > 150 || this->_gradeToExecute > 150) {
    throw GradeTooLowException();
  }
}
AForm::AForm()
    : name("AForm"), _isSigned(false), _gradeToSign(100), _gradeToExecute(100) {
  std::cout << "AForm Default Constructor called." << std::endl;
}

AForm::AForm(const AForm &other)
    : name(other.name), _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
  std::cout << "AForm Copy Constructor called for " << std::endl;
}

AForm &AForm::operator=(const AForm &other) {
  if (this != &other) {
    _isSigned = other._isSigned;
  }
  return *this;
}

const std::string AForm::getName() const { return name; }

bool AForm::isSigned() const { return _isSigned; }

int AForm::GetgradeToSign() const { return _gradeToSign; }

int AForm::GetgradeToExecute() const { return _gradeToExecute; }

std::ostream &operator<<(std::ostream &o, AForm const &f) {
  o << f.getName() << ", signed: " << (f.isSigned() ? "Yes" : "No")
    << ", grade to sign: " << f.GetgradeToSign()
    << ", grade to execute: " << f.GetgradeToExecute();
  return o;
}

void AForm::beSigned(const Bureaucrat &b) {
  if (b.getGrade() > this->GetgradeToSign()) {
    throw AForm::GradeTooLowException();
  }
  this->_isSigned = true;
}
