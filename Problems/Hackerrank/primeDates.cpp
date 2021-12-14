/*********************************************************************************************/
/* Problem: Prime Dates (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  In this challenge, the task is to debug the existing code to successfully execute all provided
  test files.
  Given two dates each in the format dd-mm-yyyy, you have to find the number of lucky dates
  between them (inclusive). To see if a date is lucky:
    - Firstly, sequentially concatinate the date, month and year, into a new integer 'x' erasing
    the leading zeroes.
    - Now if 'x' is divisible by either '4' or '7', then we call the date a lucky date.
  For example, let's take the date "02-08-2024". After concatinating the day, month and year, we get
  x = 2082024. As is divisible by '4' so the date "02-08-2024" is called a lucky date.
  Debug the given function findPrimeDates and/or other lines of code, to find the correct lucky
  dates from the given input.

  Note: You can modify at most five lines in the given code and you cannot add or remove lines
  to the code.

--Reasoning:
  Some more context:
  - A normal year has 365 days.
  - A Leap Year has 366 days (the extra day is the 29th of February).

  How to know if a given year is a Leap Year:
  - Leap Years are any year that can be EXACTLY DIVIDED BY 4 (such as 2016, 2020, 2024, etc):
        -> (year % 4 == 0)
  - Except if it can be EXACTLY DIVIDED BY 100, then it isn't (such as 2100, 2200, etc):
        -> (year % 100 == 0)
  - Except if it can be EXACTLY DIVIDED BY 400, then it is (such as 2000, 2400):
        -> (year % 400 == 0)

  Reference: https://www.mathsisfun.com/leap-years.html

  Comments indicate where the changes were performed in the code.

--Time complexity: O(N), where N is the number of dates between dates 1 and 2.

--Space complexity: O(1), there's no memory allocation dependent on the input size.

*/

// #include <bits/stdc++.h>
// using namespace std;
#include <iostream>
#include <sstream>
#include <string>

int month[15];

void luckyDatesHelper(std::string &str, int &res);

void updateLeapYear(int year)
{
  if (year % 400 == 0)
  {
    month[2] = 29; // 2: 28 -> 29
  }
  else if (year % 100 == 0)
  {
    month[2] = 28; // 3: 29 -> 28
  }
  else if (year % 4 == 0)
  {
    month[2] = 29;
  }
  else
  {
    month[2] = 28;
  }
}

void storeMonth()
{
  month[1] = 31;
  month[2] = 28;
  month[3] = 31;
  month[4] = 30;
  month[5] = 31;
  month[6] = 30;
  month[7] = 31;
  month[8] = 31;
  month[9] = 30;
  month[10] = 31;
  month[11] = 30;
  month[12] = 31;
}

int findLuckyDates(int d1, int m1, int y1, int d2, int m2, int y2)
{
  storeMonth();

  int result = 0;

  while (true)
  {
    int x = d1;
    x = x * 100 + m1;
    x = x * 10000 + y1;           // 1: 1000 -> 10000
    if (x % 4 == 0 || x % 7 == 0) // 5: && -> ||
    {
      result = result + 1;
    }
    if (d1 == d2 && m1 == m2 && y1 == y2)
    {
      break;
    }
    updateLeapYear(y1);
    d1 = d1 + 1;
    if (d1 > month[m1])
    {
      m1 = m1 + 1;
      d1 = 1;
      if (m1 > 12)
      {
        y1 = y1 + 1;
        m1 = 1; // 4: m1 + 1 -> 1
      }
    }
  }
  return result;
}

int main()
{
  std::string str;
  int luckyDates;

  // TC #1 - Expected output: 5
  str = "02-08-2025 04-09-2025";
  luckyDatesHelper(str, luckyDates);
  std::cout << "Lucky dates: " << luckyDates << "\t-- " << ((luckyDates == 5) ? "PASSED\n" : "FAILED\n") << std::endl;

  // TC #2 - Expected output: 846403
  str = "25-06-2365 07-09-8847";
  luckyDatesHelper(str, luckyDates);
  std::cout << "Lucky dates: " << luckyDates << "\t-- " << ((luckyDates == 846403) ? "PASSED\n" : "FAILED\n") << std::endl;

  // TC #3 - Expected output: 942182
  str = "13-10-2323 11-10-9536";
  luckyDatesHelper(str, luckyDates);
  std::cout << "Lucky dates: " << luckyDates << "\t-- " << ((luckyDates == 942182) ? "PASSED\n" : "FAILED\n") << std::endl;

  // TC #4 - Expected output: 682291
  str = "16-12-4018 27-09-9243";
  luckyDatesHelper(str, luckyDates);
  std::cout << "Lucky dates: " << luckyDates << "\t-- " << ((luckyDates == 682291) ? "PASSED\n" : "FAILED\n") << std::endl;

  // TC #5 - Expected output: 69066
  str = "5-07-8837 29-08-9367";
  luckyDatesHelper(str, luckyDates);
  std::cout << "Lucky dates: " << luckyDates << "\t-- " << ((luckyDates == 69066) ? "PASSED\n" : "FAILED\n") << std::endl;

  return 0;
}

void luckyDatesHelper(std::string &str, int &res)
{
  int d1, m1, y1, d2, m2, y2;

  for (int i = 0; i < str.size(); i++)
  {
    if (str[i] == '-')
    {
      str[i] = ' ';
    }
  }

  std::stringstream ss;

  ss << str;
  ss >> d1 >> m1 >> y1 >> d2 >> m2 >> y2;

  res = findLuckyDates(d1, m1, y1, d2, m2, y2);
}
