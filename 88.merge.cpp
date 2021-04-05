#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> nums3(m + n);
    nums1.resize(m);
    nums1.push_back(INT32_MAX);
    nums2.push_back(INT32_MAX);
    int i = 0, j = 0;
    for(int k = 0; k < m + n; k++) {
        if(nums1[i] < nums2[j]) {
            nums3[k] = nums1[i++];
        }
        else {
            nums3[k] = nums2[j++];
        }
    }
    nums1 = nums3;
    

}

int main() {
    vector<int> nums1 = {1,2,3,0,0,0}; 
    int m = 3; 
    vector<int> nums2 = {2,5,6}; 
    int n = 3;
    merge(nums1, m, nums2, n);
//打印
    return 0;

}