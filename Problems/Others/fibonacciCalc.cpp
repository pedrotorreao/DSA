#include <iostream>

int fibonacciRecursively(int n);
int fibonacciIteratively(int n);

int main()
{
    int n{10};

    std::cout << "Fibonacci Recursively of " << n << ": " << fibonacciRecursively(n) << std::endl;
    std::cout << "Fibonacci Iteratively of " << n << ": " << fibonacciIteratively(n) << std::endl;

    return 0;
}

int fibonacciRecursively(int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }
    return fibonacciRecursively(n - 1) + fibonacciRecursively(n - 2);
}

int fibonacciIteratively(int n)
{
    int fib0{0};
    int fib1{1};
    int fibn{0};
    int cntr{0};

    while (cntr < n)
    {
        fib0 = fib1;
        fib1 = fibn;
        fibn = fib0 + fib1;

        ++cntr;
    }
    return fibn;
}