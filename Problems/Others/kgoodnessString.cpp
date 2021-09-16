/*********************************************************************************************/
/* Problem: K Goodness String ********/
/*********************************************************************************************/
/*
--Problem statement:
  Charles defines the goodness score of a string as the number of indices i such that 
  Si≠SN−i+1 where 1≤i≤N/2 (1-indexed). For example, the string CABABC has a goodness score 
  of 2 since S2≠S5 and S3≠S4. Charles gave Ada a string S of length N, consisting of uppercase 
  letters and asked her to convert it into a string with a goodness score of K. In one operation, 
  Ada can change any character in the string to any uppercase letter. Could you help Ada find 
  the minimum number of operations required to transform the given string into a string with 
  goodness score equal to K?

--Input:
  The first line of the input gives the number of test cases, T. T test cases follow.
  The first line of each test case contains two integers N and K. The second line of each test 
  case contains a string S of length N, consisting of uppercase letters.

--Output:

  For each test case, output one line containing Case #x: y, where x is the test case number 
  (starting from 1) and y is the minimum number of operations required to transform the given 
  string S into a string with goodness score equal to K.
*/

#include <iostream>
#include <string>

int getGoodness(std::string s)
{
  int goodness{0};
  int n = s.size();

  for (int i{1}; i <= n / 2; i++)
  {
    if (s.at(i - 1) != s.at(n - i))
    {
      goodness++;
    }
  }

  return goodness;
}

int kGoodnessString(std::string s, int k)
{
  int goodness = getGoodness(s);
  if (goodness == k)
    return 0;

  int n = s.size();
  int moves{0};

  for (int i{1}; i <= n / 2; i++)
  {
    if (goodness == k)
      return moves;

    if (s.at(i - 1) == s.at(n - i))
    {
      moves++;
      goodness++;
    }
  }

  return moves;
}

int main()
{
  std::string str{"CABABC"};
  int k{3};
  std::cout << "moves needed to make " << str << " reach a goodness of " << k << ": " << kGoodnessString(str, k) << "\n";

  str = "ABCAA";
  k = 1;
  std::cout << "moves needed to make " << str << " reach a goodness of " << k << ": " << kGoodnessString(str, k) << "\n";

  str = "ABAA";
  k = 2;
  std::cout << "moves needed to make " << str << " reach a goodness of " << k << ": " << kGoodnessString(str, k) << "\n";

  return 0;
}

/*
// Solution Google Kickstart: Round-A Q1:

#include <iostream>
#include <string>
#include <cmath>

int main(){
    int t, n, k;
    std::string s;
    
    std::cin >> t;
    
    for(int it = 1; it <= t; it++){
        std::cin >> n >> k;
        std::cin >> s;
        
        int goodness {0};
    
        for(int i{1}; i <= n/2; i++){
            if(s.at(i-1) != s.at(n-i)){
                goodness++;
            }
        }
        
        std::cout << "Case #" << it << ": " << std::abs(goodness-k) << "\n";
    }
    return 0;
}

*/