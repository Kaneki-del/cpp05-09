#include "Bureaucrat.hpp"

Bureaucrat::~Bureaucrat() {
  std::cout << "Bureaucrat destructor called." << std::endl;
}

Bureaucrat::Bureaucrat() : name("bureaucrat"), grade(100) {
  std::cout << "Bureaucrat Default Constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : name(other.name), grade(other.grade) {

  std::cout << "Bureaucrat Copy Constructor called for " << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  if (this != &other) {
    grade = other.grade;
  }
  return *this;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name) {
  if (grade < 1) {
    throw GradeTooHighException();
  }
  if (grade > 150) {
    throw GradeTooLowException();
  }
  this->grade = grade;
}
const std::string Bureaucrat::getName() const { return name; }

int Bureaucrat::getGrade() const { return grade; }

void Bureaucrat::increment() {
  if (grade - 1 < 1) {
    throw Bureaucrat::GradeTooHighException();
  }
  grade--;
}

void Bureaucrat::decrement() {
  if (grade + 1 > 150) {
    throw Bureaucrat::GradeTooLowException();
  }
  grade++;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &b) {
  o << b.getName() << ", bureaucrat grade " << b.getGrade();
  return o;
}
