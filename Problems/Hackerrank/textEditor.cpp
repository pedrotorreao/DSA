/*********************************************************************************************/
/* Problem: Text Editor (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Implement a simple text editor. The editor initially contains an empty string, 'S'. Perform
  'Q' operations of the following 4 types:
  1. append(W) - Append string 'W' to the end of 'S'.
  2. delete(k) - Delete the last 'k' characters of 'S'.
  3. print(k) - Print the kth character of 'S'.
  4. undo() - Undo the last (not previously undone) operation of type 1 or 2, reverting 'S' to
  the state it was in prior to that operation.

  > Example:
    S = 'abcde'
    ops = ['1 fg', '3 6', '2 5', '4', '3 7', '4', '3 4']

    operation
    index   S       ops[index]  explanation
    -----   ------  ----------  -----------
    0       abcde   1 fg        append fg
    1       abcdefg 3 6         print the 6th letter - f
    2       abcdefg 2 5         delete the last 5 letters
    3       ab      4           undo the last operation, index 2
    4       abcdefg 3 7         print the 7th characgter - g
    5       abcdefg 4           undo the last operation, index 0
    6       abcde   3 4         print the 4th character - d

    The results should be printed as:
      f
      g
      d

--Input:
  The first line contains an integer, 'Q', denoting the number of operations. Each line 'i' of the
  subsequent lines (where 0<=i<Q) defines an operation to be performed. Each operation starts with
  a single integer, 't' (where 't' E {1,2,3,4}), denoting a type of operation as defined in the
  Problem Statement above. If the operation requires an argument, 't' is followed by its space-separated
  argument. For example, if t=1 and W='abcd', line 'i' will be '1 abcd'.

--Output:
  Each operation of type 3 must print the kth character on a new line.

--Constraints:
  1<=Q<=10^6
  1<=k<=|S|
  The sum of the lengths of all 'W' in the input <= 10^6.
  The sum of 'k' over all delete operations <= (2x10^6).
  All input characters are lowercase English letters.
  It is guaranteed that the sequence of operations given as input is possible to perform.

--Reasoning: See comments below.

--Time complexity:
  1. append(W) - O(1)
  2. delete(k) - O(n), where 'n' is the size of the string.
  3. print(k) - O(1)
  4. undo() - O(1)

--Space complexity:
  O(S*N), where 'S' is the number of string states kept on the stack and 'N' is the size of the largest string.

*/

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

class TextEditor {
private:
  // current up to date string:
  std::string str;
  // stack to maintain previous string states:
  std::stack<std::string> states;

public:
  void append(std::string s) {
    // add current string to the stack before updating it:
    states.push(str);

    str = str.empty() ? s : (str + s);
  }

  void deleteK(int k) {
    // add current string to the stack before updating it:
    states.push(str);

    if (k - 1 >= str.size())
      str = "";
    else {
      int start = str.size() - k;
      str.erase(str.begin() + start, str.end());
    }
  }

  void printKth(int k) {
    // print an empty string if the string is currently empty:
    if (str.empty()) {
      std::cout << ""
                << "\n";
      return;
    }
    // print last character if k is larger than the string size:
    if (k >= str.size()) {
      std::cout << str.at(str.size() - 1) << "\n";
      return;
    }
    // print the kth character:
    std::cout << str.at(k - 1) << "\n";
  }

  void undo(void) {
    if (states.empty()) {
      str = "";
      return;
    }
    // return the string to the previous state:
    str = states.top();
    // since the stack top is now the current state, pop it from the stack:
    states.pop();
  }

  TextEditor() { str = ""; }
  ~TextEditor() = default;
};

int main() {
  int queries{}, currOp{};

  // get the number of queries to process:
  std::cin >> queries;

  // declare a new object 'te' of type TextEditor:
  TextEditor te;

  for (int i{0}; i < queries; i++) {
    // get the current type of operation to be performed:
    std::cin >> currOp;

    switch (currOp) {
    // append(W):
    case 1: {
      std::string currStr{};
      std::cin >> currStr;

      te.append(currStr);
      break;
    }
    // delete(k):
    case 2: {
      int currK{};
      std::cin >> currK;

      te.deleteK(currK);
      break;
    }
    // print(k):
    case 3: {
      int currK{};
      std::cin >> currK;

      te.printKth(currK);
      break;
    }
    // undo():
    case 4: {
      te.undo();
      break;
    }
    }
  }

  return 0;
}
