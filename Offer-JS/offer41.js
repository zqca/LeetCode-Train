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
            if (container[parent] >= container[index]) {
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
            if (right < length &&  container[exchange] < container[right]) {
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

class MinHeap {
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
            if (container[parent] <= container[index]) {
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
            // 如果有右节点，并且右节点的值小于左节点的值
            let right = index * 2 + 2;
            if (right < length && container[right] < container[exchange]) {
                exchange = right;
            }
            if (container[index] <=  container[exchange]) {
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
 * initialize your data structure here.
 */
var MedianFinder = function() {
    this.left = new MaxHeap();
    this.right = new MinHeap();
};

/**
 * @param {number} num
 * @return {void}
 */
MedianFinder.prototype.addNum = function(num) {
    if(this.left.container.length === 0 || num < this.left.top()){
        this.left.insert(num);
    }
    else{
        this.right.insert(num);
    }
    //调节平衡,左侧最多比右侧多一个元素
    if(this.left.container.length > this.right.container.length + 1){
        this.right.insert(this.left.top());
        this.left.extract();
    }
    if(this.right.container.length > this.left.container.length + 1){
        this.left.insert(this.right.top());
        this.right.extract();
    }
};

/**
 * @return {number}
 */
MedianFinder.prototype.findMedian = function() {
    if(this.left.container.length === this.right.container.length){
        return (this.left.top() + this.right.top()) / 2;
    }
    else{
        //左多右少，或者左少右多，取多的那一侧
        return this.left.container.length > this.right.container.length ? this.left.top() : this.right.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * var obj = new MedianFinder()
 * obj.addNum(num)
 * var param_2 = obj.findMedian()
 */
