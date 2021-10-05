/*********************************************************************************************/
/* Problem: Stack Min (CtCi 3.2) ********/
/*********************************************************************************************/
/*
--Problem statement:
  How would you design a stack which, in addition to push and pop, has a function min which
  returns the minimum elements? Push, pop and min should all operate in O(1) time.

--Reasoning:
  Use two stacks, one to store all the elements and one to keep track of the min values.

--Time complexity: 
  O(1), operations do not depend on the size of the stack.
 
--Space complexity: 
  O(n), in the worst case scenario where the input is made of elements sorted in descending order,
  we'd have to store all elements in the second stack.
*/

#include <iostream>
#include <vector>
#include <climits>

#include "stack/stack.h"

class StackMin
{
private:
  Stack<int> st_values, st_min;

public:
  void push(int value)
  {
    st_values.push(value);

    if (min() >= value)
    {
      st_min.push(value);
    }
  }

  void pop(void)
  {
    if (min() == st_values.peek())
    {
      st_min.pop();
    }
    st_values.pop();
  }

  int peek(void)
  {
    return st_values.peek();
  }

  int min(void)
  {
    if (st_min.isEmpty())
    {
      return INT_MAX;
    }
    return st_min.peek();
  }

  StackMin() {}
  ~StackMin() = default;
};

// driver code:
int main()
{
  StackMin st;

  std::vector<int> values{11, 5, 3, 9, 23, -2, 47, 1};

  for (auto v : values)
  {
    st.push(v);
  }

  std::cout << "Min element in the stack: " << st.min() << "\n";
  std::cout << "Top element in the stack: " << st.peek() << "\n";

  st.pop();

  std::cout << "Min element in the stack: " << st.min() << "\n";
  std::cout << "Top element in the stack: " << st.peek() << "\n";

  st.pop();
  st.pop();

  std::cout << "Min element in the stack: " << st.min() << "\n";
  std::cout << "Top element in the stack: " << st.peek() << "\n";

  return 0;
}