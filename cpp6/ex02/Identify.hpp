#ifndef IDENTIFY_HPP
#define IDENTIFY_HPP
#include <cstdlib>
#include <iostream>
#include <string>

class Base {
public:
  virtual ~Base();
};
class A : public Base {};
class B : public Base {};
class C : public Base {};
#endif
Base *generate(void);
void identify(Base *p);
void identify(Base &p);
