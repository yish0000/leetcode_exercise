#include "TestCase.h"
#include <unordered_map>
#include <set>

using namespace std;

class Solution4Sum
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> res;
        unordered_map<int, vector<int>> m;
        for (int i=0; i<(int)nums.size()-1; i++)
        {
            for (int j=i+1; j<(int)nums.size(); j++)
            {
                m[nums[i]+nums[j]].push_back(i);
                m[nums[i]+nums[j]].push_back(j);
            }
        }
        for (int i=0; i<(int)nums.size()-1; i++)
        {
            for (int j=i+1; j<(int)nums.size(); j++)
            {
                unordered_map<int, vector<int>>::const_iterator it = m.find(target-nums[i]-nums[j]);
                if (it != m.end())
                {
                    for (int n=0; n<(int)it->second.size(); n+=2)
                    {
                        if (i != it->second[n] && i != it->second[n+1] &&
                            j != it->second[n] && j != it->second[n+1])
                        {
                            vector<int> r;
                            r.push_back(nums[i]);
                            r.push_back(nums[j]);
                            r.push_back(nums[it->second[n]]);
                            r.push_back(nums[it->second[n+1]]);
                            std::sort(r.begin(), r.end());
                            res.insert(r);
                        }
                    }
                }
            }
        }
        vector<vector<int>> result;
        for (set<vector<int>>::iterator it=res.begin(); it!=res.end(); ++it)
        {
            result.push_back(*it);
        }
        return result;
    }
};

RUN_TESTCASE(4Sum)
{
    Solution4Sum sln;
    
    vector<int> arr1 = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> res1 = {
        {1, 0, -1, 0},
        {1, -1, -2, 2},
        {0, 0, -2, 2},
    };
    TESTCASE_ASSERT(sln.fourSum(arr1, 0) == res1);
    
    vector<int> arr2;
    vector<vector<int>> res2 = {};
    TESTCASE_ASSERT(sln.fourSum(arr2, 0) == res2);
    
    vector<int> arr3 = {-3,-2,-1,0,0,1,2,3};
    TESTCASE_ASSERT(sln.fourSum(arr3, 0) == res2);
}
