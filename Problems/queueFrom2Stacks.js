/****************************************************************/
/*Problem: Queue using Two Stacks (HR) ********/
/****************************************************************/
/*
-- Summary:
In this challenge, you must first implement a queue using two stacks. Then process q queries, where each query is one of the following 3 types:
1 x: Enqueue element  into the end of the queue.
2: Dequeue the element at the front of the queue.
3: Print the element at the front of the queue.
-- Input(s):
The first line contains a single integer, q, denoting the number of queries. Each line i of the q subsequent lines contains a single query in the form described in the problem statement above. All three queries start with an integer denoting the query type, but only query 1 is followed by an additional space-separated value, x, denoting the value to be enqueued.
-- Expected output(s):
For each query of type 3, print the value of the element at the front of the queue on a new line.
-- Constraints:
*/
function queueFrom2Stacks(input) {
//Solution 4: Adapted Solution 3 to my previous solution in order to simplify it and reduce its time complexity.
  let stack1 = [], stack2 = [];
  let str = input.split('\n'); str.shift();

  str.forEach((query, index) => {
    switch(true) {//trick to use switches to analyze expressions
      case query[0] == 1: //checks if our query type is 1 (enqueue).
        stack1.push(query.split(' ')[1]); break; //if so, it splits the pair '1 x', and pushes x.
      default:
        //if stack2 is empty, load elements from stack1 in reverse order to keep first queue element on top of the stack2. if not, stack2 already has te fist element of the queue as the last element on the stack.
        if (!stack2.length) { 
          while (stack1.length) {stack2.push(stack1.pop());}
        }
        query[0] == 2 ? stack2.pop() : console.log(stack2[stack2.length-1]); break;
    }
  });

//Solution 3: Not mine, found while trying to reduce the time complexity of mine. Very smart.
/*
  const stack1 = [];
  const stack2 = [];

  input.split('\n').forEach((v, i) => {
      if (i) {
          if (v[0] == 1) {
              stack2.push(v.split(' ')[1]);
          } else {
              if (!stack1.length){
                  while (stack2.length) {stack1.push(stack2.pop());}
              } 
              v[0] == 2 ? stack1.pop() : console.log(stack1[stack1.length - 1]);
          }
      }
  });
*/

//Solution 2: Tried a workaround the loops on solution 1, but it was still not enough.
/*
  let stack1 = [], stack2 = [];
  let str = input.split('\n'); str.shift();
  let previous = 0;

  for(let i = 0; i < str.length; i++) {
    let [query, value] = str[i].split(' ').map(x => parseInt(x));

    switch(query) {
      case 1:
          let length2 = stack2.length;
          if(previous !== 1) {
            for (let i = 0; i < length2; i++) { stack1.push(stack2.pop()); }
          } previous = 1; stack1.push(value); break;
      case 2: 
          let length1 = stack1.length;
          if (previous !== 2) {
            for(let i = 0; i < length1; i++){ stack2.push(stack1.pop()) } 
          } previous = 2; stack2.pop(); break;
      case 3: 
          let length3 = stack1.length;
          for(let i = 0; i < length3; i++){ stack2.push(stack1.pop()) } previous = 3;
          console.log(stack2[stack2.length-1]); break;
    }
  }
*/

//Solution 1: Passed most tests, but it took too long in a few and it failed due to timeout.
/*
  // for(let i = 0; i < str.length; i++) {
  //   let [query, value] = str[i].split(' ').map(x => parseInt(x));

  //   switch(query) {
  //     case 1:
  //         let length2 = stack2.length;
  //         for (let i = 0; i < length2; i++) { stack1.push(stack2.pop()); }
  //         stack1.push(value);console.log('stack1: ',stack1); console.log('stack2: ',stack2);console.log('---'); 
  //         break;
  //     case 2: 
  //         let length1 = stack1.length;
  //         for(let i = 0; i < length1; i++){ stack2.push(stack1.pop()) } 
  //         stack2.pop(); console.log('stack1: ',stack1); console.log('stack2: ',stack2);console.log('---'); 
  //         break;
  //     case 3: 
  //         let length3 = stack1.length;
  //         for(let i = 0; i < length3; i++){ stack2.push(stack1.pop()) } 
  //         // console.log('stack1: ',stack1);
  //         console.log('First: ', stack2[stack2.length-1]);
  //         console.log('stack1: ',stack1); console.log('stack2: ',stack2);console.log('---'); 
  //         break;
  //   }
  // }
*/
}