#include <iostream>
#include <iomanip>
#include <vector>
#include "dynamicArray.h"

int main()
{
  std::cout << std::boolalpha;

  DynamicArray<int> arr{3 /*capacity*/, 2 /*growth_factor*/};

  // TC#1.1 - test isEmpty() method [Expected: TRUE]:
  std::cout << "Array is empty: " << arr.isEmpty() << "\n";

  arr.push(11);

  // TC#1.2 - test isEmpty() method [Expected: FALSE]:
  std::cout << "Array is empty: " << arr.isEmpty() << "\n";

  arr.push(15);

  // TC#2.1 - test get_size() method [Expected: 2]:
  std::cout << "Array size: " << arr.get_size() << "\n";

  arr.pop();

  // TC#2.2 - test get_size() method [Expected: 1]:
  std::cout << "Array size: " << arr.get_size() << "\n";

  // TC#3.1 - test print() method [Expected: 11]:
  arr.print();

  // TC#4.1 - teste front() method [Expected: 11]:
  std::cout << "Array front: " << arr.front() << "\n";

  arr.insert(9, 0);

  // TC#2.2 - test get_size() method [Expected: 1]:
  std::cout << "Array size: " << arr.get_size() << "\n";

  // TC#4.2 - teste front() method [Expected: 9]:
  std::cout << "Array front: " << arr.front() << "\n";
  // TC#4.3 - teste back() method [Expected: 11]:
  std::cout << "Array back: " << arr.back() << "\n";

  // TC#3.2 - test print() method [Expected: 9 11]:
  arr.print();

  arr.push(8);
  arr.push(23);
  arr.push(3);

  std::cout << "Array capacity: " << arr.capacity() << "\n";

  // TC#3.2 - test print() method [Expected: 9 11]:
  arr.print();

  return 0;
}