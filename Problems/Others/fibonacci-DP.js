/********************************************************************************************************/
/* Problem: Calculate the Fibonacci sequence of n - Dynamic Programming Approach   *******/
/********************************************************************************************************/

// ---- Top Down Approach - Memoization ----:
function fibonacciTopDown() {
  let cache = {};
  return function f(n) {
    if (cache[n]) {
      return cache[n];
    }
    if (n < 2) {
      return n;
    }
    cache[n] = f(n - 1) + f(n - 2);

    return cache[n];
  };
}

// ---- Bottom Up Approach - Tabulation ----:
function fibonacciBottomUp(n) {
  let res = [];
  // push first 2 results:
  res.push(0); // fib(0)
  res.push(1); // fib(1)

  for (let i = 2; i <= n; i++) {
    res.push(res[i - 1] + res[i - 2]);
  }

  return res.pop();
}

let fibTD = fibonacciTopDown();

console.log(fibTD(10), fibonacciBottomUp(10));
console.log(fibTD(9), fibonacciBottomUp(9));
console.log(fibTD(8), fibonacciBottomUp(8));
console.log(fibTD(7), fibonacciBottomUp(7));
console.log(fibTD(6), fibonacciBottomUp(6));

/*
n: 0    1    2    3    4    5    6    7    8    9    10
f: 0    1    1    2    3    5    8    13   21   34   55   
*/
