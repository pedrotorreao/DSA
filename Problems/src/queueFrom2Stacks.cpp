/****************************************************************/
/*Problem: Queue using Two Stacks (HR) ********/
/****************************************************************/

#include <vector>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class MyQueue
{
public:
  std::stack<int> stack_newest_on_top, stack_oldest_on_top;

  void push(int x)
  {
    stack_newest_on_top.push(x);
  }

  void pop()
  {
    if (stack_oldest_on_top.empty())
    {
      while (stack_newest_on_top.size() != 0)
      {
        stack_oldest_on_top.push(stack_newest_on_top.top());
        stack_newest_on_top.pop();
      }
    }
    stack_oldest_on_top.pop();
  }

  int front()
  {
    if (stack_oldest_on_top.empty())
    {
      while (stack_newest_on_top.size() != 0)
      {
        stack_oldest_on_top.push(stack_newest_on_top.top());
        stack_newest_on_top.pop();
      }
    }

    return stack_oldest_on_top.top();
  }
};

int main()
{
  MyQueue q1;

  int type, x;

  std::vector<std::vector<int>> queries{{1, 42}, {2, -1}, {1, 14}, {3, -1}, {1, 28}, {3, -1}, {1, 60}, {1, 78}, {2, -1}, {2, -1}};

  for (int i = 0; i < queries.size(); i++)
  {
    type = queries.at(i).at(0);
    if (type == 1)
    {
      x = queries.at(i).at(1);
      q1.push(x);
    }
    else if (type == 2)
    {
      q1.pop();
    }
    else
      std::cout << q1.front() << std::endl;
  }

  return 0;
}
