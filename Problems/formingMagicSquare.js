function formingMagicSquare(s) {
  //all possible magic squares with each square stored in linear format:
  let magicSquares = [
    [8, 1, 6, 3, 5, 7, 4, 9, 2],
    [6, 1, 8, 7, 5, 3, 2, 9, 4],
    [4, 9, 2, 3, 5, 7, 8, 1, 6],
    [2, 9, 4, 7, 5, 3, 6, 1, 8], 
    [8, 3, 4, 1, 5, 9, 6, 7, 2],
    [4, 3, 8, 9, 5, 1, 2, 7, 6], 
    [6, 7, 2, 1, 5, 9, 8, 3, 4], 
    [2, 7, 6, 9, 5, 1, 4, 3, 8],
    ];
  //store original matrix in linear format to make calculations easier:
  let linearS = [];
  for (let i = 0; i < s.length; i++) {
    for (let j = 0; j < s.length; j++) {
      linearS.push(s[i][j]);
    }
  }
  const totals = [];
  
  //diff between our input and the current magic square
  for (let i = 0; i < magicSquares.length; i++) {
    let result = 0;
    for (let j = 0; j < linearS.length; j++) {
      if (linearS[j] !== magicSquares[i][j]){ 
        result += Math.abs(linearS[j] - magicSquares[i][j]);
      }
    }
    totals.push(result);
  }
  console.log(Math.min(...totals));
}
//TEST CASES:
formingMagicSquare([[5,3,4],[1,5,8],[6,4,2]]); //minimal cost: 7
formingMagicSquare([[4,9,2],[3,5,7],[8,1,5]]); //minimal cost: 1
formingMagicSquare([[4,8,2],[4,5,7],[6,1,6]]); //minimal cost: 4
formingMagicSquare([[4,5,8],[2,4,1],[1,9,7]]); //minimal cost: 14