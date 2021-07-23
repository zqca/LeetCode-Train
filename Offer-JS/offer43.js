/**
 * 将n进行划分，n='high'+'cur'+'low',逐位计算
 * @param {number} n
 * @return {number}
 */
var countDigitOne = function(n) {
    //2345
    let high, cur, low, digit;
    let count = 0;
    high = Math.floor(n / 10);
    cur = n % 10;
    low = 0;
    digit = 1;
    while(high !== 0 || cur !== 0){
        //high,cur不能都为0
        if(cur === 0){
            count += high * digit;
        }
        else if(cur === 1){
            count += high * digit + low + 1;
        }
        else{
            count += (high + 1) * digit;
        }

        low = cur * digit + low;
        cur = high % 10;
        high = Math.floor(high / 10);
        digit *= 10;
    }
    return count;
};

//debug
console.log(countDigitOne(12))

