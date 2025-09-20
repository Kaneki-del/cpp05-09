#include "Serializer.hpp"
#include <iostream>

int main() {
  Data myData = {42, "Hello, world!"};
  Data *originalPtr = &myData;
  std::cout << "Original pointer address: " << originalPtr << std::endl;
  uintptr_t raw = Serializer::serialize(originalPtr);

  std::cout << "Serialized uintptr_t value: " << raw << std::endl;
  Data *deserializedPtr = Serializer::deserialize(raw);
  std::cout << "Deserialized pointer address: " << deserializedPtr << std::endl;
  if (originalPtr == deserializedPtr) {
    std::cout << "Success: Original pointer and deserialized pointer are equal!"
              << std::endl;
    std::cout << "Data value: " << deserializedPtr->id << ", "
              << deserializedPtr->message << std::endl;
  } else {
    std::cout << "Failure: Pointers do not match." << std::endl;
  }

  return 0;
}
