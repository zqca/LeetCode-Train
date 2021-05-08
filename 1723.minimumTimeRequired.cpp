#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int target = INT32_MAX;

int dfs(vector<int> jobs, int curjob, int k, vector<int> time){
    
    if(curjob == jobs.size()){ 
        //所有任务分配完成，计算最大耗时
        return *max_element(time.begin(), time.end());
    }
    unordered_map<int,int> count;//对于某个任务，已经分配过员工的已用时间----次数

    for(int i = 0; i < k; ++i){
        //当前任务分配给员工i
        //如果把把某一任务分配给i后，i的工作时间已经大于target，z这种分配方案的最后结果肯定大于target,剪枝
        //对于同一个任务，分配给已用时间相同的不同员工对最后答案没有影响，可以剪枝
        if(count[time[i]] != 0) 
            continue;//这个员工的已用时间之前考虑过，分配给他与否不影响最终结果
        else{
            count[time[i]]++;
        }

        if(time[i] + jobs[curjob] > target){
            continue;
        }
        
        time[i] += jobs[curjob];
        int tmp = dfs(jobs, curjob + 1, k, time);
        target = min(target, tmp);
        //回溯
        time[i] -= jobs[curjob];
    }

    return target;
}

int minimumTimeRequired(vector<int>& jobs, int k) {
    vector<int> time(k, 0);//每位员工已分配任务的耗时
    
    return dfs(jobs, 0, k, time);
}

int main()
{
   vector<int> jobs = {1,2,4,7,8}; 
   int k = 2;

   int ans = minimumTimeRequired(jobs, k);
   cout << ans << endl;
   return 0;
}
