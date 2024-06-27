#include <bits/stdc++.h>

using namespace std;

class GPSData {
public:
  vector<vector<bool>> coordinatesGrid;
  vector<pair<int, int>> xyList;

  GPSData() {
    // assumption: 0 <= x,y <= 10
    coordinatesGrid = vector<vector<bool>>(11, vector<bool>(11, false));
  }

  bool add(int x, int y) {
    // duplicate coordinate, return false:
    if (coordinatesGrid.at(x).at(y))
      return false;

    // add new coordinate:
    coordinatesGrid.at(x).at(y) = true;
    xyList.emplace_back(x, y);

    // not enough coordinates:
    if (xyList.size() < 4)
      return false;

    // search grid:
    return exploreGrid(x, y);
  }

  bool exploreGrid(int x, int y) {
    bool squareFound = false;

    for (const auto &xyCoord : xyList) {
      int x3 = xyCoord.first,
          y3 = xyCoord.second;

      int distanceX = abs(x3 - x),
          distanceY = abs(y3 - y);

      if (distanceX != distanceY)
        continue;

      if (distanceX == 0 || distanceY == 0)
        continue;

      if (coordinatesGrid.at(x).at(y3) && coordinatesGrid.at(x3).at(y)) {
        // cout << "\n" << x << "," << y3 << " and " << x3 << "," << y << "\n";
        squareFound = true;
        break;
      }
    }

    return squareFound;
  }

  void displayGrid(void) {
    cout << "== coordinates grid ==\n";
    for (int r{0}; r < coordinatesGrid.size(); r++) {
      for (int c{0}; c < coordinatesGrid.size(); c++) {
        cout << coordinatesGrid.at(r).at(c) << "  ";
      }
      cout << "\n";
    }
    cout << "\n";
  }
};

int main() {
  cout << boolalpha;

  GPSData data;
  bool squareFound = false;

  squareFound = data.add(1, 5);
  cout << "-> Square formed: " << squareFound << "\n"; // false: < 4 vertices

  squareFound = data.add(5, 1);
  cout << "-> Square formed: " << squareFound << "\n"; // false: < 4 vertices

  squareFound = data.add(5, 5);
  cout << "-> Square formed: " << squareFound << "\n"; // false: < 4 vertices

  squareFound = data.add(5, 5);
  cout << "-> Square formed: " << squareFound << "\n"; // false: repeated

  squareFound = data.add(2, 2);
  cout << "-> Square formed: " << squareFound << "\n"; // false: no square formed

  squareFound = data.add(1, 1);
  cout << "-> Square formed: " << squareFound << "\n"; // true: square formed

  squareFound = data.add(2, 5);
  cout << "-> Square formed: " << squareFound << "\n"; // true: square formed

  squareFound = data.add(5, 2);
  cout << "-> Square formed: " << squareFound << "\n"; // true: square formed

  return 0;
}