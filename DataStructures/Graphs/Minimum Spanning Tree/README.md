## Minimum Spanning Tree - MST

### Definition

Consider a connected, weighted, undirected graph `G`, containing `V` vertices and `E` edges, a Minimum Spanning Tree (MST) is a subset of this graph such that:

- All vertices are connected together (i.e. there are no isolated vertices);
- There are no cycles;
- The total sum of the edge weights is the lowest possible.

### Some properties

- The spanning tree should not contain any cycles;
- The spanning tree should not be disconnected (that would be a spanning forest);
- Removing any of the edges in a spanning tree will make it become disconnected;
- Adding on more edge to a spanning tree creates a cycle;
- If each edge in the graph has a distinct weight, then there will be only one unique MST; otherwise, there can be multiple MSTs.
- From a complete graph, it is possible to build a spanning tree by removing `max(E-V+1)` edges.

### Example

A common approach to follow in order to build the MST is to add edge by edge beginning from the edge with the lowest cost up until all vertices are connected and there no cycles. By following these simple steps we are able to reduce the graph shown below to its Minimum Spanning Tree.

![mst](../../../resources/img/minimum%20spanning%20tree.png)

Two common algorithms used for finding the Minimum Spanning Tree are:

- [Kruskal's Algorithm](/Algorithms/Minimum%20Spanning%20Tree/Kruskal/README.md)
- [Prim's Algorithm](/Algorithms/Minimum%20Spanning%20Tree/Prim/README.md)

### References

- [Hackerearth - Minimum Spanning Tree](https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/)
- [CP-Algorithms](https://cp-algorithms.com/graph/mst_kruskal.html)

### [Data Structures & Algorithm - Index](../../../README.md)
