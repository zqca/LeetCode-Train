/**
 * initialize your data structure here.
 */
var MinStack = function() {
    this.myStack = [];
    this.curMin = Number.MAX_SAFE_INTEGER;
};

/**
 * @param {number} x
 * @return {void}
 */
MinStack.prototype.push = function(x) {
    if(x < this.curMin){
        this.curMin = x;
    }
    this.myStack.push([x, this.curMin]);
};

/**
 * @return {void}
 */
MinStack.prototype.pop = function() {
    this.myStack.pop();
    //更新当前最小值
    let len = this.myStack.length;
    if(len === 0){
        this.curMin = Number.MAX_SAFE_INTEGER;
    }
    else{
        this.curMin = this.myStack[len - 1][1];
    }
};

/**
 * @return {number}
 */
MinStack.prototype.top = function() {
    let index = this.myStack.length - 1;
    return this.myStack[index][0];
};

/**
 * @return {number}
 */
MinStack.prototype.min = function() {
    let index = this.myStack.length - 1;
    return this.myStack[index][1];
};

/**
 * Your MinStack object will be instantiated and called as such:
 * var obj = new MinStack()
 * obj.push(x)
 * obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.min()
 */

//debug
var obj = new MinStack()
obj.push(-2);
obj.push(0);
obj.push(-3);
console.log(obj.min());   // 返回 -3.
obj.pop();
console.log(obj.top());   // 返回 0.
console.log(obj.min());   // 返回 -2.

