/**
 * @param {number} m
 * @param {number} n
 * @param {number} k
 * @return {number}
 */

let getSum = function(x){
    let sum = 0;
    while(x){
        sum += x % 10;
        x = parseInt(x / 10);
    }
    return sum;
}

let judge = function (x, y, m, n, k){
    //判断当前位置是否可行
    let sum = 0;
    sum += getSum(x) + getSum(y);
    return sum <= k;
}

var movingCount = function(m, n, k) {
    let visited = [];
    for(let i = 0; i < m; ++i){
        visited[i] = [];
        for(let j = 0; j < n; ++j){
            visited[i][j] = false;
        }
    }

    let count = 0;
    let dfs = function (x, y){
        if(x >= m || y >= n || visited[x][y]){
            return;//当前越界，或者位置访问过了
        }

        if(judge(x, y, m, n, k)){
            //当前点可以到达
            ++count;
            visited[x][y] = true;
            dfs(x, y + 1);
            dfs(x + 1, y);
        }
    }

    dfs(0,0);
    return count;

};

let ans = movingCount(3,1,0);
console.log(ans);