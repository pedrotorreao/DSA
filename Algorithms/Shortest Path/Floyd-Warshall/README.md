## Floyd-Warshall

See the code by clicking [here](/Algorithms/Shortest%20Path/Floyd-Warshall/floyd-warshall.js).

### Definition

The Floyd-Warshall is an All-Pairs Shortest Path (APSP) algorithm. This means that it can find the shortest path between all pairs of nodes, as long as they are reachable. This algorithm has a time complexity of **`O(V^3)`**, so it is better suited for small graphs.

For the Floyd-Warshall algorithm, the optimal way to represent a graph is by using an adjacency matrix. Consider an adjacency matrix `M`, the element at `M[i][j]` represent the edge's weight of going from vertex `i` to vertex `j`. For example, consider the graph below:

- Graph:

![floyd-warshall1](../../../resources/img/floyd-warshall1.png)

It is assumed that the distance from a vertex to itself is zero. Therefore, the diagonal has only zeros. Additionally, if there is no edge connecting vertix `i` to vertex `j`, the edge weigth at is set to positive **Inf**inity. See below the Adjacency Matrix which represents the graph shown above:

- Adjacency Matrix:

|     |   A   |   B   |   C   |   D   |
| :-: | :---: | :---: | :---: | :---: |
|  A  |  `0`  |  `4`  |  `1`  | `Inf` |
|  B  | `Inf` |  `0`  |  `6`  | `Inf` |
|  C  |  `4`  |  `1`  |  `0`  |  `2`  |
|  D  | `Inf` | `Inf` | `Inf` |  `0`  |

The way this algorithm works is that it compares all possible paths through the graph between each pair of vertices, testing every combination of edges. This process is performed by incrementally improving an estimate on the shortest path between the two vertices, until the estimate is optimal.

Let's say we wanted to find the path from vertex `A` to vertex `B`. By taking a look at the adjancency matrix for the graph given above we can see that there is a direct edge connecting `A` to `B` and its weight is `4`, so considering the matrix rows (`i`) as the starting points and the columns (`j`) as the destinations, the cost for going from `A` to `B` can be expressed by the following:

> distance from A to B:
>
> `distance[A][B]` => `distance[i][j] = distance[0][1] = 4`

The behavior of the Floyd-Warshall algorithm can then be summarized by the following expression:

> `distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j])`

where `k` can represent either a single vertex or a path that connects vertex `i` to vertex `j`.

### Pseudocode

See below a basic pseudocode for the Floyd-Warshall algorithm:

```
Floyd-Warshall(G):
    n: number of vertices on the graph
    distance: nxn matrix to store the shortest paths, initialize it with 0s

    copy G to D

    for k=0 to k=n-1:
        for i=0 to i=n-1:
            for j=0 to j=n-1:
                if distance[i][j] > distance[i][k] + distance[k][j]:
                    distance[i][j] = distance[i][k] + distance[k][j]
                end if
            end for
        end for
    end for

    return distance matrix
```

### Time complexity

### Space complexity

### References

- [YouTube - William Fiset](https://www.youtube.com/watch?v=4NQ3HnhyNfQ&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=21)
- [YouTube - Jenny's Lectures](https://www.youtube.com/watch?v=Gc4mWrmJBsw&list=PLdo5W4Nhv31bbKJzrsKfMpo_grxuLl8LU&index=95)
- [YouTube - Abdul Bari](https://www.youtube.com/watch?v=oNI0rf2P9gE&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=50)
- [CP - Algorithms](https://cp-algorithms.com/graph/all-pair-shortest-path-floyd-warshall.html)

### [Data Structures & Algorithm - Index](../../../README.md)
