/******************************************************************************
Algorithm: Greatest Common Divisor (GCD) Divide & Conquer Approach
*******************************************************************************/
#include <iostream>
#include <stdexcept>
#include <cmath>

int gcd(int a, int b)
{
  if (a == 0 && b == 0)
    throw std::invalid_argument("... both numbers cannot be zero!");

  if (a == b)
    return a;

  if (a == 0)
    return b;

  if (b == 0)
    return a;

  int r = std::abs(a - b);

  return gcd(b, r);
}

int main()
{
  int a = 270, b = 192;

  std::cout << "Greatest Common Divisor of " << a << " and " << b << ": " << gcd(a, b) << "\n";

  a = 1680;
  b = 640;
  std::cout << "Greatest Common Divisor of " << a << " and " << b << ": " << gcd(a, b) << "\n";

  a = 1680;
  b = 0;
  std::cout << "Greatest Common Divisor of " << a << " and " << b << ": " << gcd(a, b) << "\n";

  a = 0;
  b = 640;
  std::cout << "Greatest Common Divisor of " << a << " and " << b << ": " << gcd(a, b) << "\n";

  a = 0;
  b = 0;
  std::cout << "Greatest Common Divisor of " << a << " and " << b << ": " << gcd(a, b) << "\n";

  return 0;
}
