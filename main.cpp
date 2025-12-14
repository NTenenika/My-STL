#include "array.h"
#include <string>

int main() {
  Array<char, 3> array1;
  Array<int, 3> array2;
  Array<std::string, 4> array3;

  array1.Set(1, 'a', 0, 'f', 2, 'r');
  array1.Print();

  array2.Set(0, 2, 1, 3, 2, 4);

  array2.Print(2);

  return 0;
}