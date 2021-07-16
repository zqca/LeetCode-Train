/**
 * @param {number[][]} matrix
 * @return {number[]}
 * 不佳，大量冗余，我的上下边界不可取到
 */

var spiralOrder0 = function(matrix) {
    let ans = [];
    let m = matrix.length;
    if(m === 0) return ans;
    let n = matrix[0].length;
    if(n === 0) return ans;
    let top = -1, right = n, bottom = m, left = -1;
    //不能到达的边界
    let dx = [0, -1, 0, 1];
    let dy = [1, 0, -1, 0];
    //四次转弯的坐标变化
    let i = 0, j = 0;//当前位置
    let turn = 0;//当前需要的转弯编号mod 4
    let count = 0;

    while(j > left && j < right && i > top && i < bottom){
        while(j < right){
            ans.push(matrix[i][j]);
            ++count;
            ++j;
        }
        if(count === m * n){
            break;
        }
        --j;
        i += dy[turn % 4];
        j += dx[turn % 4];
        ++turn;
        ++top;

        while(i < bottom){
            ans.push(matrix[i][j]);
            ++count;
            ++i;
        }
        if(count === m * n){
            break;
        }
        --i;
        i += dy[turn % 4];
        j += dx[turn % 4];
        ++turn;
        --right;

        while(j > left){
            ans.push(matrix[i][j]);
            ++count;
            --j;
        }
        if(count === m * n){
            break;
        }
        ++j;
        i += dy[turn % 4];
        j += dx[turn % 4];
        ++turn;
        --bottom;

        while(i > top){
            ans.push(matrix[i][j]);
            ++count;
            --i;
        }
        if(count === m * n){
            break;
        }
        ++i;
        i += dy[turn % 4];
        j += dx[turn % 4];
        ++turn;
        ++left;
    }
    return ans;

};


/**
 * @param {number[][]} matrix
 * @return {number[]}
 * 精简代码，沿着边界走
 */
var spiralOrder = function(matrix) {
    let ans = [];
    let m = matrix.length;
    if(m === 0) return ans;
    let n = matrix[0].length;
    if(n === 0) return ans;
    let top = 0, right = n - 1, bottom = m - 1, left = 0;
    //当前走的边界
    while(true){
        //向右走
        for(let j = left; j <= right; ++j){
            ans.push(matrix[top][j]);
        }
        if(++top > bottom) break;//可以取等号；如果缩减上边界后矩阵无了，break

        //向下走
        for(let i = top; i <= bottom; ++i){
            ans.push(matrix[i][right]);
        }
        if(--right < left) break;//缩减右边界

        //向左走
        for(let j = right; j >= left; --j){
            ans.push(matrix[bottom][j]);
        }
        if(--bottom < top) break;//缩减下边界

        //向上走
        for(let i = bottom; i >= top; --i){
            ans.push(matrix[i][left]);
        }
        if(++left > right) break;//缩减左边界
    }
    return ans;
};


//debug
matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
console.log(spiralOrder(matrix))