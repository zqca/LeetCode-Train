#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target) 
{
	vector<int> result;
	unordered_map<int, int> map;

	int size = numbers.size();
	for (int i = 0; i < size; ++i)
	{
		int temp = target - numbers[i];
		auto pos = map.find(temp);

		if (pos != map.end())
		{
			int j = (*pos).second;

			result.push_back(j);
			result.push_back(i);

			break;
		}
		else
		{
			map[numbers[i]] = i;

		}
			
	}

	return result;
}

int main()
{
	
	int target = 9;
	vector<int> nums={8,79,2,7};
	vector<int> result;
	result = twoSum(nums, target);
	for (auto i = 0; i < result.size(); ++i) {
		cout << result[i] << " ";
	}
		
	system("pause");
	return 1;
	
}