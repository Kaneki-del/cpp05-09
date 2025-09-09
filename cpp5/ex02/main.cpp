#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
  srand(time(0));
  try {
    Bureaucrat high_bureaucrat("The Boss", 1);
    ShrubberyCreationForm s_form("Home");

    high_bureaucrat.signForm(s_form);
    high_bureaucrat.executeForm(s_form);

    RobotomyRequestForm r_form("Bender");
    high_bureaucrat.signForm(r_form);
    high_bureaucrat.executeForm(r_form);

  } catch (const std::exception &e) {
    std::cerr << "Caught an exception: " << e.what() << std::endl;
  }

  try {
    Bureaucrat low_grade_bureaucrat("Junior", 150);
    PresidentialPardonForm p_form("Marvin");

    low_grade_bureaucrat.signForm(p_form);
    low_grade_bureaucrat.executeForm(p_form);
  } catch (const std::exception &e) {
    std::cerr << "Caught an exception: " << e.what() << std::endl;
  }

  return 0;
}
