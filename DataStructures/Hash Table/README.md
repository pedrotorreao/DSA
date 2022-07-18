## Hash Table

See code examples by clicking [here](/DataStructures/Hash%20Table/src).

### Definition

Data structure useful for mapping `keys` to `values` which, on average, provides very fast lookups, insertions and deletions.

Imagine that we are working on a problem that requires us to store `[key: value]` pairs. Let's assume that both keys and values are integers. We could simply use an array of size `n`, `storage[n]`, where the keys could be represented by the array indexes and the values would be stored at these positions as seen below:

> `storage[key] = value`

where `key` is an integer in the range `0` to `n-1`.

Now, what if these `keys` are very large numbers or not numbers at all? We could very well have `strings` as `keys` datatype. Then, it would not be possible to directly use these `keys` as indexes, and they would have to go through some kind of _process_ in order to convert these `keys` into integers able to be used as indexes for `storage[n]`. The said _process_ is called **_hashing_** and it uses special functions called **_hash functions_** to perform the necessary convertions. In a simplified way, then, a Hash Table is basically a combination of a **_hash function_** and an array like `storage[n]`, for instance.

### Example

... Phonebook w/ company #

### Pseudocode

...

### Time complexity

...

### Space complexity

...

### Collision resolution techniques

...

### References

- [Hackerearth - Basics of Hash Tables ](https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/tutorial/)
- [Wikipedia - Hash Table](https://en.wikipedia.org/wiki/Hash_table)

### [Data Structures & Algorithms - Index](../../../README.md)
