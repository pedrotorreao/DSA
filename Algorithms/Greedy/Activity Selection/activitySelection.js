/****************************************************************/
/* Activity Selection Problem - Greedy Algorithm ********/
/****************************************************************/
const { quickSort } = require("./activitySelection_util");

function activitySelection(activities) {
  let activityList = quickSort(activities);

  let schedule = [];

  let previousActivity = activityList[0];
  schedule.push(previousActivity);

  for (let i = 1; i < activityList.length; ++i) {
    if (activityList[i][1] >= previousActivity[2]) {
      schedule.push(activityList[i]);
      previousActivity = activityList[i];
    }
  }

  return schedule;
}

function displaySchedule(activities) {
  let schedule = activitySelection(activities);

  schedule.forEach((task) => {
    console.log(`Task: ${task[0]} \tBegin: ${task[1]} \tEnd: ${task[2]}\n`);
  });
}

/* test 1 - expected output: A B D E*/
let activityList = [
  ["E", 8, 9],
  ["C", 0, 6],
  ["A", 1, 2],
  ["D", 5, 7],
  ["F", 5, 9],
  ["B", 3, 4]
];

displaySchedule(activityList);
