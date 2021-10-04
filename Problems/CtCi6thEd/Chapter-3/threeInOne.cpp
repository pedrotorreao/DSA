/*********************************************************************************************/
/* Problem: Three in One (CtCi 3.1) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Describe how you could use a single array to implement three stacks.

--Reasoning:
  Approach #1:
    If we know the size of each stack from the start, we could subdivide an array in three and
    consider each part as one of the stacks. 
      Ex: Let s1, s2 and s3 be the size of each stack such that s1=10, s2=5 and s3=15. The total
          size, st, of the stack would be st=s1+s2+s3=30. This way we'd have the following:
            s1: stack[0] to stack[9]
            s2: stack[10] to stack[14]
            s3: stack[15] to stack[29]
    The downside of this approach is the fixed sizes for the stacks, in case we need to increase
    the size of the stacks, we could end up having to shift elements, which can get expensive.
    Another disadvantage for this approach is that we could end up with a lot of empty allocated
    space, which is not memory efficient.

  Approach #2: 
    We could alternate the order in which each stack has an element pushed onto it. This way we'd
    have stacks[] = [stack1 stack2 stack3 stack1 ...]. Couple this approach with a dynamically 
    sized array and we have a flexible solution. The downside is, again, memory efficiency for the
    cases in which one of the stacks is much bigger than the others. Since there is a order of 
    insertion which must be followed, a lot of empty spaces will be left in the stack array. 
      Ex: Let s1, s2 and s3 be the size of each stack such that s1=2, s2=1 and s3=6. The stack
          distribution would be:
          stacks[] = [stack1 stack2 stack3 stack1 empty stack3 empty empty stack3 ...]

--Time complexity: 
 
--Space complexity: 
*/

#include <iostream>
#include <iomanip>
#include <climits>

// class for implementing 3 stacks of fixed size using one single array:
class ThreeFixedStacksInOne
{
private:
  const int numberOfStacks = 3;
  int stackCapacity;  // individual stack capacity
  int *stackElements; // this'll point to an array containing the stack elments themselves
  int *stackSizes;    // this'll point to an array which will store the number of elements in each stack
public:
  //  constructor:
  ThreeFixedStacksInOne(int oneStackSize)
  {
    this->stackCapacity = oneStackSize;
    stackElements = new int[numberOfStacks * stackCapacity](); // array of size (numberOfStacks * stackCapacity) to store all 3 stacks
    stackSizes = new int[numberOfStacks]();                    // store each stack's current load
  }

  // helper - check if the selected stack is already full:
  bool isStackFull(int whichStack)
  {
    return (stackSizes[whichStack] == this->stackCapacity);
  }

  // helper - check if the selected stack is empty:
  bool isStackEmpty(int whichStack)
  {
    return (stackSizes[whichStack] == 0);
  }

  // helper - return index of the stack top element:
  int indexOfTop(int whichStack)
  {
    int stackStartIndex = whichStack * stackCapacity;
    int currentStackSize = stackSizes[whichStack];

    return (stackStartIndex + currentStackSize - 1);
  }

  // helper - return selected stack's current occupancy:
  int stackOccupancy(int whichStack)
  {
    return (stackSizes[whichStack]);
  }

  // push a new element to the stack:
  void push(int whichStack, int value)
  {
    if (whichStack > (numberOfStacks - 1))
    {
      std::cout << "This stack does not exist. Please, try one of the 3 stacks available\n";
      return;
    }
    if (isStackFull(whichStack))
    {
      std::cout << "Stack " << whichStack << " is already full. Please, try another stack\n";
      return;
    }

    stackSizes[whichStack]++;
    stackElements[indexOfTop(whichStack)] = value;
  }

  // pop the top element from one of the stacks:
  void pop(int whichStack)
  {
    if (whichStack > (numberOfStacks - 1))
    {
      std::cout << "This stack does not exist. Please, try one of the 3 stacks available\n";
      return;
    }
    if (isStackEmpty(whichStack))
    {
      std::cout << "Stack " << whichStack << " is already empty.\n";
      return;
    }

    stackElements[indexOfTop(whichStack)] = -1;
    stackSizes[whichStack]--;
  }

  // peek the top element of the selected stack:
  int peek(int whichStack)
  {
    if (whichStack > (numberOfStacks - 1))
    {
      std::cout << "This stack does not exist. Please, try one of the 3 stacks available -- ";
      return INT_MIN;
    }
    if (isStackEmpty(whichStack))
    {
      std::cout << "This is stack is empty -- ";
      return INT_MIN;
    }

    return stackElements[indexOfTop(whichStack)];
  }

  // destructor:
  ~ThreeFixedStacksInOne()
  {
    delete[] stackElements;
    delete[] stackSizes;
  }
};

// driver code:
int main()
{
  std::cout << std::boolalpha;

  ThreeFixedStacksInOne stacks = ThreeFixedStacksInOne(4);

  stacks.push(0, 3);
  stacks.push(0, 55);
  stacks.push(0, 3);
  stacks.push(0, 11);
  std::cout << "Stack 0 Top Element: " << stacks.peek(0) << "\n";                 // should output 11.
  stacks.push(0, 9);                                                              // should output an error message for full capacity reached.
  std::cout << "Stack 0 is full: " << stacks.isStackFull(0) << "\n";              // should output 'true'
  stacks.pop(0);                                                                  // pops 11 out of the stack 0
  stacks.pop(0);                                                                  // pops 11 out of the stack 3
  std::cout << "Stack 0 Top Element: " << stacks.peek(0) << "\n";                 // should output 55.
  std::cout << "Stack 0 current occupancy: " << stacks.stackOccupancy(0) << "\n"; // should output 2.
  stacks.pop(0);                                                                  // pops 55 out of the stack 0
  stacks.pop(0);                                                                  // pops 3 out of the stack 0
  std::cout << "Stack 0 Top Element: " << stacks.peek(0) << "\n";                 // should output an error message for empty stack.
  stacks.pop(0);                                                                  // should output an error message for empty stack.

  stacks.push(3, 99); // should ouput an error message indicating that this stack does not exist (stacks go from 0 to 2).

  std::cout << "Stack 1 is empty: " << stacks.isStackEmpty(1) << "\n"; // should output 'true'.
  std::cout << "Stack 2 is empty: " << stacks.isStackEmpty(2) << "\n"; // should output 'true'.

  return 0;
}