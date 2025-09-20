#include "Identify.hpp"
#include <typeinfo>

Base::~Base() {}
Base *generate(void) {
  int randomNumber = rand() % 3;

  switch (randomNumber) {
  case 0:
    return new A();
  case 1:
    return new B();
  case 2:
    return new C();
  }
  return NULL;
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p)) {
    std::cout << "It's an A" << std::endl;
  } else if (dynamic_cast<B *>(p)) {
    std::cout << "It's an B" << std::endl;
  } else if (dynamic_cast<C *>(p)) {
    std::cout << "It's an C" << std::endl;
  }
}

void identify(Base &p) {
  try {
    (void)dynamic_cast<A &>(p);
    std::cout << "It's an A" << std::endl;
  } catch (const std::bad_cast &e) {
    try {
      (void)dynamic_cast<B &>(p);
      std::cout << "It's a B" << std::endl;
    } catch (const std::bad_cast &e) {
      try {
        (void)dynamic_cast<C &>(p);
        std::cout << "It's a C" << std::endl;
      } catch (const std::bad_cast &e) {
        std::cerr << "Bad cast: " << e.what() << std::endl;
      }
    }
  }
}
