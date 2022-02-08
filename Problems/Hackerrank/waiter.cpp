/*********************************************************************************************/
/* Problem: Waiter (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  You are a waiter at a party. There is a pile of numbered plates. Create an empty 'answers' array. 
  At each iteration, 'i', remove each plate from the top of the stack in order. Determine if the 
  number on the plate is evenly divisible by the ith prime number. If it is, stack it in pile Bi. 
  Otherwise, stack it in stack Ai. Store the values in Bi from top to bottom in 'answers'. In 
  the next iteration, do the same with the values in stack Ai. Once the required number of 
  iterations is complete, store the remaining values in Ai in answers, again from top to bottom. 
  Return the answers array. 

  > Example: A=[2,3,4,5,6,7]    q=3
              --> answers=[2,4,6,3,5,7]
  
  > Example: A=[3,4,7,6,5]      q=1
              --> answers=[4,6,3,7,5]

--Reasoning: See comments below.

--Time complexity: O(q*n), where q is the number of queries to process and n the size of number[].

--Space complexity: O(n), where n is the size of number[].
*/

#include <iostream>
#include <stack>
#include <vector>

void displayVec(const std::vector<int> &vec);
void nthPrime(std::vector<int> &primeList, int list_size);

std::vector<int> waiter(std::vector<int> number, int q) {
  // output arrays containing the final answers:
  std::vector<int> answers;

  // array containing q^2 prime numbers:
  std::vector<int> primes;
  nthPrime(primes, q);

  // temp array to store the elements not divisible by the ith prime number:
  std::vector<int> A_temp{number};

  // perform 'q' queries:
  for (int i{0}; i < q; ++i) {
    // store numbers not divisible by the current prime:
    std::stack<int> Ai;
    for (const auto &num : A_temp) {
      // if divisible by current prime, add to the result:
      if (num % primes.at(i) == 0)
        answers.push_back(num);
      // otherwise, push it to the stack:
      else
        Ai.push(num);
    }
    // clear the temp array so it stores only the numbers which are not multiples
    // of the current prime:
    A_temp.clear();

    // pass the numbers from the stack to the temp array:
    while (!Ai.empty()) {
      A_temp.push_back(Ai.top());
      Ai.pop();
    }
  }

  // make sure that the elements remaining from the last query are added to the result:
  answers.insert(answers.end(), A_temp.rbegin(), A_temp.rend());

  return answers;
}

int main() {
  std::vector<int> vec{2, 3, 4, 5, 6, 7};
  int queries{3};
  std::vector<int> res = waiter(vec, queries);
  displayVec(res);

  vec = {3, 4, 7, 6, 5};
  queries = 1;
  res = waiter(vec, queries);
  displayVec(res);

  vec = {3, 3, 4, 4, 9};
  queries = 2;
  res = waiter(vec, queries);
  displayVec(res);

  return 0;
}

void displayVec(const std::vector<int> &vec) {
  for (const auto &v : vec) {
    std::cout << v << "   ";
  }
  std::cout << "\n";
}

// Function to generate N prime numbers using Sieve of Eratosthenes:
void nthPrime(std::vector<int> &primeList, int list_size) {
  long max_size = list_size * 10;
  // Create a boolean array "isPrime[0..list_size]" and initialize
  // all entries as true. A value in IsPrime[i] will be false if i
  // is Not a IsPrime, else true.
  std::vector<bool> isPrime(max_size, true);

  for (int nth{2}; nth * nth < max_size; ++nth) {
    // If IsPrime[nth] is not changed, then nth is a prime number:
    if (isPrime.at(nth) == true) {
      // Update all multiples of p greater than or
      // equal to the square of it
      // numbers which are multiple of p and are
      // less than p^2 are already been marked.
      for (int i = nth * nth; i < max_size; i += nth)
        isPrime.at(i) = false;
    }
  }

  // Store all prime numbers
  for (int nth = 2; nth < max_size; nth++) {
    if (isPrime.at(nth))
      primeList.push_back(nth);
  }
}
