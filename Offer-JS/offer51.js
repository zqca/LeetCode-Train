/**
 * @param {number[]} nums
 * @return {number}
 * 归并排序的基础上改动
 */

var reversePairs = function(nums) {
    let count = 0;

    /**
     * 将一个数组划分两个子数组
     * @param nums 完整数组
     * @param left 原始数组的左边界
     * @param right 原始数组的有边界
     */
    let merge = function(nums, left, right) {
        if(left < right){
            //否则不用划分啦
            let mid = left + Math.floor((right - left) / 2);
            merge(nums, left, mid);
            merge(nums, mid + 1, right);
            mergeSort(nums, left, mid, right);
        }
    }

    /**
     * 合并两个已排序的子数组，顺便统计逆序对
     * @param nums
     * @param left
     * @param mid
     * @param right
     */
    let mergeSort = function(nums, left, mid, right){
        let tmp = Array(right - left + 1);
        let index = 0;
        let i = left, j = mid + 1;

        while(i <= mid && j <= right){
            if(nums[i] <= nums[j]){
                tmp[index++] = nums[i];
                ++i;
            }
            else{
                count += mid - i + 1;
                tmp[index++] = nums[j];
                ++j;
            }
        }
        //加入剩下的子数组
        while(i <= mid){
            tmp[index++] = nums[i++];
        }

        while(j <= right){
            tmp[index++] = nums[j++];
        }

        //修改原数组
        index = 0;
        for(let k = left; k <= right; ++k){
            nums[k] = tmp[index++];
        }
    }

    //主函数
    merge(nums, 0, nums.length - 1);
    return count;
};

//debug
let nums = [7,5,6,4];
console.log(reversePairs(nums))