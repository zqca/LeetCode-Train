/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function(x, n) {
    if(n < 0){
        return 1 / myPow(x, -n);
    }
    if(x === 0 && n !== 0 || x === 1 || n === 1){
        return x;
    }
    if(n === 0){
        return 1;
    }

    let div = n % 2;//对半
    let part = parseInt(n / 2);
    let half = myPow(x, part);
    if(div){
        //奇数
        return half * half * x;
    }
    else{
        return half * half;
    }
};

console.log(myPow(2.1,3))