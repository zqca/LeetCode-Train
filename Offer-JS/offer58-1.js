/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    s = s.trim();//去除头尾空格
    let arr = s.split(" ").filter((cur)=>{
        return !(cur === '' || cur === " ");
    });

    arr.reverse();
    return arr.join(" ");
};

/**正则
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    s = s.replace(/ +/g, ' ');//将多余的空格变成一个
    return s.split(' ').reverse().join(" ");
};