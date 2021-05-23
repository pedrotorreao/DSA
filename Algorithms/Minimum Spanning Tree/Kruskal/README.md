## Kruskal

Check out the code for this algorithm [here](/Algorithms/Minimum%20Spanning%20Tree/Kruskal/kruskal.js).

### Definition

The Kruskal's algorithm is a greedy algorithm used to find the Minimum Spanning Tree for a connected weighted graph. The way it does this is by going through the graph and selecting edges based on their weight from lowest to highest while avoiding edges which will create cycles.

- [Minimum Spanning Tree](/DataStructures/Graphs/Minimum%20Spanning%20Tree/README.md)

The algorithm initially places all the nodes of the original graph isolated from each other, using, in this case, a Disjoint Set Union data structure, to form a forest of isolated sets, and then gradually merges these sets, combining at each iteration any two of all the sets with some edge of the original graph. Additionaly, before the execution of the algorithm, all edges are sorted by weight in non-decreasing order using either a sorting algorithm like quick sort or a priority queue data structure. Next, select all edges from the first to the last in sorted order and, if the ends of the currently picked edge belong to different sets (i.e. they have different set representatives), merge the sets and add the edge to the answer. After iterating through all the edges, all the vertices will belong to the same set, and we will get the answer.

- [Disjoint Set Union](/DataStructures/Disjoint%20Set/README.md)

### Example

Below is an image containing a graph and its minimum spanning tree. It is good to mention that in case there are different edges with the same weight, the minimum spanning tree found will not be unique.

![kruskal](/resources/img/kruskal-prim.png)

The first step for the algorithm is to create a disjoint set for each vertex , i.e. `make_set` operation, which leaves us with six sets,

> Sets: `A B C D E F`

Next, the algorithm uses a sorting method, i.e. a sorting algorithm or a priority queue, to sort the graph's edges by weight. The edges are structured in tuples `(from,to,weight)`. After the sorting, the list of edges become the following:

> `[B,C,1], [C,E,2], [D,E,3], [A,C,4], [B,D,5], [B,E,6], [E,F,7], [F,D,8], [A,B,9]`

After that, the algorithm iterates through the sorted edge' list, and for each edge from a vertex `u` to a vertex `v`, if `u` and `v` are in different sets, i.e. `find_set` operation returns different set representatives for these vertices, it means the current edge was not checked yet so add edge to the MST, merge sets `u` and `v` and add edge weight to the total cost. So, applying this step to the example above:

- edge `[B,C,1]`: as each vertex is an isolated set initially, the operation `find_set` will return different set representatives for `B` and `C`, so merge these sets, add edge `[B,C,1]` to the MST and update total cost, resulting in:

> MST = [`[B,C,1]`]
>
> Total Cost = 0 + 1 = 1
>
> Sets: `A BC D E F`

- edge `[C,E,2]`: the operation `find_set` will once again return different set representatives for `C` and `E`, indicating that they're part of different sets, so merge these sets, add edge `[C,E,2]` to the MST and update total cost:

> MST = [`[B,C,1]`, `[C,E,2]`]
>
> Total Cost = 1 + 2 = 3
>
> Sets: `A BCE D F`

- edge `[D,E,3]`: `D` and `E` are part of different sets, so merge these sets, add edge `[D,E,3]` to the MST and update total cost:

> MST = [`[B,C,1]`, `[C,E,2]`, `[D,E,3]`]
>
> Total Cost = 3 + 3 = 6
>
> Sets: `A BCED F`

- edge `[A,C,4]`: `A` and `C` are part of different sets, so merge these sets, add edge `[A,C,4]` to the MST and update total cost:

> MST = [`[B,C,1]`, `[C,E,2]`, `[D,E,3]`, `[A,C,4]`]
>
> Total Cost = 6 + 4 = 10
>
> Sets: `ABCED F`

- edge `[B,D,5]`: `B` and `D` are already part of the same set, so adding this edge to the MST would form a cycle, which goes against the MST rules so the algorithm skips this edge:

> MST = [`[B,C,1]`, `[C,E,2]`, `[D,E,3]`, `[A,C,4]`]
>
> Total Cost = 10
>
> Sets: `ABCED F`

- edge `[B,E,6]`: `B` and `E` are already part of the same set, so adding this edge to the MST would form a cycle, which goes against the MST rules so the algorithm skips this edge:

> MST = [`[B,C,1]`, `[C,E,2]`, `[D,E,3]`, `[A,C,4]`]
>
> Total Cost = 10
>
> Sets: `ABCED F`

- edge `[E,F,7]`: `E` and `F` are part of different sets, so merge these sets, add edge `[E,F,7]` to the MST and update total cost:

> MST = [`[B,C,1]`, `[C,E,2]`, `[D,E,3]`, `[A,C,4]`, `[E,F,7]`]
>
> Total Cost = 10 + 7 = 17
>
> Sets: `ABCEDF`

We could keep going and check the last two edges; however, at this point we can see that all the nodes belong to the same set so there are no merges left to be done. Also, one of the properties of a Minimum Spanning Tree states that the number of edges in the MST will be `V-1`, where `V` is the number of vertices in the graph. Here the number of vertices is 6, and there are already 5 edges in the MST, so the algorithm is done.

### Pseudocode

See below a basic pseudocode for the Kruskal's algorithm:

```
kruskal(graph):
    create a disjoint set for each vertex in the graph
    sort the edges of the graph in ascending order (use a sorting algo or a priority queue)
    for each edge which connects u to v:
        if u and v are not in the same set:
            add edge to the MST
            merge sets u and v
            add the cost of going from u to v to the total cost
        end if
    end for
end
```

### Time complexity

- O(E\*log(E)), where `E` is the number of edges in the graph.

### Space complexity

- O(V), where `V` is the number of vertices. This is due to the `make_set` opration creating `V` isolated sets.

### References

- [CP - Algorithms](https://cp-algorithms.com/graph/mst_kruskal.html)
- [CP - Algorithms](https://cp-algorithms.com/graph/mst_kruskal_with_dsu.html)
- [YouTube - William Fiset](https://www.youtube.com/watch?v=pSqmAO-m7Lk&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=18)
- [YouTube - Jenny's Lectures](https://www.youtube.com/watch?v=EjVHtpWkIho&list=PLdo5W4Nhv31bbKJzrsKfMpo_grxuLl8LU&index=85)
- [YouTube - Abdul Bari](https://www.youtube.com/watch?v=4ZlRH0eK-qQ&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=46)

### [Data Structures & Algorithms - Index](../../../README.md)
