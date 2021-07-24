/**
 * @param {number[]} nums
 * @return {string}
 * sort的排序是看回调函数的返回值：
        如果返回值大于 0，则位置互换。
        如果返回值小于 0，则位置不变。
 */
var minNumber = function(nums) {
    /**
     * 输入的是数字a,b
     * @param a
     * @param b
     */
    let cmp = function (a, b) {
        let str_a = String(a);
        let str_b = String(b);

        let A = str_a + str_b;
        let B = str_b + str_a;
        if(A < B){
            return -1;//不交换
        }
        else{
            return 1;
        }
    }

    nums.sort(cmp);
    return nums.join('');

};

//debug
let nums = [824,8247];
console.log(minNumber(nums))