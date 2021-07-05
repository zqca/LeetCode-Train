let memo = Array(101);//n=0-100
memo.fill(-1);
memo[0] = 1;
memo[1] = 1;
var numWays = function(n) {
    if(memo[n] !== -1){
        return memo[n];
    }
    memo[n] = ((numWays(n - 1) % (1e9 + 7)) + (numWays(n - 2) % (1e9 + 7))) % (1e9 + 7);
    return memo[n];
};