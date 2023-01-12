/***************************************************************************************/
/* Problem: LC 733. Flood Fill *********************************************************/
/***************************************************************************************/
/*
--Problem statement:

  An image is represented by an m x n integer grid image where image[i][j] represents the
  pixel value of the image.
  You are also given three integers sr, sc, and color. You should perform a flood fill on
  the image starting from the pixel image[sr][sc].
  To perform a flood fill, consider the starting pixel, plus any pixels connected
  4-directionally to the starting pixel of the same color as the starting pixel, plus any
  pixels connected 4-directionally to those pixels (also with the same color), and so on.
  Replace the color of all of the aforementioned pixels with color.

  Return the modified image after performing the flood fill.

  > Example 1:
    Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
    Output: [[2,2,2],[2,2,0],[2,0,1]]
    Explanation:
      From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all
      pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels)
      are colored with the new color.
      Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.

  > Example 2:
    Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
    Output: [[0,0,0],[0,0,0]]
    Explanation:
      The starting pixel is already colored 0, so no changes are made to the image.

--Inputs:
  -int[]: array of integers 'nums'
  -int: number of possible flips 'k'

--Output:
  -int: maximum number of consecutive 1's by flip at most 'k' 0's

--Constraints:
    :: m == image.length
    :: n == image[i].length
    :: 1 <= m, n <= 50
    :: 0 <= image[i][j], color < 216
    :: 0 <= sr < m
    :: 0 <= sc < n

--Reasoning: See comments below.

--Time complexity: O(R*C)
    R: number of rows
    C: number of columns
    In the worst case, we may need to fill the whole matrix.

--Space complexity: O(R*C)
    For the recursion stack when we need to fill the whole matrix.
*/

#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

template <typename T>
void display2D(const std::vector<std::vector<T>> &grid) {
  for (int i{0}; i < grid.size(); ++i) {
    for (int j{0}; j < grid.at(0).size(); ++j) {
      std::cout << grid.at(i).at(j) << "  ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}

void bfsPaint(std::vector<std::vector<int>> &grid, int row, int col,
              int color, int originalColor,
              const int R, const int C) {

  std::queue<std::pair<int, int>> neighbors;
  neighbors.push({row, col});

  while (!neighbors.empty()) {
    auto [currRow, currCol] = neighbors.front();
    neighbors.pop();

    // base case - current cell is beyond grid limits, i.e. invalid:
    if (currRow >= R || currRow < 0 || currCol >= C || currCol < 0)
      continue;
    // base case - current cell has a different color than de original color:
    if (grid.at(currRow).at(currCol) != originalColor)
      continue;

    // update cell color to new color:
    grid.at(currRow).at(currCol) = color;

    // add neighboring cells to queue:
    neighbors.push({currRow + 1, currCol}); // down
    neighbors.push({currRow, currCol + 1}); // right
    neighbors.push({currRow - 1, currCol}); // down
    neighbors.push({currRow, currCol - 1}); // left
  }
}

void dfsPaint(std::vector<std::vector<int>> &grid, int row, int col,
              int color, int originalColor,
              const int R, const int C) {
  // base case - current cell is beyond grid limits, i.e. invalid:
  if (row >= R || row < 0 || col >= C || col < 0)
    return;
  // base case - current cell has a different color than de original color:
  if (grid.at(row).at(col) != originalColor)
    return;

  // update cell color to new color:
  grid.at(row).at(col) = color;

  // recursively visit neighboring cells:
  dfsPaint(grid, row + 1, col, color, originalColor, R, C); // down
  dfsPaint(grid, row, col + 1, color, originalColor, R, C); // right
  dfsPaint(grid, row - 1, col, color, originalColor, R, C); // up
  dfsPaint(grid, row, col - 1, color, originalColor, R, C); // left
}

std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>> &image, int row, int col, int color) {
  std::vector<std::vector<int>> paintedImg(image);

  const int ROWS = paintedImg.size();
  const int COLS = paintedImg.at(0).size();

  int originalColor = paintedImg.at(row).at(col);

  if (color == originalColor)
    return paintedImg;

  dfsPaint(paintedImg, row, col, color, originalColor, ROWS, COLS);

  return paintedImg;
}

int main() {
  std::vector<std::vector<int>> mat{}, res{};

  mat = {{0, 1, 1, 1, 0},
         {0, 0, 0, 1, 1},
         {0, 1, 1, 1, 0},
         {0, 1, 1, 0, 0},
         {0, 0, 0, 0, 0}};
  std::cout << "-- Original matrix:\n";
  display2D(mat);
  res = floodFill(mat, 1, 3, 2);
  std::cout << "-- Modified matrix:\n";
  display2D(res);
  std::cout << "-- -- -- -- --\n\n";

  mat = {{0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0},
         {0, 0, 1, 1, 0},
         {0, 0, 1, 0, 0},
         {0, 0, 1, 0, 0}};
  std::cout << "-- Original matrix:\n";
  display2D(mat);
  res = floodFill(mat, 3, 2, 5);
  std::cout << "-- Modified matrix:\n";
  display2D(res);
  std::cout << "-- -- -- -- --\n\n";

  return 0;
}