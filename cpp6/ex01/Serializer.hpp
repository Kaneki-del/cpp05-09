#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
enum e_type { CHAR, INT, FLOAT, DOUBLE, UNKNOWN };

class Serializer {
public:
  static uintptr_t serialize(Data *ptr);
  Data *deserialize(uintptr_t raw);

private:
  Serializer();
  Serializer(const Serializer &other);
  ~Serializer();
  Serializer &operator=(const Serializer &other);
};
#endif
