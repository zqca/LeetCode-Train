/**
 * @param {number} target
 * @return {number[][]}
 * 前缀和
 */
var findContinuousSequence0 = function(target) {
    let maxNum = Math.floor((target + 1) / 2);
    let preSum = Array(1 + maxNum);
    preSum[0] = 0;
    let mp = new Map();//<sum,index>
    mp.set(0, 0);
    for(let i = 1; i <= maxNum; ++i){
        preSum[i] = i + preSum[i - 1];
        mp.set(preSum[i], i);
    }

    let range = (start, end) =>{
        let ans = [];
        for(let i = start; i < end; ++i){
            ans.push(i);
        }
        return ans;
    }

    let ans = [];
    for(let i = 0; i <= maxNum; ++i){
        if(preSum[i] + target > preSum[maxNum]){
            break;
        }

        if(mp.has(preSum[i] + target)){
            ans.push(range(i + 1, mp.get(preSum[i] + target) + 1))
        }
    }
    return ans;
};


//优化，数学方法，二分
/**
 * @param {number} target
 * @return {number[][]}
 */
var findContinuousSequence1 = function(target) {
    let getSum = (a, b) => {
        //闭区间求和
        return (a + b) * (b - a + 1) / 2;
    }
    let search = (a, target, st, ed) => {
        //返回在闭区间内是否有使得getSum(a, b)等于target的b
        let low = st, high = ed, mid;
        while(low < high){
            mid = low + Math.floor((high - low) / 2);
            let tmp = getSum(a, mid);
            if(tmp === target){
                return mid;
            }
            if(tmp > target){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        if(getSum(a, low) === target){
            return low;
        }
        return -1;//不存在
    }
    let range = (start, end) =>{
        let ans = [];
        for(let i = start; i < end; ++i){
            ans.push(i);
        }
        return ans;
    }

    let maxNum = Math.floor((target + 1) / 2);
    let ans = [];

    for(let a = 1; a < maxNum; ++a){
        let tmp = search(a, target,a + 1, maxNum);
        if(tmp === -1){
            continue;
        }
        ans.push(range(a, tmp + 1));
    }
    return ans;
};

//滑动窗口
/**
 * 窗口左右都只能向右滑动！！
 * @param {number} target
 * @return {number[][]}
 */
var findContinuousSequence = function(target) {
    let maxNum = Math.floor((target + 1) / 2);
    let arr = [];
    for(let i = 0; i <= maxNum; ++i){
        arr.push(i);
    }

    let i = 1, j = 2, tmpSum = 3;
    let ans = [];
    while(i < j && j <= maxNum){
        if(tmpSum === target){
            ans.push(arr.slice(i, j + 1));
            tmpSum -= i;
            ++i;
            continue;
        }

        if(tmpSum < target){
            ++j;//扩大窗口
            tmpSum += j;
        }
        else{
            tmpSum -= i;
            ++i;
        }
    }
    return ans;
};



//debug
let target = 15;
console.log(findContinuousSequence(target))

