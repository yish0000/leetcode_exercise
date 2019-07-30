#include "TestCase.h"
#include <set>

using namespace std;

class Solution3SumClosest
{
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) return 0;
        std::sort(nums.begin(), nums.end());
        int result = nums[0] + nums[1] + nums[2];
        int last_processed = std::numeric_limits<int>::min();
        for (int i=0; i<(int)nums.size() - 2; i++)
        {
            if (nums[i] == last_processed)
                continue;
            last_processed = nums[i];
            
            int l = i + 1;
            int r = (int)nums.size() - 1;
            while(l < r)
            {
                if (r - l >= 2)
                {
                    int mid = l + (r - l) / 2;
                    int cur1 = nums[i] + nums[l] + nums[mid];
                    int cur2 = nums[i] + nums[mid] + nums[r];
                    if (cur1 > target)
                    {
                        if (abs(cur1 - target) < abs(result - target))
                            result = cur1;
                        r = mid - 1;
                        continue;
                    }
                    else if (cur2 < target)
                    {
                        if (abs(cur2 - target) < abs(result - target))
                            result = cur2;
                        l = mid + 1;
                        continue;
                    }
                }
                
                int cur = nums[i] + nums[l] + nums[r];
                if (abs(cur - target) < abs(result - target))
                    result = cur;
                if (cur < target)
                    l++;
                else
                    r--;
            }
            
            if (nums[i] >= target)
                break;
        }
        return result;
    }
};

RUN_TESTCASE(3SumClosest)
{
    vector<int> arr1 = {-1, 2, 1, -4};
    vector<int> arr2 = {0, 1, 2};
    
    Solution3SumClosest sln;
    TESTCASE_ASSERT(sln.threeSumClosest(arr1, 1) == 2);
    TESTCASE_ASSERT(sln.threeSumClosest(arr2, 0) == 3);
}
