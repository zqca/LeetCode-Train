/**
 * @param {number} a
 * @param {number} b
 * @return {number}
 * 位运算，不用担心负数，计算机内部有补码可以解决
 * 异或--无进位的和
 *   与--是否需要进位（真正的进位：与操作后左移一个）
 */
var add = function (a, b) {
    //无进位的结果n = a xor b
    //进位c = (a & b) << 1
    while (b !== 0) {
        //当进位为0时停止
        let n = a ^ b;
        let c = (a & b) << 1;
        a = n;
        b = c;
    }
    return a;
};