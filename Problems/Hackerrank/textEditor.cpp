/*********************************************************************************************/
/* Problem: Text Editor (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:


  > Example:

--Input:


--Output:


--Reasoning:


--Constraints:


--Time complexity:

--Space complexity:

*/

#include <iostream>
#include <stack>
#include <string>

class TextEditor {
private:
  std::string str;
  std::stack<std::string> states;

public:
  void append(std::string s) {
    states.push(str);

    str = str.empty() ? s : (str + s);
  }
  void deleteK(int k) {
    states.push(str);

    if (k - 1 >= str.size())
      str = "";
    else {
      int start = str.size() - k;
      str.erase(str.begin() + start, str.end());
    }
  }
  void printKth(int k) {
    if (str.empty()) {
      std::cout << ""
                << "\n";
      return;
    }
    if (k >= str.size()) {
      std::cout << str.at(str.size() - 1) << "\n";
      return;
    }

    std::cout << str.at(k - 1) << "\n";
  }
  bool undo(void) {
    /* TO DO */
  }

  TextEditor() { str = ""; }
  ~TextEditor() = default;
};

int main() {
  // .. driver code
  // .. test cases
  return 0;
}