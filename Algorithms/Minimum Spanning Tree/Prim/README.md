## Prim

Check out the code for this algorithm [here](/Algorithms/Minimum%20Spanning%20Tree/Prim/prim.js).

### Definition

The Prim's algorithm also takes a greedy approach for finding the Minimum Spanning Tree (MST) for a connected weighted graph, so it always try to select the next best edge and adds it to the MST.

- [Minimum Spanning Tree](/DataStructures/Graphs/Minimum%20Spanning%20Tree/README.md)

Here's the basics on how the Prim's algorithm works. A Priority Queue (PQ) is used to have all edges sorted based on their edge costs, from lowest to highest, which will be used to determine the next vertex to visit and which edge will be used in order to get there. The algorithm selects a starting vertex `source`, which can be any vertex, marks `source` as visited, iterates over all of its edges and add them to the priority queue. Next, while the priority queue is not empty and the MST has not yet been formed, i.e. it does not have `V-1` edges, dequeue the next cheapest edge from the priority queue. The algorithm then checks if the vertex connected by this edge has already been visited, if not, mark the current vertex as visited and add the selected edge to the MST, if so, skip this edge and dequeue the next one. Iterate over the new current vertex' edges and, if the edge is not pointing to already visited vertices, add it to the priority queue.

### Example

Below is an image containing a undirected graph and its minimum spanning tree. It is good to mention that in case there are different edges with the same weight, the minimum spanning tree found will not be unique.

![kruskal](/resources/img/kruskal-prim.png)

Let's go through this example. Consider that the starting vertex selected by the algorithm is vertex `A`. The algorithm then iterates through all of `A`'s edges, adds them to the priority queue PQ, as they point to not visited yet vertices, and mark `A` as visited:

> Visited: `A`
>
> PQ: `[A,B,9]`, `[A,C,4]`
>
> MST: `empty`
>
> Total cost: `0`

Next, the algorithm dequeues the next cheapest edge from `PQ`, which is `[A,C,4]`, adds it to the MST, marks `C` as visited and iterates over all of `C`'s edges adding them to `PQ` in case they point to unvisited vertices. Notice that edge `[C,A,4]` is not added since it points to vertex `A` which was already visited:

> Visited: `A`, `C`
>
> PQ: `[A,B,9]`, `[C,B,1]`, `[C,E,2]`
>
> MST: `[A,C,4]`
>
> Total cost: `0 + 4 = 4`

The next cheapest edge from `PQ` to be dequeued is `[C,B,1]`. This edge gets added to the MST, `B` is marked as visited and the algorithm iterates over all of `B`'s edges adding them to `PQ` in case they point to unvisited vertices. Notice that edges `[B,A,9]` and `[B,C,1]` are not added since it points to vertices `A` and `C` which were already visited:

> Visited: `A`, `C`, `B`
>
> PQ: `[A,B,9]`, `[C,E,2]`, `[B,D,5]`, `[B,E,6]`
>
> MST: `[A,C,4]`, `[C,B,1]`
>
> Total cost: `4 + 1 = 5`

The next cheapest edge from `PQ` to be dequeued is `[C,E,2]`. This edge gets added to the MST, `E` is marked as visited and the algorithm iterates over all of `E`'s edges adding them to `PQ` in case they point to unvisited vertices. Notice that edges `[E,C,2]` and `[E,B,6]` are not added since it points to vertices `C` and `B` which were already visited:

> Visited: `A`, `C`, `B`, `E`
>
> PQ: `[A,B,9]`, `[B,D,5]`, `[B,E,6]`, `[E,D,3]`, `[E,F,7]`
>
> MST: `[A,C,4]`, `[C,B,1]`, `[C,E,2]`
>
> Total cost: `5 + 2 = 7`

Next, the algorithm dequeues the next cheapest edge from `PQ`, which is `[E,D,3]`, adds it to the MST, marks `D` as visited and iterates over all of `D`'s edges adding them to `PQ` in case they point to unvisited vertices. Notice that only edge `[D,F,8]` gets added to the `PQ` since all the other vertices to which vertex `D` is connected to have already been visited:

> Visited: `A`, `C`, `B`, `E`, `D`
>
> PQ: `[A,B,9]`, `[B,D,5]`, `[B,E,6]`, `[E,F,7]`, `[D,F,8]`
>
> MST: `[A,C,4]`, `[C,B,1]`, `[C,E,2]`, `[E,D,3]`
>
> Total cost: `7 + 3 = 10`

The next cheapest edge dequeued from `PQ` is `[B,D,5]`, but since both `B` and `D` have already been visited, this edge is not added to the MST and the algorithm skips it and dequeues the next one, which is `[B,E,6]`. However, the same happens to this edge, since vertices `B` and `E` have been visited. The next cheapest edge dequeued from `PQ` is `[E,F,7]`. Since vertex `F` has not been visited yet, this edge gets added to the MST, `F` is marked as visited and the algorithm iterates over all of `F`'s edges adding them to `PQ` in case they point to unvisited vertices. In this case, there are no edges to be added to the `PQ` since there are no vertices left unvisited:

> Visited: `A`, `C`, `B`, `E`, `D`, `F`
>
> PQ: `[A,B,9]`, `[D,F,8]`
>
> MST: `[A,C,4]`, `[C,B,1]`, `[C,E,2]`, `[E,D,3]`, `[E,F,7]`
>
> Total cost: `10 + 7 = 17`

We could keep going and check the next edges until the priority queue is left empty; however, at this point we can see that all the vertices have been visited. Also, one of the properties of a Minimum Spanning Tree states that the number of edges in the MST will be `V-1`, where `V` is the number of vertices in the graph. Here the number of vertices is 6, and there are already 5 edges in the MST, so the algorithm is done.

### Pseudocode

See below a basic pseudocode for the Prim's algorithm:

```
prim(graph):
    > keep a priority queue (PQ) which will sort the edges based on their weights
    > choose a starting vertex (src)
    > iterate over src's edges and add them to the PQ
    > mark src as visited

    while pq is not empty and the number of edges in the MST is not V-1:
        > dequeue the next cheapest edge (nxt)
        if nxt points to an unvisited vertex (nxtTo):
            > add nxt to the MST
            > add nxt weight to the total cost
            > mark nxtTo as visited
            iterate over nxtTo edges:
                > add edge to PQ in case they point to unvisited vertices
            end
        end if
    end while
end

```

### Time complexity

- O(E\*log(E)), where `E` is the number of edges in the graph.

### Space complexity

- O(V), where `V` is the number of vertices.

### References

- [CP - Algorithms](https://cp-algorithms.com/graph/mst_prim.html)
- [YouTube - William Fiset](https://www.youtube.com/watch?v=jsmMtJpPnhU&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=33)
- [YouTube - Jenny's Lectures](https://www.youtube.com/watch?v=AT14lCXuMKI&list=PLdo5W4Nhv31bbKJzrsKfMpo_grxuLl8LU)
- [YouTube - Abdul Bari](https://www.youtube.com/watch?v=4ZlRH0eK-qQ&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=46)

### [Data Structures & Algorithms - Index](../../../README.md)
