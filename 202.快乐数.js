/*
 * @lc app=leetcode.cn id=202 lang=javascript
 *
 * [202] 快乐数
 */

// @lc code=start
/**
 * @param {number} n
 * @return {boolean}
 */

function getSum(n){
    //计算数字n的各位之和，如12-》1^2+2^5=5
    let sum = 0;
    let dig;//最后一位的数字
    while(n) {
        dig = n % 10;
        sum += dig * dig;
        n = (n - dig) / 10;//避免使用parseInt()
    }
    return sum;
}



//TODO:先转换为字符串再求各位和
/*
function getSum(n){
    //计算数字n的各位之和，如12-》1^2+2^5=5
    let str = String(n);//转换为字符串
    let len = str.length;
    let sum = 0;
    for(let i = 0; i < len; i++) {
        sum += str[i] * str[i];
    }
    return sum;
}
*/


var isHappy = function(n) {
    let sums = new Set();//使用map似乎也行
    let tmp = n;
    let isHappy = 1;
    do{
        tmp = getSum(tmp);
        if(sums.has(tmp)){
            //若已经存在过
            isHappy = 0;//不是快乐数
            break;
        }
        else {
            sums.add(tmp);
        }
    }while(tmp != 1);

    return isHappy;



};
// @lc code=end

