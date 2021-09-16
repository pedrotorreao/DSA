/****************************************************************/
/*Problem: Repeated String (HR) ********/
/****************************************************************/
/*
-- Summary: There is a string, s, of lowercase English letters that is repeated 
infinitely many times. Given an integer, n, find and print the number of letter 
a's in the first n letters of the infinite string.
-- Input(s): 
    s: a string to repeat
    n: the number of characters to consider
-- Expected output(s): The frequency of 'a' in the substring.
-- Constraints: (1 ≤ |s| ≤ 100), (1 ≤ n ≤ 10^12)
-- Example:
    Inputs:
        s = "abcac"
        n = 10
    Output:
        The substring we consider is "abcacabcac", the first 10 characters of the infinite 
        string. There are 4 occurrences of 'a' in the substring. 

*/

#include <bits/stdc++.h>
using namespace std;

long repeatedString(string s, long n)
{
    long count = 0;

    for (auto charac : s)
    {
        if (charac == 'a')
        {
            ++count;
        }
    }

    long mult = n / (long)s.size();
    count *= mult;

    long rest = n % (long)s.size();
    for (auto i{0}; i < rest; ++i)
    {
        if (s.at(i) == 'a')
            ++count;
    }

    return count;
}

int main()
{
    string s1 = "abcac";

    long test1 = repeatedString(s1, 6);
    long test2 = repeatedString(s1, 10);

    cout << "test 1: " << test1 << (test1 == 3 ? " PASSED" : " FAILED") << "\n";
    cout << "test 2: " << test2 << (test2 == 4 ? " PASSED" : " FAILED") << "\n";

    return 0;
}