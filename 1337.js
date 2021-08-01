/**
 * @param {number[][]} mat
 * @param {number} k
 * @return {number[]}
 */
var kWeakestRows = function (mat, k) {
    let getSum = (mat, row) => {
        let ans = 0;
        for (let x of mat[row]) {
            ans += x;
        }
        return ans;
    }
    let len = mat.length;
    let count = Array(len);
    let arr = [];
    for (let i = 0; i < len; i++) {
        count[i] = getSum(mat, i);
        arr.push([i, count[i]]);
    }
    arr.sort((a, b) => {
        if (a[1] > b[1] || (a[1] === b[1] && a[0] > b[0])) {
            return 1;
        } else {
            return -1;
        }
    });
    let ans = [];
    for (let i = 0; i < k; ++i) {
        ans.push(arr[i][0]);
    }
    return ans;
};