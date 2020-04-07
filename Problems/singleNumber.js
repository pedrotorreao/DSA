/************************************************************/
/*Problem: Single Number  ********/
/************************************************************/
var singleNumber = function(nums) {
  let mapSingle = {};
  let single;
  for (let i = 0; i < nums.length; i++) {
    if(!mapSingle[nums[i]]) {
      const newItem = nums[i];
      mapSingle[newItem] = 'new';
    } else {
      const newItem = nums[i];
      mapSingle[newItem] = 'seen';
      //delete mapSingle[newItem];
    }
  }
  for (let i = 0; i < nums.length; i++) {
    if(mapSingle[nums[i]] === 'new') {
      return nums[i];
    } 
  }
  //return parseInt(Object.keys(mapSingle));
  //return mapSingle;
};
console.log(singleNumber([4,1,2,1,2]));
console.log(singleNumber([2,2,1]));
console.log(singleNumber([1,1,2,9,2,5,7,11,0,0,2,7,11,9,5]));
console.log(singleNumber([4,1,2,1,2,4,0]));
console.log(singleNumber([0,4,1,2,4,1,2,-1,0]));
console.log(singleNumber([4,1,2,1,4,5,2]));