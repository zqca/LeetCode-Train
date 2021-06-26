/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var findNumberIn2DArray = function(matrix, target) {
    let row = matrix.length;
    if(row === 0) return  false;
    let col = matrix[0].length;
    if(col === 0) return  false;
    //从左下角开始访问，数组的值大于target就去除当前行，小于就去除列
    let i = row - 1;
    let j = 0;
    while(i >= 0 && j <= col - 1){
        if(matrix[i][j] === target){
            return true;
        }
        if(matrix[i][j] > target){
            --i;//去除当前行
        }
        else{
            ++j;//去除列
        }
    }
    return false;
};

let matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]];
let target = 5;
let ans = findNumberIn2DArray(matrix, target);
console.log(ans);