/****************************************************************/
/*Problem: Roman to Integer  ********/
/****************************************************************/
//NAIVE APPROACH: nested if-else statements
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
console.log(romanToInt('III'));       //3
console.log(romanToInt('LVIII'));     //58
console.log(romanToInt('MCMXCIV'));   //1994
console.log(romanToInt('MMMCMXCIX')); //3999