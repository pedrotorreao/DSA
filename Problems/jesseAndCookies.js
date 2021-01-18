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

/* ---- Min Heap ---- */
class minHeap {
    constructor() {
        this.heap = [];
    }
    peek() {
        return this.heap[1];
    }
    insert(value) {
        if(this.heap.length < 1) {
            this.heap[0] = null;
            this.heap.push(value);
            return;
        }
        this.heap.push(value);
        this.heapifyBottomTop();
    }
    heapifyBottomTop(index = this.heap.length - 1) {
        let parentIndex = Math.floor(index/2);

        if(!this.heap[parentIndex]) { return; }

        if(this.heap[parentIndex] > this.heap[index]) {
            this.swapValues(index, parentIndex);
            index = parentIndex;
            this.heapifyBottomTop(index);
        } 
        else { return; }
    }
    remove() {

    }
    heapifyTopBottom() {

    }
    swapValues(child, parent) {
        let temp = this.heap[child];
        this.heap[child] = this.heap[parent];
        this.heap[parent] = temp;
    }
}
function cookies(k, A) {
    let sweetnessHeap = new minHeap();

    for(let i = 0; i < A.length; ++i) {
        if(A[i] < k) { 
            sweetnessHeap.insert(A[i]);
        }
    }
    console.log(sweetnessHeap);
}

cookies(7,[10,2,9,12,3,1]);
