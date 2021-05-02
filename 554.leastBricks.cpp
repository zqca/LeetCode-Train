#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int leastBricks(vector<vector<int>>& wall) {
    unordered_map<int,int> mymap;
    int sum;
    for(int i = 0; i < wall.size(); i++){
        //每一行
        sum = 0;
        for(int j = 0; j < wall[i].size(); j++){
            sum += wall[i][j];
            
            mymap[sum]++;  
        }
    }
    mymap.erase(sum);


    int ans = 0;
    for(auto item = mymap.begin(); item != mymap.end(); item++){
        ans = max(ans, item->second);
    }

    return wall.size() - ans;

}

int main()
{
   vector<vector<int> > wall = {{1},{1},{1}};
   int ans = leastBricks(wall);
   cout << ans << endl;
   return 0;
}
