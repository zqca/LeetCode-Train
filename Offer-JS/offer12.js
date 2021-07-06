var exist = function(board, word) {
    let m = board.length;
    let n = board[0].length;

    let dfs = (x, y, cur)=>{
        if(x < 0 || x >= m || y < 0 || y >= n || board[x][y] !== word[cur]){
            return false;//当前位置越界或者不符合题意
        }
        if(cur === word.length - 1){
            return true;//找到了答案
        }

        board[x][y] = '#';
        //当前位置的四个可能的方向
        let res = dfs(x - 1, y,cur + 1) || dfs(x, y + 1,cur + 1) || dfs(x + 1, y,cur + 1) || dfs(x, y - 1,cur + 1)

        board[x][y] = word[cur];//回溯
        return res;
    }

    for(let i = 0; i < m; ++i){
        for(let j = 0; j < n; ++j){
            if(dfs(i, j,0)){
                return true;
            }
        }
    }
    return false;
};


let board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED";
console.log(exist(board, word));
