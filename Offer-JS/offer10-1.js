/**
 * @param {number} n
 * @return {number}
 */

let memo = Array(105);//n=0-100
memo.fill(-1);
memo[0] = 0;
memo[1] = 1;
var fib = function(n) {
    if(memo[n] !== -1){
        return memo[n];
    }
    memo[n] = ((fib(n - 1) % (1e9 + 7)) + (fib(n - 2) % (1e9 + 7))) % (1e9 + 7);
    return memo[n];
};

console.log(fib(5))