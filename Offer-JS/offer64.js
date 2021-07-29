/**
 * @param {number} n
 * @return {number}
 * pow里面有乘法，不行
 */
var sumNums = function(n) {
    // let tmp1 = Math.pow(n, 2);
    // let tmp2 = n;
    return (Math.pow(n, 2) + n) >> 1;
};

/**
 * @param {number} n
 * @return {number}
 * 使用逻辑短路递归
 */
var sumNums = function(n) {
    return n && sumNums(n - 1) + n;
};