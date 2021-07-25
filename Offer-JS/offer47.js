/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxValue = function(grid) {
    let m = grid.length;
    let n = grid[0].length;

    let top, left;
    for(let i = 0; i < m; ++i){
        for(let j = 0; j < n; ++j){
            top = left = 0;
            if(i - 1 >= 0){
                top = grid[i - 1][j];
            }
            if(j - 1 >= 0){
                left = grid[i][j - 1];
            }
            grid[i][j] += Math.max(top, left);
        }
    }
    return grid[m - 1][n - 1];
};