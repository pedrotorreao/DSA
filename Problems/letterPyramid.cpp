#include <iostream>		//std::cout, std::cin
#include <string>		//std::string
#include <algorithm>	//reverse()

using namespace std;

int main()
{
	string userStr {};
	cout << "Enter your string: ";
	getline(cin,userStr);

	//Filter string to remove spaces:
	string strFilter {};
	for (unsigned int i {}; i < userStr.length(); i++) {
		if(userStr.at(i) != ' ') strFilter += userStr.at(i);
	}

	string spacing (strFilter.length()-1,' '); //Initial number of spaces.
	string pyramidStr {};

	//Create a copy of the filtered string without the last character and reverse it:
	string pyrRev = strFilter.substr(0,strFilter.length()-1);
	reverse(pyrRev.begin(),pyrRev.end());

	for (unsigned int i {}; i < strFilter.length(); i++) {
		//Here we concatenate the filtered string with the reversed one:
		pyramidStr = strFilter.substr(0, i+1) + pyrRev.substr(pyrRev.length()-i,i);
		cout << spacing << pyramidStr << endl;
		spacing.erase(0,1); //Remove the amount of spaces to be added on the next iteration.
	}

	return 0;
}
//g++ -Wall -std=c++14 letterPyramid.cpp -o letterPyramid.exe

/* --------------------------------------------------------------------------------------------
-- Alternative solution:
// Letter Pyramid
// Written by Frank J. Mitropoulos

#include <iostream>
#include <string>


int main()
{
    std::string letters{};

    std::cout << "Enter a string of letters so I can create a Letter Pyramid from it: ";
    getline(std::cin, letters);

    size_t num_letters = letters.length();

    int position {0};

    // for each letter in the string
    for (char c: letters) {

        size_t num_spaces = num_letters - position;
        while (num_spaces > 0) {
            std::cout << " ";
            --num_spaces;
        }

        // Display in order up to the current character
        for (size_t j=0; j < position; j++) {
            std::cout << letters.at(j);
        }

        // Display the current 'center' character
        std::cout << c;

        // Display the remaining characters in reverse order
        for (int j=position-1; j >=0; --j) {
            // You can use this line to get rid of the size_t vs int warning if you want
            auto k = static_cast<size_t>(j);
            std::cout << letters.at(k);
        }

        std::cout << std::endl; // Don't forget the end line
        ++position;
    }

    return 0;
}
*/