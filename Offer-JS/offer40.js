/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 * 找最小的k个数
 * 使用快速排序的划分函数
 */
var getLeastNumbers0 = function(arr, k) {
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

//TODO:堆
// ac地址：https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/
// 原文地址：https://xxoo521.com/2020-02-21-least-nums/
function swap(arr, i, j) {
    [arr[i], arr[j]] = [arr[j], arr[i]];
}

class MaxHeap {
    constructor(arr = []) {
        this.container = [];
        if (Array.isArray(arr)) {
            for(let x of arr){
                this.insert.call(this, x);//插入每一个元素
            }
            //arr.forEach(this.insert.bind(this));
        }
    }

    insert(data) {
        const { container } = this;//获取当前堆

        container.push(data);//在最后插入，然后自下而上调整
        let index = container.length - 1;
        while (index) {
            let parent = Math.floor((index - 1) / 2);
            if (container[index] <= container[parent]) {
                break;//不用继续向上调整了
            }
            swap(container, index, parent);
            index = parent;//向上调整
        }
    }

    extract() {
        //去除一个元素
        const { container } = this;
        if (!container.length) {
            return null;
        }

        swap(container, 0, container.length - 1);//把根放在最后，把最后一个元素放在根的位置
        const res = container.pop();//去掉最后的元素
        //开始自上而下调整
        const length = container.length;
        let index = 0,
            exchange = index * 2 + 1;//左孩子

        while (exchange < length) {
            // 如果有右节点，并且右节点的值大于左节点的值
            let right = index * 2 + 2;
            if (right < length && container[right] > container[exchange]) {
                exchange = right;
            }
            if (container[index] >=  container[exchange]) {
                break;//不用继续向下调整了
            }
            swap(container, exchange, index);
            index = exchange;
            exchange = index * 2 + 1;
        }

        return res;//返回被去掉的元素（堆顶）
    }

    top() {
        if (this.container.length) return this.container[0];
        return null;
    }
}

/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var getLeastNumbers = function(arr, k) {
    const length = arr.length;
    if (k >= length) {
        return arr;
    }

    const heap = new MaxHeap(arr.slice(0, k));
    for (let i = k; i < length; ++i) {
        if (heap.top() > arr[i]) {
            heap.extract();
            heap.insert(arr[i]);
        }
    }
    return heap.container;
};

// 作者：xin-tan
// 链接：https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/solution/chao-quan-3chong-jie-fa-zhi-jie-pai-xu-zui-da-dui-/
//     来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。




//debug
let arr = [0,1,2,1], k = 3
console.log(getLeastNumbers(arr, k))