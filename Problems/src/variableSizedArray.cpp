//-------------------------------------------
//---------- Variable Sized Arrays ----------
//-------------------------------------------
/*
Descr.: 
	Consider an n-element array, a, where each index i in the array contains a reference to an array of k integers (where the value of k varies from array to array). 
	Given a, you must answer q queries. Each query is in the format i j, where i denotes an index in array a and j denotes an index in the array located at a[i]. 
	For each query, find and print the value of element j in the array at location a[i] on a new line.
Input:
	The first line contains two space-separated integers denoting the respective values of n (the number of variable-length arrays) and q (the number of queries).
	Each line  of the  subsequent lines contains a space-separated sequence in the format k a[i]0 a[i]1 … a[i]k-1 describing the k-element array located at a[i].
	Each of the  subsequent lines contains two space-separated integers describing the respective values of i (an index in array a) and j (an index in the array 
	referenced by a[i]) for a query.
Output:
	For each pair of i and j values (i.e., for each query), print a single integer that denotes the element located at index j of the array referenced by a[i]. 
	There should be a total of q lines of output.
Example:
	Sample input:
		2 2
		3 1 5 4
		5 1 2 8 9 3
		0 1
		1 3
	Sample output:
		5
		9
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int numOfArrays {};
    cin >> numOfArrays;
    
    int numOfQueries {};
    cin >> numOfQueries;
    
    vector<vector<int>> arr {};
    for(int i{0}; i < numOfArrays; ++i) {arr.push_back(vector<int>());}
    
    int iter {0};
    while(numOfArrays > 0){
        int k {};
        cin >> k;
 
        for(int i{0}; i < k; ++i){
            int ki {};
            cin >> ki;
            arr[iter].push_back(ki);
        }
        ++iter;
        --numOfArrays;
    }
    
    while(numOfQueries > 0){
        int qi {}, qj{};
        cin >> qi;
        cin >> qj;
        
        cout << arr.at(qi).at(qj) << endl;
        
        --numOfQueries;
    }
    
    return 0;
}