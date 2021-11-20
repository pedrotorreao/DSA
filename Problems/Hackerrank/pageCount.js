/****************************************************************/
/*Problem: Page Count (HR)  ********/
/****************************************************************/
/*
-- Summary:
Brie’s Drawing teacher asks her class to open their books to a page number. Brie can either start turning pages from the front of the book or from the back of the book. She always turns pages one at a time. When she opens the book, page 1 is always on the right side. When she flips page 1, she sees pages 2 and 3. Each page except the last page will always be printed on both sides. The last page may only be printed on the front, given the length of the book. If the book is n pages long, and she wants to turn to page p, what is the minimum number of pages she will turn? She can start at the beginning or the end of the book. Given n and p, find and print the minimum number of pages Brie must turn in order to arrive at page p.
-- Input(s):
n: the number of pages in the book
p: the page number to turn to
-- Expected output(s):
Print an integer denoting the minimum number of pages Brie must turn to get to page p.
-- Constraints:
*/
function pageCount(n, p) {
  let minimum = 0;
  if (p > Math.round(n / 2) && p % 2 !== 0) {
    minimum = Math.ceil((n - p) / 2);
  } else if (p >= Math.round(n / 2)) {
    minimum = Math.floor((n - p) / 2);
  } else {
    minimum = Math.floor(p / 2);
  }
  //console.log(Math.round(n/2));
  return minimum;
}
console.log("TC 0: ", pageCount(6, 2));
console.log("TC 1: ", pageCount(5, 4));
console.log("TC 2: ", pageCount(4, 4));
console.log("TC 3: ", pageCount(5, 5));
console.log("TC 4: ", pageCount(5, 1));
console.log("TC 7: ", pageCount(7, 3));
console.log("TC 15: ", pageCount(15603, 6957));
console.log("TC 27: ", pageCount(2059, 117));
console.log("TC 28: ", pageCount(6, 5));
console.log("TC 29: ", pageCount(2, 1));
console.log("TC 30: ", pageCount(6, 3));
console.log("TC 31: ", pageCount(27, 14));
