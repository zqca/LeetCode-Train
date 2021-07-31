/**
 * @param {number[]} a
 * @return {number[]}
 * 画表格！维护当前元素左侧/右侧的乘积
 */
var constructArr = function (a) {
    let len = a.length;
    if (len < 2) {
        return [];
    }

    let left = Array(len).fill(1);//left[i]表示a[i]左侧的乘积
    let right = Array(len).fill(1);
    //处理左侧
    let tmp = 1;
    for (let i = 1; i < len; ++i) {
        tmp = tmp * a[i - 1];
        left[i] = tmp;
    }
    //处理右侧；
    tmp = 1;
    for (let i = len - 2; i >= 0; --i) {
        tmp = tmp * a[i + 1];
        right[i] = tmp;
    }
    let ans = [];
    for (let i = 0; i < len; ++i) {
        ans.push(left[i] * right[i]);
    }
    return ans;
};