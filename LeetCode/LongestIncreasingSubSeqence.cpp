//
//  LongestIncreasingSubSeqence.cpp
//  leetcode_exercise
//
//  Created by zhouchu hou on 2020/5/10.
//  Copyright © 2020 侯周楚. All rights reserved.
//

#include "TestCase.h"

using namespace std;

class SolutionLongestIncreasingSubsequence
{
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int max_len = 1;
        vector<int> dp(nums.size(), 0);
        dp[(int)nums.size()-1] = 1;
        for (int i=(int)nums.size()-2; i>=0; i--)
        {
            dp[i] = 1;
            for (int j=i+1; j<nums.size(); j++)
            {
                if (nums[i] < nums[j])
                    dp[i] = std::max(dp[i], dp[j] + 1);
            }
            max_len = std::max(max_len, dp[i]);
        }
        return max_len;
    }

	int lengthOfLISFast(vector<int>& nums) {
		vector<int> lis;
		for (auto num : nums)
		{
			auto it = std::lower_bound(lis.begin(), lis.end(), num);
			if (it == lis.end())
				lis.push_back(num);
			else if (*it > num)
				*it = num;
		}
		return (int)lis.size();
	}
};

RUN_TESTCASE(LongestIncreasingSubsequence)
{
    SolutionLongestIncreasingSubsequence sln;
    
    vector<int> arr1 = {10,9,2,5,3,7,101,18};
    TESTCASE_ASSERT(sln.lengthOfLISFast(arr1) == 4);
    
    vector<int> arr2 = {4,10,4,3,8,9};
    TESTCASE_ASSERT(sln.lengthOfLISFast(arr2) == 3);
    
    vector<int> arr3 = {1,3,6,7,9,4,10,5,6};
    TESTCASE_ASSERT(sln.lengthOfLISFast(arr3) == 6);
}
