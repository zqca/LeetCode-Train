/**
 * @param {number} n
 * @return {number}
 * 数学题,太乱了
 */
var findNthDigit0 = function(n) {
    if(n < 10){
        return n;
    }
    //先构造pos[k + 1] = 1 + k*10^k - 11111...1(k个)
    let pos = Array(12);
    for(let k = 0; k < 12; ++k){
        pos[k + 1] = 1 + k * Math.pow(10, k) - (Math.pow(10, k) - 1) / 9;
    }
    let len;
    for(len = 2; len < 12; ++len){
        if(pos[len] >= n){
            --len;
            break;
        }
    }
    //当前是len位数字
    let startPos = pos[len];
    let startNum = Math.pow(10, len - 1);//对应的数字
    let left = n - startPos;
    let num = Math.floor(left / len) + startNum;
    let numPos = startPos + len * (num - startNum);//当前数字的第一位的pos

    let arr = String(num).split('');
    for(let t = 0; t < len; ++t){
        if(t + numPos === n){
            return parseInt(arr[t]);
        }
    }

};


/**
 * @param {number} n
 * @return {number}
 * 第一步，确定所在的数字区间
 * 第二步，确定是哪一个数字
 * 第三步，确定是数字的第几位
 */
var findNthDigit = function(n) {
    if(n === 0){
        return n;
    }
    //第一步:数字长度为dig，第一个数字start为10^(dig - 1),
    //       数字数量cnt为9*10^(dig - 1)，该区间所有数字的长度digsCount为dig * 9*10^(dig - 1)
    let dig = 1, start = 1, cnt = 9, digsCount = 9;

    while(n - digsCount > 0){
        n = n - digsCount;
        ++dig;
        start = Math.pow(10, dig - 1);
        cnt = 9 * start;
        digsCount = dig * cnt;

    }
    //第一步:确定是哪一个数字
    --n;
    let num = start + Math.floor(n / dig);//确定是数字num
    //第三步:确定是数字的第几位
    let arr = String(num).split('');
    let diff = n - dig * (num - start);//数字的第diff位
    return parseInt(arr[diff]);
};


//debug
let n = 195;
console.log(findNthDigit(n))