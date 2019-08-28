#include "TestCase.h"
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

class Solution3Sum {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> s;
        set<int> processed;
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        
        for (int i=0; i<(int)nums.size()-2; i++)
        {
            if (nums[i] > 0) break;
            if (processed.find(nums[i]) != processed.end())
                continue;
            
            processed.insert(nums[i]);
            
            int l = i + 1;
            int r = (int)nums.size() - 1;
            while(l < r)
            {
                if (nums[i] + nums[l] + nums[r] == 0)
                {
                    s.insert({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                }
                else if (nums[i] + nums[l] + nums[r] < 0)
                    l++;
                else
                    r--;
            }
        }
        
        for (set<vector<int>>::iterator it=s.begin(); it!=s.end(); ++it)
        {
            result.push_back(*it);
        }
        
        return result;
    }
};

RUN_TESTCASE(3Sum)
{
	Solution3Sum sln;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<int> result1 = {-1, -1, 2};
    vector<int> result2 = {-1, 0, 1};
    vector<vector<int>> result = sln.threeSum(nums);
    TESTCASE_ASSERT(result.size() == 2);
    if (result.size() == 2)
    {
        TESTCASE_ASSERT(result[0] == result1);
        TESTCASE_ASSERT(result[1] == result2);
    }
    
    vector<int> nums2 = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    vector<vector<int>> ret2 = sln.threeSum(nums2);
    TESTCASE_ASSERT(ret2.size() == 6);
}