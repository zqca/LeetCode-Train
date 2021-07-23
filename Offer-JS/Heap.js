class Heap {
    /**
     * @param arr，利用输入的arr构造堆
     * @param type，默认堆的类型type为大根堆
     */
    constructor(arr = [], type = 'big') {
        if(type !== 'big' && type !== 'small'){
            console.log('Wrong type! type should be "big" or "small"');
            return;
        }
        this.container = [];
        this.type = type;//堆的类型
        if(Array.isArray(arr)){
            for(let x of arr){
                //插入每一个数组中的元素
                this.insert.call(this, x);
            }
        }
    }

    /**
     * 向堆添加一个元素,自下向上调整。终止条件为curIndex = 0；
     * @param val
     */
    insert = (val) => {

        let { container, type } = this;
        container.push(val);//先放在末尾
        let curIndex = container.length - 1;
        let parent;
        while(curIndex){
            parent = Math.floor((curIndex - 1) / 2);

            if(type === 'big' && container[parent] >= container[curIndex]){
                //大根堆，不用向上调整了
                break;
            }
            if(type === 'small' && container[parent] <= container[curIndex]){
                //小根堆，不用向上调整了
                break;
            }

            //交换,向上调整
            [container[parent], container[curIndex]] = [container[curIndex], container[parent]];
            curIndex = parent;
        }
    }

    /**
     * 去掉堆的根，自上向下调整.终止条件只能是son越界，因为不确定最后的parent是谁！！！
     * @returns {null|*}返回堆的根
     */
    extract = () => {
        let { container, type } = this;

        if(!container.length){
            return null;//堆为空
        }
        //交换头尾元素
        [container[0], container[container.length - 1]] = [container[container.length - 1], container[0]];
        const res = container.pop();//去除最后一个元素（原来是堆的根）
        const len = container.length;
        let curParent = 0;
        let son = 2 * curParent + 1;//默认左孩子

        while(son < len){

            if(type === 'big' && son + 1 < len && container[son + 1] > container[son]){
                //右孩子更大
                son = son + 1;
            }
            if(type === 'small' && son + 1 < len && container[son + 1] < container[son]){
                //右孩子更小
                son = son + 1;
            }

            if(type === 'big' && container[curParent] >= container[son]){
                break;//停止调整
            }
            if(type === 'small' && container[curParent] <= container[son]){
                break;//停止调整
            }

            [container[curParent], container[son]] = [container[son], container[curParent]];
            curParent = son;
            son = 2 * curParent + 1;//默认左孩子
        }

        return res;//返回原来的堆的根
    }

    /**
     * @returns {*}返回堆顶的元素
     */
    top = () => {
        let { container } = this;
        return container[0];
    }

    /**
     * @returns {number}返回堆的长度（堆中元素的个数）
     */
    getLen = () => {
        let { container } = this;
        return container.length;
    }
}

//debug
let arr1 = [13,2,4,9,5];
let myHeap = new Heap(arr1, 'big');//构造大顶堆
myHeap.insert(99);
myHeap.top();
myHeap.extract();
myHeap.top()
myHeap.getLen();