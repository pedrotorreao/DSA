/*****************************************************************************************/
/*Problem: Time Conversion  ********/
/*****************************************************************************************/
function timeConversion(s) {
  let h = parseInt(s.slice(0,2));
  let minsec = s.slice(2,8);

  if (s.includes('P') && h !== 12){
    h = h + 12; 
  } else if (s.includes('A') && h === 12){
    h = 0;
  }

  if (h < 10){
    h = '0' + h;
  }

  h = h.toString();
  let time24 = h.concat(minsec);

  return time24;
}
console.log(timeConversion('07:05:45AM'));
console.log(timeConversion('09:05:45AM'));
console.log(timeConversion('11:05:45PM'));
console.log(timeConversion('12:05:45AM'));
console.log(timeConversion('12:05:45PM'));