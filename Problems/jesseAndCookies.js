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
            [this.heap[index], this.heap[parentIndex]] = [this.heap[parentIndex], this.heap[index]];
            //this.swapValues(index, parentIndex);
            index = parentIndex;
            this.heapifyBottomTop(index);
        } 
        else { return; }
    }
    remove() {
        if(this.heap.length <= 1) { return; }

        [this.heap[this.heap.length-1], this.heap[1]] = [this.heap[1], this.heap[this.heap.length-1]];
        let min = this.heap.pop();
        this.heapifyTopBottom();
        
        return min;
    }
    heapifyTopBottom(rootIndex=1) {
        if(!this.heap[rootIndex]) { return; }

        let leftIndex, rightIndex;
        leftIndex = 2*rootIndex;
        rightIndex = (2*rootIndex)+1;

        if(!this.heap[leftIndex]) { return; }

        if(this.heap[rootIndex] > this.heap[leftIndex] || this.heap[rootIndex] > this.heap[rightIndex]) {
            //if there's no right child or left child's value is less than right child's, swap subtrees' root and left child's values  and go down the heap:
            if(!this.heap[rightIndex] || this.heap[leftIndex] < this.heap[rightIndex]) {
                [this.heap[leftIndex], this.heap[rootIndex]] = [this.heap[rootIndex], this.heap[leftIndex]];
                //this.swapValues(rootIndex, leftIndex);
                rootIndex = leftIndex;
            }
            else {
                [this.heap[rightIndex], this.heap[rootIndex]] = [this.heap[rootIndex], this.heap[rightIndex]];
                //this.swapValues(rootIndex, rightIndex);
                rootIndex = rightIndex;
            }
        this.heapifyTopBottom(rootIndex);
        }
    }
    swapValues(child, parent) {
        let temp = this.heap[child];
        this.heap[child] = this.heap[parent];
        this.heap[parent] = temp;
    }
    mixSweeteness() {
        //get the 1st and 2nd heap values with smaller K values:
        //  smaller1 = heap.remove()    smaller2 = heap.remove()
        let smaller1 = this.remove();
        let smaller2 = this.remove();
        //mix sweeteness:
        //  newCookie = smaller1 + (2*smaller2)
        let newCookie = smaller1 + (2*smaller2);
        //add newCookie to the heap and increment counter
        this.insert(newCookie);
    }
    getSize() {
        return this.heap.length-1;
    }
}
function cookies(k, A) {
    let sweetnessHeap = new minHeap();
    let opCntr = 0;

    for(let i = 0; i < A.length; ++i) {
        if(A[i] < k) { 
            sweetnessHeap.insert(A[i]);
        }
    } 
    while(sweetnessHeap.peek() < k && sweetnessHeap.getSize() > 1) {
        sweetnessHeap.mixSweeteness();
        opCntr++;
    }
    if(sweetnessHeap.peek() < k) { return -1; }
    return opCntr;
    //console.log(sweetnessHeap);
};

//console.log(cookies(7,[10,2,9,12,3,1,7,16,0]));
console.log(cookies(7,[1,2,3,9,10,12]));
console.log(cookies(75,[0,1,1,1,1]));
console.log(cookies(9,[1,62,14]));
