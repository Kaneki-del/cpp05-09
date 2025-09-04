#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
  Intern intern;
  AForm *r_form = NULL;
  AForm *p_form = NULL;

  try {
    r_form = intern.makeForm("robotomy request", "Bender");
    Bureaucrat high_b("Boss", 1);
    high_b.signForm(*r_form);
    high_b.executeForm(*r_form);

    p_form = intern.makeForm("presidential pardon", "Ford Prefect");
    Bureaucrat low_b("Manager", 50);
    low_b.signForm(*p_form);
    low_b.executeForm(*p_form);
  } catch (const std::exception &e) {
    std::cerr << "Caught an exception: " << e.what() << std::endl;
  }

  delete r_form;
  delete p_form;

  return 0;
}
