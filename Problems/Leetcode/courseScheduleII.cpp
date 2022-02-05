/*********************************************************************************************/
/* Problem: Course Schedule II (LC) ********/
/*********************************************************************************************/
/*
--Problem statement:
  There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
  You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must 
  take course bi first if you want to take course ai. For example, the pair [0, 1], indicates 
  that to take course 0 you have to first take course 1. Return the ordering of courses you 
  should take to finish all courses. If there are many valid answers, return any of them. If it 
  is impossible to finish all courses, return an empty array.
  > Example 1:
    Input: numCourses = 2, prerequisites = [[1,0]]
    Output: [0,1]
    Explanation: There are a total of 2 courses to take. To take course 1 you should have finished 
                course 0. So the correct course order is [0,1].

  > Example 2:
    Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
    Output: [0,2,1,3]
    Explanation: There are a total of 4 courses to take. To take course 3 you should have finished 
                both courses 1 and 2. Both courses 1 and 2 should be taken after you finished 
                course 0. So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].

  > Example 3:
    Input: numCourses = 1, prerequisites = []
    Output: [0]

--Inputs:
  -int: the number of courses 'n'.
  -vector<int>: array of prerequisites.

--Outputs:
  -vector<int>: array with elements representing the order in which the courses should be taken.

--Constraints:
    1 <= numCourses <= 2000
    0 <= prerequisites.length <= numCourses * (numCourses - 1)
    prerequisites[i].length == 2
    0 <= ai, bi < numCourses
    ai != bi
    All the pairs [ai, bi] are distinct.

--Reasoning: See comments below.

--Time complexity: 
  O(V + E), where V is the number of courses and E the edges representing the dependency relationship.

--Space complexity: O(V), where V is the number of courses.

*/
#include <iostream>
#include <queue>
#include <vector>

typedef std::vector<std::vector<int>> graph;

std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>> &prerequisites) {
  // output array containing the ordering of courses to be taken:
  std::vector<int> schedule;

  // adjacency list of size 'numCourses' initialized with empty vectors:
  graph g(numCourses, std::vector<int>());

  // queue for processing the nodes based on the number of incoming edges, in
  // increasing order:
  std::queue<int> processing;

  // vector to keep track of the number of incoming edges (in_degree) to each node:
  std::vector<int> in_degree(numCourses, 0);

  // build graph and count the number of incoming edges for each node:
  for (auto &p : prerequisites) {
    int u = p[1];
    int v = p[0];

    g[u].push_back(v);
    ++in_degree.at(v);
  }

  // get the starting point (first course to be taken), represented by a node
  // with no incoming edges which means that this course does not depend of
  // any other, i.e., there's no prerequisite for it:
  for (int in{0}; in < in_degree.size(); ++in) {
    if (in_degree.at(in) == 0)
      processing.push(in);
  }

  // while the processing queue is not empty, pop its front, add it to the schedule
  // and check its neighbors. For each of its  neighbors, "remove" the incoming edge
  // to it from the current node (--in_degree.at(next)), since this node is now
  // processed. If after the edge removal any of the neighbors have an in degree of 0,
  // add it to the precessing queue to be processed next:
  while (!processing.empty()) {
    int current_node = processing.front();
    processing.pop();

    schedule.push_back(current_node);

    for (auto &next : g.at(current_node)) {
      --in_degree.at(next);

      if (in_degree.at(next) == 0)
        processing.push(next);
    }
  }

  // return the schedule if all the courses were scheduled (schedule.size() == numCourses);
  // otherwise, it means that there was at least one course not processed, so return an
  // empty array:
  return ((schedule.size() == numCourses) ? schedule : std::vector<int>());
}