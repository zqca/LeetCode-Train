#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void show(vector<int> vec) {
    if(vec.size() == 0) return;

    cout << vec[0];
    for(int i = 1; i < vec.size(); i++){
        cout << " " << vec[i];
    }
    cout << endl;
}

//TODO:冒泡排序
vector<int> bubble_sort(vector<int> raw) {
    vector<int> ans = raw;
    int len = raw.size();
    //每一趟都会有一个元素沉底,有序区在后面
    for(int i = 0; i < len - 1; ++i) {//次数
        for(int j = 0; j < len - i - 1; ++j) {
            if(ans[j] > ans[j + 1]) {
                swap(ans[j], ans[j + 1]);
            }
        }
    }

    return ans;
}

//TODO:选择排序
vector<int> selection_sort(vector<int> raw) {
    //有序区域放在开头
    vector<int> ans = raw;
    int len = raw.size();
    int pos;//最小元素的位置

    for (int i = 0; i < len; i++) {//选择的次数
        pos = i;
        for(int j = pos; j < len; j++) { 
            if(ans[pos] > ans[j]) {
                pos = j;
            }
        }
        swap(ans[pos], ans[i]);
    }

    return ans;
}

//TODO:插入排序
vector<int> insertion_sort(vector<int> raw) {
    //有序区域放在开头
    vector<int> ans = raw;
    int len = raw.size();

    int pos = 0;//最后一个有序元素的位置

    for (int i = 1; i < len; i++) {//插入的元素的下标
        pos = i;

        while(i - 1 >= 0 && ans[i - 1] > ans[i]) {
            swap(ans[i - 1], ans[i]);
            --i;
        }
        i = pos;
    }

    return ans;
}

//TODO:快速排序
int myPartition(vector<int> &vec, int low, int high) {
    //超时！！！！
    //以第一个元素作为标准
    if(low >= high) return low;

    deque<int> tmpVec;

    int p = vec[low];
    tmpVec.push_back(p);
    int diff = 0;//分割点的偏移量，最终的分割点是low+diff

    for(int k = high; k > low; k--){
        if(vec[k] < p) {
            tmpVec.push_front(vec[k]);
            diff++;
        }
        else{
            tmpVec.push_back(vec[k]);
        }
    }

    for(int k = low; k <= high; ++k) {
        vec[k] = tmpVec[k - low];
    }

    return low + diff;
}

int partition(vector<int> &vec, int low, int high) {
    int pivot = vec[low];

    while(low < high) {
        while(low < high && vec[high] >= pivot) {
            --high;
        }
        vec[low] = vec[high];

        while(low < high && vec[low] <= pivot) {
            ++low;
        }
        vec[high] = vec[low];
    }

    vec[low] = pivot;
    return low;
}

void QuickSort(vector<int>& ans, int low, int high) {
    //闭区间
    //if(ans.size() == 0) return ans;
    if(low < high) {
        int p = partition(ans, low, high);
        QuickSort(ans, low, p - 1);
        QuickSort(ans, p + 1, high);
    }
}

//TODO:归并排序
void Merge(vector<int>& vec, int front, int mid, int end) {
    //做合并的操作，目前两个数组已经排好序
    vector<int> left_vec(vec.begin() + front, vec.begin() + mid + 1);
    vector<int> right_vec(vec.begin() + mid + 1, vec.begin() + end + 1);

    //解决一个数组结束后合并的单独处理难题
    left_vec.push_back(INT32_MAX);
    right_vec.push_back(INT32_MAX);

    int left_idx = 0;
    int right_idx = 0;

    for(int i = front; i < end + 1; ++i){
        if(left_vec[left_idx] < right_vec[right_idx]) {
            vec[i] = left_vec[left_idx ++];
        }
        else {
            vec[i] = right_vec[right_idx ++];
        }
    }

}
void MergeSort(vector<int>& vec, int front, int end){
    //闭区间
    if(front >= end) return;

    int mid = (front + end) / 2;
    MergeSort(vec, front, mid);
    MergeSort(vec, mid + 1, end);
    Merge(vec, front, mid, end);
}


//TODO:堆排序

void heapify_max(vector<int>& vec, int start, int end) {
    //要求从小到！！大！！排序，因此建立！！大！！顶堆，
    //这里只负责调整指定范围内的堆
    int dad = start;
    int son = dad * 2 + 1;//这是左孩子

    while(son <= end) {
        if(son + 1 <= end && vec[son + 1] > vec[son]) {//选择较大的孩子,如果右孩子不越界的话
            son++;
        }
        if(vec[dad] > vec[son]) {
            return; //不需要调整
        }
        else{
            swap(vec[dad], vec[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

void HeapSort(vector<int> &vec) {
    //先初始化，调整堆
    int len = vec.size();
    for(int i = len / 2 - 1; i >= 0; --i) {
        //i从最后一个非叶子节点开始调整
        heapify_max(vec, i, len - 1);
    }
    //将第一个元素和最后一个元素进行交换，实现将全局最大值放在最后（后面先有序）
    for(int i = len - 1; i > 0; --i) {
        swap(vec[0], vec[i]);
        //相当于删除堆顶元素,然后调整剩下的未排序元素
        heapify_max(vec, 0, i - 1);
    }

}

int main() {
    vector<int> raw = {1,2,42,5,2,14,22};
    cout << "Before: ";
    show(raw);


    //TODO:冒泡排序
    vector<int> tmp1 = bubble_sort(raw);
    cout << "bubble_sort: ";
    show(tmp1);

    //TODO:选择排序
    vector<int> tmp2 = selection_sort(raw);
    cout << "selection_sort: ";
    show(tmp2);

    //TODO:插入排序
    vector<int> tmp3 = insertion_sort(raw);
    cout << "insertion_sort: ";
    show(tmp3);

    //TODO:快速排序
    vector<int> tmp4 = raw;
    QuickSort(tmp4, 0, raw.size() - 1);
    cout << "QuickSort: ";
    show(tmp4);

    //TODO:归并排序
    vector<int> tmp5 = raw;
    MergeSort(tmp5, 0, raw.size() - 1);
    cout << "MergeSort: ";
    show(tmp5);

    //TODO:堆排序
    vector<int> tmp6 = raw;
    HeapSort(tmp6);
    cout << "HeapSort: ";
    show(tmp6);


}