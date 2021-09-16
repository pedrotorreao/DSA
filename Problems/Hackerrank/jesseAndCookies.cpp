/****************************************************************/
/*Problem - Jesse and Cokies (HR)  ********/
/****************************************************************/
/*
-- Summary: 
    Jesse wants the sweetness of all his cookies to be greater than a value K. To achieve this, 
    Jesse repeatedly mixes two cookies with the least sweetness. He creates a special combined cookie with:
        sweetness = (1 * Least sweet cookie) +  (2 * 2nd least sweet cookie).
    He repeats this procedure until all the cookies in his collection have a sweetness >= K.
    You are given Jesse's cookies. Print the number of operations required to give the cookies a 
    sweetness >= K. Print -1 if this isn't possible. 
-- Input(s): 
    The first line consists of integers N, the number of cookies and K, the minimum required sweetness, 
    separated by a space. The next line contains N integers describing the array A where A[i] is the 
    sweetness of the ith cookie in Jesse's collection.
-- Expected output(s): 
    Output the number of operations that are needed to increase the cookie's sweetness >= K.
    Output -1 if this isn't possible.
-- Constraints: 
    1 <= N <= 10e6; 1 <= A[i] <= 10e6; 1 <= K <= 10e9

*/
int cookies(int k, vector<int> A) {
    priority_queue<int, vector<int>, greater<int>> sweetnessHeap;
    
    int opCntr {0};
    int smaller1 {0};
    int smaller2 {0};
    int newCookie {0};
    
    for(auto index : A){
        sweetnessHeap.push(index);
    }
    
    while(sweetnessHeap.top() < k) {
        smaller1 = sweetnessHeap.top();
        sweetnessHeap.pop();
         
        if(sweetnessHeap.empty()) { return -1;}
    
        smaller2 = sweetnessHeap.top();
        sweetnessHeap.pop();
        
        newCookie = smaller1 + (smaller2 * 2);
        sweetnessHeap.push(newCookie);
        
        opCntr++;
    }
    
    return opCntr;
}