"""
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
"""


def sqrt_of_x(x):
    if x < 2:
        return x

    lowest_possible_root = 1
    greatest_possible_root = x // 2

    while True:
        current_guess = (greatest_possible_root + lowest_possible_root) // 2

        # mid*mid > x --> mid > x/mid: mid is too high:
        if current_guess > (x / current_guess):
            greatest_possible_root = current_guess - 1
        else:
            # (mid + 1)*(mid + 1) < x --> (mid + 1) < x/(mid + 1): mid is the nearest int:
            if (current_guess + 1) > (x / (current_guess + 1)):
                return current_guess
            # mid*mid < x --> mid < x/mid: mid is too low:
            else:
                lowest_possible_root = current_guess + 1


x = 8
print(f"The nearest integer to the square root of {x} is: {sqrt_of_x(x)}")

x = 4
print(f"The nearest integer to the square root of {x} is: {sqrt_of_x(x)}")

x = 2
print(f"The nearest integer to the square root of {x} is: {sqrt_of_x(x)}")

x = 17
print(f"The nearest integer to the square root of {x} is: {sqrt_of_x(x)}")
