/*********************************************************************************************/
/* Problem: L Shaped Plots ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given a grid of R rows and C columns each cell in the grid is either 0 or 1. A segment is a 
  nonempty sequence of consecutive cells such that all cells are in the same row or the same 
  column. We define the length of a segment as number of cells in the sequence.
  A segment is called "good" if all the cells in the segment contain only 1s.
  An "L-shape" is defined as an unordered pair of segments, which has all the following properties:
    - Each of the segments must be a "good" segment.
    - The two segments must be perpendicular to each other.
    - The segments must share one cell that is an endpoint of both segments.
    - Segments must have length at least 2.
    - The length of the longer segment is twice the length of the shorter segment. 
  We need to count the number of L-shapes in the grid.

--Input:
  The first line of the input contains the number of test cases, T. T test cases follow.
  The first line of each testcase contains two integers R and C. Then, R lines follow, each line 
  with C integers representing the cells of the grid.

--Output:
  For each test case, output one line containing Case #x: y, where x is the test case number 
  (starting from 1) and y is the number of L-shapes. 

*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fillGrid(vector<vector<int>> &grid, int &r, int &c)
{
  for (int row{0}; row < r; row++)
  {
    for (int col{0}; col < c; col++)
    {
      cin >> grid.at(row).at(col);
    }
  }
}

void solve(int tc)
{
  int r, c;
  cin >> r >> c;

  vector<vector<int>> m(r, vector<int>(c));
  fillGrid(m, r, c);

  vector<vector<int>> count_up(r, vector<int>(c));
  vector<vector<int>> count_down(r, vector<int>(c));
  vector<vector<int>> count_left(r, vector<int>(c));
  vector<vector<int>> count_right(r, vector<int>(c));

  // calculate segment lengths horizontally:
  for (int row{0}; row < r; row++)
  {
    // count 1s to the left:
    for (int col{0}; col < c; col++)
    {
      if (m.at(row).at(col) == 1)
      {
        count_left.at(row).at(col) = 1;
        if (col >= 1)
        {
          count_left.at(row).at(col) += count_left.at(row).at(col - 1);
        }
      }
    }

    // count 1s to the left:
    for (int col{c - 1}; col >= 0; col--)
    {
      if (m.at(row).at(col) == 1)
      {
        count_right.at(row).at(col) = 1;
        if (col < c - 1)
        {
          count_right.at(row).at(col) += count_right.at(row).at(col + 1);
        }
      }
    }
  }

  // calculate segment lengths vertically:
  for (int col{0}; col < c; col++)
  {
    // count 1s going up:
    for (int row{0}; row < r; row++)
    {
      if (m.at(row).at(col) == 1)
      {
        count_up.at(row).at(col) = 1;
        if (row >= 1)
        {
          count_up.at(row).at(col) += count_up.at(row - 1).at(col);
        }
      }
    }

    // count 1s going down:
    for (int row{r - 1}; row >= 0; row--)
    {
      if (m.at(row).at(col) == 1)
      {
        count_down.at(row).at(col) = 1;
        if (row < r - 1)
        {
          count_down.at(row).at(col) += count_down.at(row + 1).at(col);
        }
      }
    }
  }

  ll l_shaped_plots{0};
  for (int row{0}; row < r; row++)
  {
    for (int col{0}; col < c; col++)
    {
      l_shaped_plots += max(0, min(count_left[row][col], (count_up[row][col] / 2)) - 1);
      l_shaped_plots += max(0, min((count_left[row][col] / 2), count_up[row][col]) - 1);
      l_shaped_plots += max(0, min(count_left[row][col], (count_down[row][col] / 2)) - 1);
      l_shaped_plots += max(0, min((count_left[row][col] / 2), count_down[row][col]) - 1);

      l_shaped_plots += max(0, min(count_right[row][col], (count_up[row][col] / 2)) - 1);
      l_shaped_plots += max(0, min((count_right[row][col] / 2), count_up[row][col]) - 1);
      l_shaped_plots += max(0, min(count_right[row][col], (count_down[row][col] / 2)) - 1);
      l_shaped_plots += max(0, min((count_right[row][col] / 2), count_down[row][col]) - 1);
    }
  }

  cout << "Case #" << tc << ": " << l_shaped_plots << "\n";
}

int main()
{
  // disables the synchronization between the C and C++ standard streams:
  ios::sync_with_stdio(false);
  // unties cin from cout:
  cin.tie(NULL);
  // test case:
  int tc{0};

  cin >> tc;

  for (int i{1}; i <= tc; i++)
  {
    solve(i);
  }

  return 0;
}

/* Test case:
2
4 3
1 0 0
1 0 1
1 0 0
1 1 0
6 4
1 0 0 0
1 0 0 1
1 1 1 1
1 0 1 0
1 0 1 0
1 1 1 0
*/