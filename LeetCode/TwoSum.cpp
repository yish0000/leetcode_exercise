#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;
		unordered_map<int, int> indexMap;

		for (int i = 0; i < nums.size(); ++i)
		{
			if (indexMap.find(target - nums[i]) != indexMap.end())
			{
				result.push_back(i);
				result.push_back(indexMap[target - nums[i]]);
				return result;
			}
			else
				indexMap[nums[i]] = i;
		}

		return result;
	}
};

void Test_TwoSum()
{
	Solution sln;
	vector<int> arr = { 1,2,3,4,5,6,7,8,9 };
	vector<int> ret = sln.twoSum(arr, 11);
	cout << ret[0] << ", " << ret[1] << endl;
}