#include <iostream>
#include <string>

void separateNumbers(std::string s)
{
  std::string prev, curr;

  for (int l = 1; (l <= s.size() / 2) && (s != curr); l++)
  {
    prev = curr = s.substr(0, l);
    for (int i = 1; curr.size() < s.size(); i++)
    {
      curr += std::to_string(stoll(prev) + i);
    }
  }
  std::cout << (s == curr ? "YES " + prev : "NO");
}

int main()
{
  std::string num{"1234"};
  separateNumbers(num); // Expects "YES"

  num = {"91011"};
  separateNumbers(num); // Expects "YES"

  num = {"99100"};
  separateNumbers(num); // Expects "YES"

  num = {"312"};
  separateNumbers(num); // Expects "NO"

  num = {"10203"};
  separateNumbers(num); // Expects "NO"

  num = {"100101"};
  separateNumbers(num); // Expects "YES"

  return 0;
}
