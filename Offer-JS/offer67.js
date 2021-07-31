/**
 * @param {string} str
 * @return {number}
 */
var strToInt = function (str) {
    let getNum = (str) => {
        //获取数字,无效的输入返回‘0’
        str = str.trim();
        if (str.length === 0) {
            return '0';
        }
        let code = str.codePointAt(0);
        if (str[0] !== '+' && str[0] !== '-' && (code > '9'.codePointAt() || code < '0'.codePointAt())) {
            return '0';
        }

        let end;
        for (end = 1; end < str.length; ++end) {
            //停在第一个不是数字的位置
            let tmp = str.codePointAt(end);
            if (tmp > '9'.codePointAt(0) || tmp < '0'.codePointAt(0)) {
                break;
            }
        }
        let ans = str.slice(0, end);
        if (ans === '+' || ans === '-') {
            return '0';
        }

        return ans;
    }

    let toInt = (str) => {
        //将数字字符串(可能有符号，前导0)转换为数字,需要处理溢出
        if (str === '0') return 0;
        let arr = str.split('');
        let flag = -1;
        switch (arr[0]) {
            case '+':
                flag = 1;
                break;
            case '-':
                break;
            default:
                arr.unshift('+');
                flag = 1;
        }

        let ans = 0;
        let MAX = Math.pow(2, 31) - 1;
        let MIN = -MAX - 1;
        for (let i = 1; i < arr.length; ++i) {
            let num = arr[i].codePointAt(0) - '0'.codePointAt(0);
            ans = ans * 10 + (num) * flag;
            if (ans >= MAX) return MAX;
            if (ans <= MIN) return MIN;
        }
        return ans;
    }

    let num_str = getNum(str);
    return toInt(num_str);
};

//debug

let str = "+1"
console.log(strToInt(str))