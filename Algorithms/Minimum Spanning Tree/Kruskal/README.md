## Kruskal

Check out the code for this algorithm [here](/Algorithms/Minimum%20Spanning%20Tree/Kruskal/kruskal.js).

### Definition

The Kruskal's algorithm is a greedy algorithm used to find the Minimum Spanning Tree for a connected wighted graph. The way it does this is by going through the graph and selecting edges based on their weight from lowest to highest while avoinding edges which will create cycles.

- [Minimum Spanning Tree](/DataStructures/Graphs/Minimum%20Spanning%20Tree/README.md)

The algorithm initially places all the nodes of the original graph isolated from each other, using, in this case, a Disjoint Set Union data structure, to form a forest of isolated sets, and then gradually merges these sets, combining at each iteration any two of all the sets with some edge of the original graph. Additionaly, before the execution of the algorithm, all edges are sorted by weight in non-decreasing order using either a sorting algorithm like quick sort or a priority queue data structure. Next, select all edges from the first to the last in sorted order and, if the ends of the currently picked edge belong to different sets (i.e. they have different set representatives), merge the sets and add the edge to the answer. After iterating through all the edges, all the vertices will belong to the same set, and we will get the answer.

- [Disjoint Set Union](/DataStructures/Disjoint%20Set/README.md)

### Example

![kruskal](/resources/img/kruskal-prim.png)

### Pseudocode

See below a basic pseudocode for the Kruskal's algorithm:

```
kruskal(graph):
    create a disjoint set for each vertex in the graph
    sort the edges of the graph in ascending order (use a sorting algo or a priority queue)
    for each edge which connects u to v:
        if u and v are not in the same set:
            merge sets u and v
            add the cost of going from u to v to the total cost
        end if
    end for
end
```

### Time complexity

### Space complexity

### References

- [CP - Algorithms](https://cp-algorithms.com/graph/mst_kruskal.html)
- [CP - Algorithms](https://cp-algorithms.com/graph/mst_kruskal_with_dsu.html)
- [YouTube - William Fiset](https://www.youtube.com/watch?v=pSqmAO-m7Lk&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=18)
- [YouTube - Jenny's Lectures](https://www.youtube.com/watch?v=EjVHtpWkIho&list=PLdo5W4Nhv31bbKJzrsKfMpo_grxuLl8LU&index=85)
- [YouTube - Abdul Bari](https://www.youtube.com/watch?v=4ZlRH0eK-qQ&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=46)

### [Data Structures & Algorithms - Index](../../../README.md)
