/********************************************************************************************************/
/* Problem: Calculate the Fibonacci sequence of n - Dynamic Programming Approach   *******/
/********************************************************************************************************/

function fibonacci() {
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

let fib = fibonacci();

console.log(fib(10));
console.log(fib(9));
console.log(fib(8));
console.log(fib(7));
console.log(fib(6));

/*
n: 0    1    2    3    4    5    6    7    8    9    10
f: 0    1    1    2    3    5    8    13   21   34   55   
*/
