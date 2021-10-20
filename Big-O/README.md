## Big-O: Time and Space Complexity Analisys

### Definition

The Big-O notation provides us the information of how fast a given algorithm is. It allows us to compare the number of operations and informs us of how quickly the algorithm grows. This particular way of measuring the running time of an algorithm takes into account the worst case, i.e. in the worst possible scenario we can be sure that an algorithm performance won't be worse than its Big-O notation. The speed of an algorithm is not measured in seconds, but based on the growth of the number of operations, in other words, it is based on how quickly the running time increases as the input size grows. Big-O allows us to express how the runtime scales.

### Common Big-O notations

The chart below ilustrates how the most common Big-O running times behave as the size of the input grows (source: [Big-O Cheatsheet by Eric Rowell](https://www.bigocheatsheet.com/)).

![Big-O Chart](../resources/img/bigochart.png)

Common time complexities ordered from best to worst:

1. Constant - `O(1)`:

A **constant** running time means that no matter the size of the input, the performance of the algorithm will be the same. Since this algorithm running time does not depend on the size of the input, the number of operations remains constant and does not increase as the input size grows.

It is good to mention, however, that a constant running time does not mean that something happens instantaneously, but that the running time will always be the same no matter how large is the dataset.

> Example: In the function `getMax` below, no matter the values of `a` and `b`, `getMax` always performs the same amount of operations.

```javascript
function getMax(a, b) {
  if (a > b) {
    return a;
  }
  return b;
}
```

2. Linear - `O(n)`:

In the worst case scenario, the maximum number of operations will be equal to the input size.

```javascript
function searchArray(array, target) {
  let n = array.length;

  for (let i = 0; i < n; ++i) {
    if (array[i] == target) {
      return i;
    }
  }
  return -1;
}
```

3. Logarithmic - `O(log n)`:

If an algorithm has a time complexity of `O(log n)`, the bigger its input size, the smaller proportion of the actual input your program has to go through. A logarithmic algorithm is the opposite of an exponential one. When something grows exponentially, it means that, at each step, the number of operations is multiplied by a factor. Whereas, when an algorithm grows logarithmically, the number of operations needed is being divided by this factor at each step. Assuming the base of the logarithm as being `2`, this means that the size of the dataset that the algorithm has to go through gets divided by `2` at each step.

A traditional example for `O(log n)` running time is binary search. Consider an **ordered** `array` on size `n` and a `target` value. If we were to use linear search to find `target` in `array`, in the worst case scenario that we begin at the first position in `array` and `target` is the last element, we'd have to search the entire `array`, thus performing `n` comparisons. However, using a binary search algorithm like the one below, since at each step we half the the amount of elements to be searched, the total number of operations necessary is at most `log (input_size)` or `log n`.

> Binary search algorithm:

```javascript
function binarySearch(array, target) {
  let start = 0;
  let end = array.length - 1;

  while (start <= end) {
    if (array[start] === target) return start;
    if (array[end] === target) return end;

    let mid = Math.round((start + end) / 2);

    if (target == array[mid]) return mid;

    if (target > array[mid]) start = mid + 1;
    else if (target < array[mid]) end = mid - 1;
  }

  return -1;
}
```

> Example:

```
array = [11, 23, 30, 45, 51, 62, 70, 89, 95, 100, 110]
target = 100

start = 0
end = array.length - 1 = 10

step 1 - dataset searched [11, 23, 30, 45, 51, 62, 70, 89, 95, 100, 110]
  array[start] != target
  array[end] != target

  mid = (start + end) / 2 = 10 / 2 = 5

  target > array[mid] -- 100 > 62:
    start = mid + 1 = 6

step 2 - dataset searched [x x x x x x 70, 89, 95, 100, 110]
  array[start] != target
  array[end] != target

  mid = (start + end) / 2 = (6+10) / 2 = 8
  target > array[mid] -- 100 > 95:
    start = mid + 1 = 9

step 3 - dataset searched [x x x x x x x x x 100, 110]
  array[start] == target: return start -- return 9
```

As we can see, we begin with an `n` sized array to search. After the first step, we're searching through only `n/2` elements. One more step and we're down to `n/4` elements to search. We are done when we either find `target` or we're down to only one element.

The total runtime can be expressed as how many steps, dividing `n` by two each time, we need too take until `n` becomes 1. For the example above, where `n = 11`:

> \# of steps: `log(n) = log(11) = ~3`, which matches our example.

Let's apply this reasonig to a larger dataset. Consider now that we want to find a person by searching for his registered unique `ID` in an ordered database containing fifty million registered `ID`s. If we decide to use linear search here, in the event that our target `ID` is the last in the database or does not exist, we'd have to look and compare all the fifty million elements in the database elements. However, we were to use binary search to find the person, that would take:

```
step 1: 50000000 / 2 = 25000000
step 2: 25000000 / 2 = 12500000
step 3: 12500000 / 2 = 6250000
step 4: 6250000 / 2 = 3125000
step 5: 3125000 / 2 = 1562500
step 6: 1562500 / 2 = 781250
...
step 25: 2.98 / 2 = ~1

or simply, log(50000000) = ~25
```

25 steps at worst, which is a huge improvement over the linear search. We can see that the growth rate of the runtime for both algorithms is very different, while linear search follows the size of the dataset, binary search gets faster in proportion as the size of the dataset grows.

1. Quadratic - `O(n^2)`:

```javascript
function printMatrixElements(matrix) {
  let n = matrix.length;

  for (let i = 0; i < n; ++i) {
    for (let j = 0; j < n; ++j) {
      console.log(matrix[i]);
    }
  }
}
```

Other common running times:

1. Linearithmic - `O(n * log n)`:

2. Exponential - `O(b^n)`, where b > 1:

3. Factorial - `O(n!)`:

### Determining the Big-O notation

#### General rules

1. Different steps get added

   - Example:

2. Drop the constants

   - Example:

3. Different inputs equate to different variables

   - Example:

4. Drop the non-dominant terms
   - Example:

#### Steps:

1. Identify your code
2. Identify what `n` means (Rule #3)
3. Count the steps in a typical run (Rule #1)
4. Keep the most significant part (Rules #2 and #4)

### Time Complexity

### Space Complexity

### Additional Examples

### A few takeaways

### References

- [Grokking Algorithms: An Illustrated Guide for Programmers and Other Curious People](https://www.manning.com/books/grokking-algorithms)
- [Cracking the Coding Interview](https://www.crackingthecodinginterview.com/)

### [Data Structures & Algorithms - Index](../README.md)
