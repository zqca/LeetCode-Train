var CQueue = function(){
    this.input = [];
    this.output = [];
};

/**
 * @param {number} value
 * @return {void}
 */
CQueue.prototype.appendTail = function(value) {
    this.input.push(value);
};

/**
 * @return {number}
 */
CQueue.prototype.deleteHead = function() {
    if(this.output.length){
        return this.output.pop();
    }
    if(this.input.length === 0){
        return -1;
    }
    while(this.input.length){
        this.output.push(this.input.pop());
    }
    return  this.output.pop();
};

/**
 * Your CQueue object will be instantiated and called as such:
 * var obj = new CQueue()
 * obj.appendTail(value)
 * var param_2 = obj.deleteHead()
 */