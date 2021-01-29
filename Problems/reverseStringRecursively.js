/****************************************************************/
/* Problem: Reverse a given string using recursion  ********/
/****************************************************************/
function reverseString(str, newstr="") {
    if(!str.length)
    {
      return newstr;
    }
    
    newstr += str[str.length - 1];
    str = str.substring(0,str.length-1)
    
    return reverseString(str,newstr);
  }
  //should return: 'yretsam oyoy'
  console.log(reverseString('yoyo mastery'));
  
  //should return: 'gnirts siht esrever'
  console.log(reverseString('reverse this string'));