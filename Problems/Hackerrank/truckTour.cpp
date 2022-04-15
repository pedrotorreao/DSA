/*********************************************************************************************/
/* Problem: Truck Tour (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Suppose there is a circle. There are N petrol pumps on that circle. Petrol pumps are numbered 0
  to (N-1) (both inclusive). You have two pieces of information corresponding to each of the
  petrol pumpS:
    1) the amount of petrol that particular petrol pump will give
    2) the distance from that petrol pump to the next petrol pump

  Initially, you have a tank of infinite capacity carrying no petrol. You can start the tour at any
  of the petrol pumps. Calculate the first point from where the truck will be able to complete the
  circle. Consider that the truck will stop at each of the petrol pumps. The truck will move one
  kilometer for each litre of the petrol.
  > Example:
    arr = [ [1,5], [10,3], [3,4] ]
    We cannot begin from i=0 since the amount of fuel the pump provides is less than the cost to reach
    the next. However, we can begin from i=1.

--Inputs:
  -int arr[n][N]: pumps information

--Output:
  -int: smallest index of the petrol pump from which we can start the tour.

--Constraints:
  1<=N<=10^5
  1<=amount of petrol, distance <= 10^9

--Reasoning:
  We cannot begin from a pump which gives an amount of fuel that's less than the distance to the next pump.
  --approach #1:
  Since the problem does not specify, we'll assume that there is always a solution and iterate over all the
  pumps. If at some point the amount of fuel is not enough to reach the next pump, we restart the route to
  begin from the next pump which satisfies the condition. Since we're assuming the existence of a solution,
  there's no need to wrap around and check the conditions again for the skipped pumps.
  --approach #2:
  For this one we make no assumptions and use a queue in order to wrap around and simulate the circular route.

--Time complexity: O(N), where N is the number of buildings.

--Space complexity:
  --approach #1: O(1), no additional input dependent space is needed.
  --approach #2: O(N), due to the use of the queue.

*/

#include <iostream>
#include <queue>
#include <vector>

// --approach #1:
int truckTour_1(std::vector<std::vector<int>> petrolpumps) {
  long fuelRemaining{0};
  int firstPumpID{0}, n = petrolpumps.size();

  for (int i{0}; i < n; ++i) {
    long fuelPlus = petrolpumps.at(i).at(0);
    long costNext = petrolpumps.at(i).at(1);

    fuelRemaining += fuelPlus - costNext;

    if (fuelRemaining < 0) {
      firstPumpID = i + 1;
      fuelRemaining = 0;
    }
  }

  return firstPumpID;
}

// --approach #2:
int truckTour_2(std::vector<std::vector<int>> petrolpumps) {
  int numOfPumps = petrolpumps.size();
  std::queue<std::pair<int, int>> truckRoute;

  // feed queue:
  for (int i{0}; i < numOfPumps; ++i) {
    long currFuel = petrolpumps.at(i).at(0);
    long nextCost = petrolpumps.at(i).at(1);

    truckRoute.push(std::make_pair(currFuel, nextCost));
  }

  int pumpsVisited{0}, routeStart{0};
  long fuelLeft{0};

  // iterate while there are pumps left to visit:
  while (pumpsVisited < numOfPumps) {
    std::pair<int, int> currPump = truckRoute.front();
    truckRoute.pop();

    fuelLeft += currPump.first;

    if (fuelLeft >= currPump.second) {
      pumpsVisited++;
      fuelLeft -= currPump.second;
    } else {
      routeStart += pumpsVisited + 1;
      pumpsVisited = 0;
      fuelLeft = 0;
    }

    truckRoute.push(currPump);
  }

  return routeStart;
}

int main() {
  std::vector<std::vector<int>> petrolpumps{{1, 5}, {10, 3}, {3, 4}};
  std::cout << "route start:\n"
            << "--approach #1: " << truckTour_1(petrolpumps) << "\n"
            << "--approach #2: " << truckTour_2(petrolpumps) << "\n";

  petrolpumps = {{5, 7}, {3, 2}, {6, 6}, {8, 7}};
  std::cout << "route start:\n"
            << "--approach #1: " << truckTour_1(petrolpumps) << "\n"
            << "--approach #2: " << truckTour_2(petrolpumps) << "\n";

  petrolpumps = {{2, 9}, {3, 5}, {7, 4}, {1, 4}, {11, 2}};
  std::cout << "route start:\n"
            << "--approach #1: " << truckTour_1(petrolpumps) << "\n"
            << "--approach #2: " << truckTour_2(petrolpumps) << "\n";

  return 0;
}