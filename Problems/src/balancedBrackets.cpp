/******************************************************************************
Problem: Balanced Brackets CPP (HR)
*******************************************************************************/
#include <iostream>
#include <stack>
#include <string>
#include <vector>

std::string isBalanced(std::string s)
{
  std::stack<char> match;
  char top;
  for (size_t i{0}; i < s.length(); i++)
  {
    switch (s.at(i))
    {
    case '{':
    {
      match.push('}');
      break;
    }
    case '[':
    {
      match.push(']');
      break;
    }
    case '(':
    {
      match.push(')');
      break;
    }
    default:
    {
      if (match.size())
      {
        top = match.top();
      }
      else
      {
        return "NO";
      }
      if (top != s.at(i))
        return "NO";
      match.pop();
    }
    }
  }
  return ((match.size() != 0) ? "NO" : "YES");
}

int main()
{
  std::vector<std::string> queries{
      "}][}}(}][))]", "[](){()}", "()", "({}([][]))[]()", "{)[](}]}]}))}(())(",
      "([[)", "{}", "}([[{)[]))]{){}[", "{]]{()}{])", "(){}", "{}{()}{{}}"};

  for (size_t i{0}; i < queries.size(); i++)
  {
    std::string result = isBalanced(queries.at(i));
    std::cout << queries.at(i) << ": " << result << "\n";
  }
  return 0;
}
