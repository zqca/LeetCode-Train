function MyQue() {
    this.que = [];
}

MyQue.prototype.myFront = function () {
    return this.que[0];
}

MyQue.prototype.myPush = function (value) {
    //从尾部比较，比value小的值都要去掉。因为这些值在value存在的条件下不可能是最大值
    let len = this.que.length;
    while (len && this.que[len - 1] < value) {
        this.que.pop();
        --len;
    }
    this.que.push(value);
}

MyQue.prototype.myPop = function (value) {
    //去除指定的值，只去除1个
    if (this.que.length && this.que[0] === value) {
        //只有当前窗口的最大值（队头）是需要去除的值时才操作
        this.que.shift();
    }
}


var MaxQueue = function () {
    this.Que = new MyQue();//单调队列
    this.tmp = [];//普通队列
};

/**
 * @return {number}
 */
MaxQueue.prototype.max_value = function () {
    if (this.tmp.length === 0) {
        return -1;
    }

    return this.Que.myFront();
};

/**
 * @param {number} value
 * @return {void}
 */
MaxQueue.prototype.push_back = function (value) {
    this.tmp.push(value);
    this.Que.myPush(value);
};

/**
 * @return {number}
 */
MaxQueue.prototype.pop_front = function () {
    if (this.tmp.length === 0) {
        return -1;
    }
    let val = this.tmp.shift();
    this.Que.myPop(val);
    return val;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * var obj = new MaxQueue()
 * var param_1 = obj.max_value()
 * obj.push_back(value)
 * var param_3 = obj.pop_front()
 */