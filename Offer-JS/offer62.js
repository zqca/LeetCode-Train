/**
 * @param {number} n
 * @param {number} m
 * @return {number}
 * f[n,m] = (f[n-1,m]+m)%n
 */
var lastRemaining = function (n, m) {
    let f = 0;//一个数，n=1
    for (let i = 2; i <= n; ++i) {
        f = (f + m) % i;
    }
    return f;

};