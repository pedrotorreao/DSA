/****************************************************************/
/*Problem: Run Length Encoding ********/
/****************************************************************/
/*
-- Problem statement:
Given a string str, perform a run length encoding (RLE) on it. 
Ex.:  str = "aaaabbbbbcc"
      strRLE = "4a4b2c"
-- Input: string to encode.
-- Output: RLE encoded string.
*/

function encodeStr(str) {
  let countChar = 0;
  let strEncoded = "";

  for (let i = 1; i < str.length; i++) {
    countChar++;
    if (str[i] !== str[i - 1]) {
      let partial = countChar.toString() + str[i - 1];
      //strEncoded = strEncoded.concat(partial);
      strEncoded += partial;
      countChar = 0;
    }
    if (i + 1 === str.length) {
      countChar++;
      let partial = countChar.toString() + str[i];
      //strEncoded = strEncoded.concat(partial);
      strEncoded += partial;
      countChar = 0;
    }
  }

  console.log(strEncoded);
}

encodeStr("aaaabbbbcccccffff");
encodeStr("abcdaaabdcg");
