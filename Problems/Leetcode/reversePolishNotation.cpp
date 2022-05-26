/*********************************************************************************************/
/* Problem: Evaluate Reverse Polish Notation (LC) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Evaluate the value of an arithmetic expression in Reverse Polish Notation. Valid operators
  are +, -, *, and /. Each operand may be an integer or another expression.
  Note that division between two integers should truncate toward zero.
  It is guaranteed that the given RPN expression is always valid. That means the expression would
  always evaluate to a result, and there will not be any division by zero operation.

  > Example 1:
    Input: tokens = ["2","1","+","3","*"]
    Output: 9
    Explanation: ((2 + 1) * 3) = 9

  > Example 2:
    Input: tokens = ["4","13","5","/","+"]
    Output: 6
    Explanation: (4 + (13 / 5)) = 6

  > Example 3:
    Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
    Output: 22
    Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
    = ((10 * (6 / (12 * -11))) + 17) + 5
    = ((10 * (6 / -132)) + 17) + 5
    = ((10 * 0) + 17) + 5
    = (0 + 17) + 5
    = 17 + 5
    = 22

--Inputs:
  -std::vector<std::string>: tokens

--Output:
  -int: result

--Constraints:
    1 <= tokens.length <= 104
    tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].

--Reasoning:
  Iterate over the tokens vector and, for each token, either push it to the stack if it's a number
  or perform the acalculation if it's an arithmetical operator. See more comments below.

--Time complexity: O(N), where N is the number of tokens

--Space complexity: O(N), due to the stack created, where N is the number of tokens.

*/

#include <iostream>
#include <stack>
#include <string>
#include <vector>

int evalRPN(std::vector<std::string> &tokens) {
  std::stack<int> st;

  for (const auto &tk : tokens) {
    // current token is an arithmetical operator, perform operation. The members of the
    // calculation are the two last entries to the stack (numbers):
    if (tk.size() == 1 && (tk[0] == '+' || tk[0] == '-' || tk[0] == '*' || tk[0] == '/')) {
      int op_1, op_2, res;

      op_2 = st.top();
      st.pop();

      op_1 = st.top();
      st.pop();

      if (tk[0] == '+')
        res = op_1 + op_2;
      else if (tk[0] == '-')
        res = op_1 - op_2;
      else if (tk[0] == '*')
        res = op_1 * op_2;
      else
        res = op_1 / op_2;

      // push the result to the stack to be used in future calculations:
      st.push(res);
    }
    // current token represents a number, push it to the stack to be processed later when
    // an arithmetical operator in met:
    else {
      st.push(std::stoi(tk));
    }
  }

  return st.top();
}

int main() {
  std::vector<std::string> tokens{"2", "1", "+", "3", "*"};
  int res = evalRPN(tokens);
  std::cout << "--RPN result: " << res << "  --Expected: 9\n";

  tokens = {"4", "13", "5", "/", "+"};
  res = evalRPN(tokens);
  std::cout << "--RPN result: " << res << "  --Expected: 6\n";

  tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
  res = evalRPN(tokens);
  std::cout << "--RPN result: " << res << "  --Expected: 22\n";

  return 0;
}