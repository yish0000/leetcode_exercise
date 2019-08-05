#include "TestCase.h"
#include <unordered_map>

using namespace std;

class SolutionSubarraySumEqualsK
{
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        int sum = 0;
        for (int i=0; i<(int)nums.size(); i++)
        {
            sum += nums[i];
            if (m.find(sum - k) != m.end())
                count += m[sum - k];
            m[sum]++;
        }
        return count;
	}
    
    int subarraySumSlow(vector<int>& nums, int k) {
        int count = 0;
        for (int i=0; i<(int)nums.size(); i++)
        {
            int sum = nums[i];
            if (sum == k) count++;
            for (int j=i+1; j<(int)nums.size(); j++)
            {
                sum += nums[j];
                if (sum == k) count++;
            }
        }
        return count;
    }
};

RUN_TESTCASE(SubarraySumEqualsK)
{
    vector<int> arr = {1,2,2,4,3,1,1,3,2,2};
    vector<int> arr2 = {3,4,7,2,-3,1,4,2};
    vector<int> arr3 = {0,0,0,0,0,0,0,0,0,0};
    
    SolutionSubarraySumEqualsK sln;
    TESTCASE_ASSERT(sln.subarraySum(arr, 4) == 5);
    TESTCASE_ASSERT(sln.subarraySum(arr2, 7) == 4);
    TESTCASE_ASSERT(sln.subarraySum(arr3, 0) == 55);
}
