## Array

### Definition

Array is a fundamental data structure which consists of a collection of elements and all elements are of the same type. Array elements can be accessed directly by using its position/index keeping in mind that arrays are zero-based which means that its position count begins at 0.

Arrays are usually stored contiguously in memory, which just means that all elements are stored sequentially one after the other in memory. This can be very important when considering arrays as data storage due to something called [cache locality](#cache-locality). 

Regarding size, arrays may be classified as static or dynamic:
* _Static_: fixed size. Ex.: C and C++ arrays.
* _Dynamic_: memory is allocated on demand, which usually means that when an array reaches its capacity, a new chunk of memory is allocated with (most of the time) double the original size and the original the array elements are copied to this new location. Ex.: C++ vectors, JavaScript and Python arrays.

#### Keypoints - Arrays ...
* ... are usually stored contiguously in memory
* ... may be static or dynamic regarding its size

For the next sections below, arrays are going to be represented using C++, which is a strongly typed language.

### Declaration & Initialization

`code example`

### Accessing & Modifying

`code example`

### Time Complexity

| Access | Search | Insertion | Deletion |
|:------:|:------:|:---------:|:--------:|
|  O(1)  |  O(n)  |    O(n)   |   O(n)   |

### Space Complexity


### Extra
#### Cache locality

