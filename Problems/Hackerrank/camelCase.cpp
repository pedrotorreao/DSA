/*********************************************************************************************/
/* Problem: Camel Case (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Camel Case is a naming style common in many programming languages. In Java, method and variable
  names typically start with a lowercase letter, with all subsequent words starting with a capital
  letter (example: startThread). Names of classes follow the same pattern, except that they start
  with a capital letter (example: BlueCar). Your task is to write a program that creates or splits
  Camel Case variable, method, and class names.

--Input Format:
  > Each line of the input file will begin with an operation (S or C) followed by a semi-colon
  followed by M, C, or V followed by a semi-colon followed by the words you'll need to operate on.
  > The operation will either be S (split) or C (combine)
  > M indicates method, C indicates class, and V indicates variable
  > In the case of a split operation, the words will be a camel case method, class or variable name
  that you need to split into a space-delimited list of words starting with a lowercase letter.
  >In the case of a combine operation, the words will be a space-delimited list of words starting
  with lowercase letters that you need to combine into the appropriate camel case String. Methods
  should end with an empty set of parentheses to differentiate them from variable names.

--Output Format:
  > For each input line, your program should print either the space-delimited list of words (in the
  case of a split operation) or the appropriate camel case string (in the case of a combine operation).

--Example:
  S;M;plasticCup()            -->       plastic cup
  C;V;mobile phone            -->       mobilePhone
  C;C;coffee machine          -->       CoffeeMachine
  S;C;LargeSoftwareBook       -->       large software book
  C;M;white sheet of paper    -->       whiteSheetOfPaper()
  S;V;pictureFrame            -->       picture frame


--Time complexity: O(N), where n is the length of the string.

--Space complexity: O(N), due to the temporary strings.

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void splitString(const std::string &str, std::string &out)
{
  char type = str.at(2);
  std::string temp{};

  switch (type)
  {
  case 'M':
  case 'V':
  {
    for (size_t i{4}; i < str.size(); i++)
    {
      char charac = str.at(i);
      int char_code = int(charac);

      if ((char_code >= 97) && (char_code <= 122))
      {
        temp.push_back(charac);
      }
      else if ((char_code >= 65) && (char_code <= 90))
      {
        temp.push_back(' ');
        temp.push_back(tolower(charac));
      }
    }
    out = temp;
  }
  break;
  case 'C':
  {
    temp.push_back(tolower(str.at(4)));

    for (size_t i{5}; i < str.size(); i++)
    {
      char charac = str.at(i);
      int char_code = int(charac);

      if ((char_code >= 97) && (char_code <= 122))
      {
        temp.push_back(charac);
      }
      else if ((char_code >= 65) && (char_code <= 90))
      {
        temp.push_back(' ');
        temp.push_back(tolower(charac));
      }
    }
    out = temp;
  }
  break;
  }
}

void combineString(const std::string &str, std::string &out)
{
  char type = str.at(2);
  std::string temp{};
  std::vector<std::string> all_str{};

  switch (type)
  {
  case 'M':
  {
    for (size_t i{4}; i < str.size(); i++)
    {
      char charac = str.at(i);

      if (charac == ' ')
        continue;

      if (str.at(i - 1) == ' ')
      {
        charac = toupper(charac);
      }

      temp.push_back(charac);
    }
    temp += "()";
    out = temp;
  }
  break;
  case 'C':
  {
    temp.push_back(toupper(str.at(4)));

    for (size_t i{5}; i < str.size(); i++)
    {
      char charac = str.at(i);

      if (charac == ' ')
        continue;

      if (str.at(i - 1) == ' ')
      {
        charac = toupper(charac);
      }

      temp.push_back(charac);
    }
    out = temp;
  }
  break;
  case 'V':
  {
    for (size_t i{4}; i < str.size(); i++)
    {
      char charac = str.at(i);
      if (charac == ' ')
        continue;
      if (str.at(i - 1) == ' ')
      {
        charac = toupper(charac);
      }

      temp.push_back(charac);
    }
    out = temp;
  }
  break;
    // default:
    /*do nothing*/
  }
}

int main()
{
  std::string s, o;

  while (std::getline(std::cin, s))
  {
    if (s.at(0) == 'S')
    {
      splitString(s, o);
    }
    else
    {
      combineString(s, o);
    }
    o.erase(remove(o.begin(), o.end(), '\r'), o.end());
    o.erase(remove(o.begin(), o.end(), '\t'), o.end());
    o.erase(remove(o.begin(), o.end(), '\n'), o.end());
    std::cout << o << "\n";
  }

  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  return 0;
}