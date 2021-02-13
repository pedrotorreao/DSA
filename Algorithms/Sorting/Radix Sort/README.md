## Radix Sort
---
### Definition
#### Radix-sort is a stable non-comparative sorting algorithm which sorts the data by distributing elements into groups according to their radix (place value, base). For elements with more than one significant digit, this distribution process is repeated for each digit, while preserving the ordering of the prior step, until all digits have been considered. Radix sorts is usually implemented by starting from the least significant digit (LSD) for numbers and from the most significant digit (MSD) for words.


#### Here, Counting Sort is used as a subroutine to sort an array of numbers corresponding to the place values, i.e., if the data is an array of integers, each individual digit can go from 0 to 9 (10 digits - base 10). Since it is not comparison based, radix sort is not bounded by _O(nlog⁡n)_ for running time and it can perform in linear time.


#### As it sorts by place value and not the whole number at once, it can sort larger numbers without decreasing the efficiency due to the size of the range of keys the algorithm goes over. To provide a perspective, consider the array below:
> #### _specialArray_ = [152, 8, 530, 90, 88, 231, 11, 45, 677, 199]

#### If we were to sort this array using counting sort directly, we'd have a _**count**_ array with a size equal to the maximum number in _**specialArray**_ where for each element of _**specialArray**_ we'd store how many times it appears in _**count**_ at the position _**count[ specialArray[i] ]**_. We can easily see that being very inefficient for the example above since _**count**_ would have to have 678 (0 to 677) elements and _**specialArray**_ only has 10 elements to be sorted which would mean that we'd have most of the positions in _**count**_ would be empty (huge waste of time). What Radix Sort does is that it uses Counting Sort to sort each individual digit and since at each iteration each digit can only go from 0 to 9, with 9 being the maximum number, the size of _**count**_ is pretty much fixed.

![radix-sort](../../../resources/img/radix-sort-01.png)

### Steps


### Time Complexity

### Resources & References

* #### [Brilliant](https://brilliant.org/wiki/radix-sort/)
* #### [Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
* #### [Youtube](https://www.youtube.com/watch?v=Il45xNUHGp0&list=PLdo5W4Nhv31bbKJzrsKfMpo_grxuLl8LU&index=107)
* #### [GeeksforGeeks](https://www.geeksforgeeks.org/radix-sort/)