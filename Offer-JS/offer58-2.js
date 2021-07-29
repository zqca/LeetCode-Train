/**
 * @param {string} s
 * @param {number} n
 * @return {string}
 */
var reverseLeftWords = function(s, n) {
    let part1 = s.slice(n);
    let part2 = s.slice(0, n);
    return part1 + part2;
};