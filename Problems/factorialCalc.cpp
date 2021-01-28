#include <iostream>

int factorialRecursively(int n);
int factorialIteratively(int n);

int main()
{
    int n{6};

    std::cout << "Factorial Recursively of " << n << ':' << factorialRecursively(n) << std::endl;
    std::cout << "Factorial Iteratively of " << n << ':' << factorialIteratively(n) << std::endl;

    return 0;
}

int factorialRecursively(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * factorialRecursively(n - 1);
}

int factorialIteratively(int n)
{
    int fact{1};

    while (n >= 1)
    {
        fact *= n;
        --n;
    }
    return fact;
}