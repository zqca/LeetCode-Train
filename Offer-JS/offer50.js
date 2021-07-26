/**
 * @param {string} s
 * @return {character}
 */
var firstUniqChar = function(s) {
    let ans = ' ';
    if(s.length === 0) return ans;

    let mp = new Map();
    //首先统计每个字母的出现次数
    for(let i = 0; i < s.length; ++i){
        if(mp[s[i]] === undefined){
            mp[s[i]] = 1;
        }
        else{
            ++mp[s[i]];
        }
    }

    for(let i = 0; i < s.length; ++i){
        if(mp[s[i]] === 1){
            return s[i];
        }
    }
    return ans;
};

//debug
let s= "leetcode";
console.log(firstUniqChar(s))