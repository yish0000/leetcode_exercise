#include "TestCase.h"
#include <unordered_map>

using namespace std;

class SolutionContinuousSubarraySum
{
public:
    bool checkSubarraySumSlow(vector<int>& nums, int k) {
        for (int i=0; i<(int)nums.size(); i++)
        {
            int sum = nums[i];
            for (int j=i+1; j<(int)nums.size(); j++)
            {
                if (k == 0)
                {
                    if (sum == nums[j])
                        return true;
                    sum = nums[j];
                }
                else
                {
                    sum += nums[j];
                    if (sum % k == 0)
                        return true;
                }
            }
        }
        return false;
    }
    
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.empty()) return false;
        unordered_map<int, int> sums;
        int sum = nums[0];
        sums[sum] = 0;
        for (int i=1; i<(int)nums.size(); i++)
        {
            if (k == 0)
            {
                if (sum == nums[i])
                    return true;
                sum = nums[i];
            }
            else
            {
                sum += nums[i];
                if (sum % k == 0)
                    return true;
                for (int j=0; j<=sum/k; j++)
                {
                    unordered_map<int, int>::const_iterator it = sums.find(sum - j*k);
                    if (it != sums.end() && i - it->second >= 2)
                        return true;
                }
                if (sums.find(sum) == sums.end())
                    sums[sum] = i;
            }
        }
        
        return false;
    }
};

RUN_TESTCASE(ContinuousSubarraySum)
{
    SolutionContinuousSubarraySum sln;

    vector<int> arr = {23, 2, 6, 4, 7};
    TESTCASE_ASSERT(sln.checkSubarraySum(arr, 6));
    
    vector<int> arr2 = {5,0,0,0};
    TESTCASE_ASSERT(sln.checkSubarraySum(arr2, 0));
    
    vector<int> arr3 = {1,1,2,-8,3,0};
    TESTCASE_ASSERT(sln.checkSubarraySum(arr3, -4));

    vector<int> arr4 = {0,1,0};
    TESTCASE_ASSERT(!sln.checkSubarraySum(arr4, 0));
    
    vector<int> arr5 = {1,2,12,6};
    TESTCASE_ASSERT(sln.checkSubarraySum(arr5, 6));
    
    vector<int> arr6 = {23,2,6,2,5};
    TESTCASE_ASSERT(!sln.checkSubarraySum(arr6, 6));
    
    vector<int> arr7 = {1,0,1,0,1};
    TESTCASE_ASSERT(!sln.checkSubarraySum(arr7, 4));
    
    vector<int> arr8 = {1,2,3};
    TESTCASE_ASSERT(sln.checkSubarraySum(arr8, 5));
    
    vector<int> arr9 = {23,0,0};
    TESTCASE_ASSERT(sln.checkSubarraySum(arr9, 6));
}
