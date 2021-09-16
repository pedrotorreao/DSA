/****************************************************************/
/*Problem: Day of the Programmer  ********/
/****************************************************************/
/*
-- Summary:
  Given a year, y, find the date of the 256th day of that year according to the official Russian calendar during that year. Then print it in the format dd.mm.yyyy, where dd is the two-digit day, mm is the two-digit month, and yyyy is y. For example, y = 1984. y is divisible by 4, so it is a leap year. The 256th day of a leap year after 1918 is September 12, so the answer is 12.09.1984. Complete the dayOfProgrammer function in the editor below. It should return a string representing the date of the  day of the year given.
-- Input(s): A single integer denoting year .
-- Expected output(s): A string representing the date of the  day of the year given.
-- Constraints: 1700 <= y <= 2700.
*/
function dayOfProgrammer(year) {
  let febDays = 0; 
  let sepDay = 0;
  if ((year >= 1700 && year < 1919) && (year % 4 === 0)) 
  {
    febDays = 29;
  } else if ((year >= 1919 && year <= 2700) && ((year % 400 === 0) || ((year % 4 === 0) && (year % 100 !== 0)))) 
  {
    febDays = 29;
  } else if (year === 1918) {
    febDays = 15;
  } else {
    febDays = 28;
  }
  sepDay = 256 - (febDays + 215);
  sepDay = sepDay.toString();

  let progDay = sepDay.concat(`.09.${year}`);

  return progDay;
}
console.log(dayOfProgrammer(1984));
console.log(dayOfProgrammer(2017));
console.log(dayOfProgrammer(2016));
console.log(dayOfProgrammer(1800));
console.log(dayOfProgrammer(1918)); 
//Catch. 1918 was the of the transition from calendars. In this year, February only had 15 days.
console.log(dayOfProgrammer(1700));
console.log(dayOfProgrammer(1919));
console.log(dayOfProgrammer(1920));
console.log(dayOfProgrammer(2020));