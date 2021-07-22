/**
 * @param {string} s
 * @return {string[]}
 */
var permutation = function(s) {
    let len = s.length;
    let visited = new Array(len).fill(false);
    let cur = [];
    let ans = new Set();

    let dfs = function(str, level, visited){
        if(level === str.length){
            ans.add(cur.join(''));
            return ;
        }
        for(let i = 0; i < str.length; ++i){
            if(visited[i]){
                continue;
            }

            cur.push(str[i]);
            visited[i] = true;
            dfs(str, level + 1, visited);

            cur.pop();
            visited[i] = false;
        }
    }

    dfs(s, 0, visited);
    return Array.from(ans);
};

//debug
let s = "abc"
console.log(permutation(s))