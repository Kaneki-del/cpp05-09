
#include "Form.hpp"

Form::~Form() { std::cout << "Form destructor called." << std::endl; }

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), _isSigned(false), _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute) {
  if (this->_gradeToSign < 1 || this->_gradeToExecute < 1) {
    throw GradeTooHighException();
  }
  if (this->_gradeToSign > 150 || this->_gradeToExecute > 150) {
    throw GradeTooLowException();
  }
}
Form::Form()
    : name("Form"), _isSigned(false), _gradeToSign(100), _gradeToExecute(100) {
  std::cout << "Form Default Constructor called." << std::endl;
}

Form::Form(const Form &other)
    : name(other.name), _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
  std::cout << "Form Copy Constructor called for " << std::endl;
}

Form &Form::operator=(const Form &other) {
  if (this != &other) {
    _isSigned = other._isSigned;
  }
  return *this;
}

const std::string Form::getName() const { return name; }

bool Form::isSigned() const { return _isSigned; }

int Form::GetgradeToSign() const { return _gradeToSign; }

int Form::GetgradeToExecute() const { return _gradeToExecute; }

std::ostream &operator<<(std::ostream &o, Form const &f) {
  o << f.getName() << ", signed: " << (f.isSigned() ? "Yes" : "No")
    << ", grade to sign: " << f.GetgradeToSign()
    << ", grade to execute: " << f.GetgradeToExecute();
  return o;
}

void Form::beSigned(const Bureaucrat &b) {
  if (b.getGrade() > this->GetgradeToSign()) {
    throw Form::GradeTooLowException();
  }
  this->_isSigned = true;
}
