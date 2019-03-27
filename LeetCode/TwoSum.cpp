#include "TestCase.h"
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;
		unordered_map<int, int> indexMap;

		for (size_t i = 0; i < nums.size(); ++i)
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

RUN_TESTCASE(TwoSum)
{
	Solution sln;
	vector<int> arr = { 1,2,3,4,5,6,7,8,9 };
	vector<int> ret = sln.twoSum(arr, 11);
	TESTCASE_ASSERT((ret[0] == 4 && ret[1] == 5) || (ret[0] == 5 && ret[1] == 4));
}