/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 * 找最小的k个数
 * 使用快速排序的划分函数
 */
var getLeastNumbers = function(arr, k) {
    let ans = [];
    if(arr.length === 0 || k === 0){
        return ans;
    }

    let partition = function (arr, low, high){
        //闭区间
        let div = arr[low];
        while(low < high){
            while(low < high && arr[high] >= div){
                --high;
            }
            arr[low] = arr[high];
            while(low < high && arr[low] <= div){
                ++low;
            }
            arr[high] = arr[low];
        }
        arr[low] = div;
        return low;
    }

    let low = 0, high = arr.length - 1;
    let num = k;

    while(true){
        let pos = partition(arr, low, high);
        if(pos === k){
            break;
        }
        if(pos > k){
            high = pos;
        }
        if(pos < k){
            low = pos + 1;
        }
    }
    for(let i = 0; i < num; ++i){
        ans.push(arr[i]);
    }
    return ans;
};

//debug
let arr = [0,1,2,1], k = 1
console.log(getLeastNumbers(arr, k))