/**
 * @param {number} n
 * @return {number[]}
 */
var printNumbers = function(n) {
    let maxNum = Math.pow(10, n) - 1;
    let ans = [];
    for(let i = 0; i < maxNum; ++i){
        ans[i] = i + 1;
    }
    return  ans;

};