/**
 * @param {number} n
 * @return {number[]}
 * dp
 */
var dicesProbability = function (n) {
    let maxVal = 6 * n;
    let pre = Array(1 + maxVal).fill(0);
    let cur = Array(1 + maxVal).fill(0);
    pre[0] = 1;//初始化
    for (let num = 1; num <= n; ++num) {
        //总共num个骰子
        for (let i = num; i <= maxVal; ++i) {
            //num个骰子得到点数的和为i
            for (let j = 1; j <= 6; ++j) {
                //当前最后一个的点数
                if (i - j < 0) break;
                cur[i] += pre[i - j];
            }
        }
        pre = Array.from(cur);
        cur.fill(0);
    }
    //最后一个pre保存结果
    let tmp = pre.slice(n);//前面几个的概率为0，去掉
    let total = tmp.reduce((pre, cur) => {
        return pre + cur;
    })
    for (let i = 0; i < tmp.length; ++i) {
        tmp[i] = tmp[i] / total;
    }
    return tmp;

};

//debug

let n = 2;
console.log(dicesProbability(n))