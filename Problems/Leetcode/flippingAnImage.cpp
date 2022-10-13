/*********************************************************************************************/
/* Problem: Flipping an Image (LC) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given an n x n binary matrix image, flip the image horizontally, then invert it, and return
  the resulting image.
  To flip an image horizontally means that each row of the image is reversed. For example,
  flipping [1,1,0] horizontally results in [0,1,1].
  To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example,
  inverting [0,1,1] results in [1,0,0].

  > Example 1:
    Input: image = [[1,1,0],[1,0,1],[0,0,0]]
    Output: [[1,0,0],[0,1,0],[1,1,1]]
    Explanation:
      First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
      Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]

  > Example 2:
    Input: image = [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
    Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
    Explanation:
      First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
      Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]

--Input:
  int[][]: n x n binary matrix.

--Output:
  int[][]: n x n flipped binary matrix.

--Reasoning: regular taversal of 2d array.

--Constraints:
  :: n == image.length
  :: n == image[i].length
  :: 1 <= n <= 20
  :: images[i][j] is either 0 or 1.

--Time complexity: O(N^2)

--Space complexity: O(1), since we are returning the modified input matrix.

*******************************************************************************/
#include <iostream>
#include <vector>

void flipRow(std::vector<int> &vec);
void reverseRow(std::vector<int> &vec);
void displayImg(std::vector<std::vector<int>> &image);

std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>> &image) {
  const int N = image.size();

  for (int r{0}; r < N; ++r) {
    flipRow(image.at(r));
    reverseRow(image.at(r));
  }

  return image;
}

int main() {

  std::vector<std::vector<int>> img{{1, 1, 0}, {1, 0, 1}, {0, 0, 0}};
  flipAndInvertImage(img);
  displayImg(img); // output: [[1,0,0],[0,1,0],[1,1,1]]

  img = {{1, 1, 0, 0}, {1, 0, 0, 1}, {0, 1, 1, 1}, {1, 0, 1, 0}};
  flipAndInvertImage(img);
  displayImg(img);

  return 0;
}

void flipRow(std::vector<int> &vec) {
  int i = 0, j = vec.size() - 1;

  while (i <= j) {
    int t = vec.at(i);

    vec.at(i) = vec.at(j);
    vec.at(j) = t;

    ++i;
    --j;
  }
}

void reverseRow(std::vector<int> &vec) {
  for (auto &v : vec) {
    if (v == 0)
      v = 1;
    else
      v = 0;
  }
}

void displayImg(std::vector<std::vector<int>> &image) {
  for (auto &row : image) {
    for (auto &r : row) {
      std::cout << r << "  ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}