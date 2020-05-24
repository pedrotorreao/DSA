/****************************************************************/
/*Problem: Roman to Integer  ********/
/****************************************************************/
//NAIVE APPROACH: nested if-else statements
//  Runtime: 232 ms
//  Memory: 42.4 MB
var romanToInt = function(s) {
  let conv = 0;

  for (let i = 0; i < s.length; i++) {
    if (s[i] === 'I') 
    {
      if (s[i+1] === 'V') {
        conv += 4;
        i++;
      } else if (s[i+1] === 'X') {
        conv += 9;
        i++;
      } else {
        conv += 1;
      }
    }
    else if (s[i] === 'V') 
    {
      conv += 5;
    }
    else if (s[i] === 'X') 
    {
      if (s[i+1] === 'L') {
        conv += 40;
        i++;
      } else if (s[i+1] === 'C') {
        conv += 90;
        i++;
      } else {
        conv += 10;
      }
    }
    else if (s[i] === 'L') 
    {
      conv += 50;
    }
    else if (s[i] === 'C') 
    {
      if (s[i+1] === 'D') {
        conv += 400;
        i++;
      } else if (s[i+1] === 'M') {
        conv += 900;
        i++;
      } else {
        conv += 100;
      }
    }
    else if (s[i] === 'D') 
    {
      conv += 500;
    }
    else if (s[i] === 'M') 
    {
      conv += 1000;
    }
  }
  return conv;
};
// console.log(romanToInt('III'));       //3
// console.log(romanToInt('LVIII'));     //58
// console.log(romanToInt('MCMXCIV'));   //1994
// console.log(romanToInt('MMMCMXCIX')); //3999

//BETTER APPROACH: switch statements
//  Runtime: 144 ms
//  Memory: 42 MB   (still too much)
var romanToInt2 = function(s) {
  let conv = 0;

  for (let i = 0; i < s.length; i++) {
    switch (s[i]) 
    {
      case 'I':
        if (s[i+1] === 'V') {
          conv += 4;
          i++;
        } else if (s[i+1] === 'X') {
          conv += 9;
          i++;
        } else {
          conv += 1;
        } break;
      case 'V':
        conv += 5; break;
      case 'X':
        if (s[i+1] === 'L') {
          conv += 40;
          i++;
        } else if (s[i+1] === 'C') {
          conv += 90;
          i++;
        } else {
          conv += 10;
        } break;
      case 'L':
        conv += 50; break;
      case 'C':
        if (s[i+1] === 'D') {
          conv += 400;
          i++;
        } else if (s[i+1] === 'M') {
          conv += 900;
          i++;
        } else {
          conv += 100;
        } break;
      case 'D':
        conv += 500; break;
      case 'M':
        conv += 1000; break;
      default:
        return 'Not a valid roman number!';
    }
  }
    return conv;
};
console.log(romanToInt2('III'));       //3
console.log(romanToInt2('LVIII'));     //58
console.log(romanToInt2('MCMXCIV'));   //1994
console.log(romanToInt2('MMMCMXCIX')); //3999