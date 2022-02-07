/*********************************************************************************************/
/* Problem: Pow(x,n) (LC) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
  > Example 1:
    Input: x = 2.00000, n = 10
    Output: 1024.00000

  > Example 2:
    Input: x = 2.10000, n = 3
    Output: 9.26100

  > Example 3:
    Input: x = 2.00000, n = -2
    Output: 0.25000
    Explanation: 2-2 = 1/22 = 1/4 = 0.25

--Inputs:
  -double: represents 'x', the base.
  -int: represents 'n', the power to which 'x' is being raised to.

--Outputs:
  -double: the result of x^n.

--Constraints:
    -100.0 < x < 100.0
    -231 <= n <= 231-1
    -104 <= xn <= 104

--Reasoning: 
  In order to computer the value of 'x' raised to the nth power, you might start to consider first 
  of all the cases in which 'n' is positive. Let's assume that n = 13, so we can say:
                  pow(x, 13) = pow(x, 1) * pow(x, 4) * pow(x, 8)
  Paying close attention we can see that we basically decomposed 13 in its binary digits 1 (0001), 
  4 (0100) and 8 (1000), or 13 (1101). And that is how a computer calculates powers, at each step 
  we multiply 'x' by itself, so we'll get x^1, x^2, x^4, x^8, x^16 and so on. Therefore, we can
  decompose 'n' as powers of 2 and keep multiplying for 'x' by itself while 'n' is a valid power.
  Additionally, for the cases when n < 0, instead of multiplying, we divide.

--Time complexity: O(log(n)), at each step of the way, we divide n by 2.

--Space complexity: O(1), no additional input-dependent space is allocated.

*/
#include <iostream>
#include <string>
#include <vector>

double myPow(double x, int n) {
  double powxn = 1;
  // The result of any number to the power of 0 is 1:
  if (n == 0)
    return powxn;

  while (n != 0) {
    // Update the result for when n is odd. Say n=7, x^7 can be broken down into:
    //      x^7 = (x^4) * (x^2) * (x^1), the powers of 2 ,i.e. 4 and 2, are accounted for
    //      by multiplying x by itself, but x^1 needs to be calculated and added to the result.
    if (n % 2 != 0) {
      if (n > 0) // n is a positive exponent, multiply:
        powxn = powxn * x;
      else // n is a negative exponent, divide:
        powxn = powxn / x;
    }

    x *= x;
    n /= 2;
  }

  return powxn;
}

int main() {

  double x{2.000};
  int n{10};
  std::cout << x << "^" << n << ": " << myPow(x, n) << "\n";

  x = 2.0;
  n = -2;
  std::cout << x << "^" << n << ": " << myPow(x, n) << "\n";

  return 0;
}

/* Alternative solution - Recursive one liner mirror of the current iterative one:
double myPow(double x, int n, double res = 1) {
    return n ? myPow(x * x, n / 2, n % 2 ? (n > 0 ? res * x : res / x) : res) : res;
}

*/

/* Alternative solution - Tail recursion: it works but it exceeds LC' time constraints.

double myPowHelper(double x, int n, double res = 1.0){
    if(n == 0)
        return res;
        
    return myPowHelper(x, n-1, res*x);
}

double myPow(double x, int n) {
    double powxn = myPowHelper(x, abs(n));
    //return (n < 0) ? (1 / myPowHelper(x, n)) : (myPowHelper(x, n));
    return (n < 0) ? (1/powxn) : powxn;
}

*/