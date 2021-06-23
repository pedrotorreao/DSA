/****************************************************************/
/*Problem: Largest Rectangle (HR) ********/
/****************************************************************/

#include <iostream>
#include <vector>
#include <stack>

long largestRectangle(std::vector<int> h)
{
  // stack to hold indexes of h[] in increasing order of their heights:
  std::stack<int> indexStack;

  long maxArea = 0;     // initialize max area
  int prevIndex;        // top of stack: index of rectangle's left border
  long currentArea = 0; // stores area calculated once a smaller height is found

  int i = 0; // id of current building

  while (i < h.size())
  {
    // if current building is higher than previous one, push its id to the stack
    // and keep going:
    if (indexStack.empty() || h[indexStack.top()] <= h[i])
      indexStack.push(i++);

    // if current building is smaller than the previous one, the rectangle for
    // the previous building is done, so calculate its area w/ previous building
    // as the smallest (or minimum height) building, 'i' as its right border and
    // previous building before it as its left border:
    else
    {
      prevIndex = indexStack.top(); // get previous building index
      indexStack.pop();             // remove it from the stack

      // calculate the area for previous building:
      currentArea = h[prevIndex] * (indexStack.empty() ? i : i - indexStack.top() - 1);

      // update max area in case we've found a new max value:
      if (maxArea < currentArea)
        maxArea = currentArea;
    }
  }

  // if the stack is not empty, pop its elements and calculate their areas to see
  // if it's still possible to improve the rectangle's area:
  while (indexStack.empty() == false)
  {
    prevIndex = indexStack.top();
    indexStack.pop();

    currentArea = h[prevIndex] * (indexStack.empty() ? i : i - indexStack.top() - 1);

    if (maxArea < currentArea)
      maxArea = currentArea;
  }

  return maxArea;
}

int main()
{
  std::vector<int> h1{1, 2, 3, 4, 5};
  std::vector<int> h2{1, 3, 6, 8, 7, 2, 4, 1};

  std::cout << "Largest rectangle for h1: " << largestRectangle(h1) << "\n";
  std::cout << "Largest rectangle for h2: " << largestRectangle(h2) << "\n";

  return 0;
}

/*
-- solution 3: brute force approach improved - O(n^2)

long largestRectangle(std::vector<int> h) {
        long maxArea = 0;
        long minHeight = 0;
        int width = 0;          // num. of buildings
        int leftLimit = 0;
        int rightLimit = 0;
        
        for(int i = 0; i < h.size(); i++) {
            minHeight = h[i];
            width = 0;
            leftLimit = i;
            rightLimit = i;
            
            //left side of current:
            while(leftLimit >= 0 && (h[leftLimit] >= minHeight)) {
                width++;
                leftLimit--;
            }
            
            //right side of current:
            while(rightLimit < h.size() && (h[rightLimit] >= minHeight))
            {
                width++;
                rightLimit++;    
            }
            
            width -= 1;
            maxArea = std::max(maxArea, (minHeight * width));
        }
        
        return maxArea;
}

-- solution 2: brute force approach - O(n^2)

long largestRectangle(std::vector<int> h) {
    long maxArea = 0;
    int minHeight = 0;
    long currentArea = 0;
    
    for(size_t i{0}; i < h.size(); i++){
        minHeight = h.at(i);
        for(size_t j{i}; j < h.size(); j++){
            minHeight = std::min(minHeight, h.at(j));
            currentArea = static_cast<long>((j-i+1) * minHeight);
            maxArea = std::max(currentArea, maxArea);
        }
    }
    
    return maxArea;
}

-- solution 1: horrible take on this problem, original order is important so ordering messes things up.

long largestRectangle(vector<int> h) {
    long result {0};
    int k = h.size();
    
    std::priority_queue <int, std::vector<int>, std::greater<int>> minHeap;
    
    for(auto i{0}; i < h.size() - 1; i++){
        minHeap.push(h.at(i));
    }
    
    
    for(auto i{0}; i < h.size() - 1; i++){
        if(k * minHeap.top() > result){
            result = k * minHeap.top();
        }
        k--;
        minHeap.pop();
    }
    
    return result;
}

*/
/*

Problem Explanation - HR Discussions:

Consider the following array representing the buildings heights:
    h = [1, 3, 6, 8, 7, 2, 4, 1]

Let's begin with building 1 (h[0]) and compute all of the areas of each rectangle and choose the maximum from that. 
Notice that when we start with building 1, we have no idea when the end of its rectangle will be, i.e. its right wall
(represented by a dashed arrow going to the right). The next thing you should notice is that if the next building goes up 
(higher than the previous), this building is added to the width but the beginning of the active rectangle is 
still at building 1, so all active areas will remain active (i.e. we still haven't found the end of the area, the 
right wall). This goes on until we reach a building with a height which is less than the previous height we've encountered,
i.e. when the height starts goind down.

When building 5 (h[4] = 7) is added, as it has a height smaller than the previous building (building 4 - height: h[3] = 8), it 
ends the previous building's rectangle or whatever area it was part of (i.e. it is the right limit for the rectangle which 
began at building 4). Also, notice that we need to extend building 5 back through building 4. How do we know to stop at building 4? 
The next active area (coming from building 3) has a height (h[2] = 6) lower than building 5's h[4] = 7, so that area is still active 
(in other words it will go through building 5).

Hopefully you're starting to see how a stack can be used here: when the next building is taller than the previous, 
add it to the stack (to be processsed later). When the next building is shorter: pop off stack until you find a starting 
area with a smaller height (than the current building) or you empty the stack (meaning it goes all the way back through the 
first building). Now push this building's height along with it's left position onto the stack.

When you pop off the stack, this means you've found the right side of an area, so compute its area and see if it's the maximum. 
Also when you find the "left wall" for the current building (meaning you found a smaller building in the stack or went all the way 
back to the first building), you need to remember that position in addition to the height of the current building so that when the 
current building is eventually popped off of the stack, you can properly compute it's area. Notice how building 6 extends both backwards 
and forwards, such that when I get to building 8, I have to know that building 6's height extended all the way back through building 2.

Algorithm steps - O(n) solution:
1) Create an empty stack.
2) Start from first bar, and do following for every bar ‘h[i]’ where ‘i’ varies from 0 to n-1:
    2.a) If stack is empty or h[i] is higher than the bar at top of stack, then push ‘i’ to stack. 
    2.b) If this bar is smaller than the top of stack, then keep removing the top of stack while top of the stack is greater. Let the 
    removed bar be h[tp]. Calculate area of rectangle with h[tp] as smallest bar. For h[tp], the ‘left index’ is previous (previous to tp) 
    item in stack and ‘right index’ is ‘i’ (current index).
3) If the stack is not empty, then one by one remove all bars from stack and do step 2.b for every removed bar.

*/
