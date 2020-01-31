#include "TestCase.h"

using namespace std;

class SolutionRemoveDupFromSortedArrayII
{
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        int last = nums[0];
        int cnt = 0;
        for (int i=1; i<(int)nums.size(); i++)
        {
            if (nums[i] == last)
            {
                if (++cnt == 2)
                {
                    last = nums[i];
                    cnt--;
                    nums.erase(nums.begin() + i);
                    i -= 1;
                }
            }
            else
            {
                last = nums[i];
                cnt = 0;
            }
        }
        
        return (int)nums.size();
    }
};

RUN_TESTCASE(RemoveDupFromSortedArrayII)
{
    SolutionRemoveDupFromSortedArrayII sln;
    
    vector<int> arr1 = {1,1,1,2,2,3};
    vector<int> ret1 = {1,1,2,2,3};
    TESTCASE_ASSERT(sln.removeDuplicates(arr1) == 5);
    TESTCASE_ASSERT(arr1 == ret1);
    
    vector<int> arr2 = {0,0,1,1,1,1,2,3,3};
    vector<int> ret2 = {0,0,1,1,2,3,3};
    TESTCASE_ASSERT(sln.removeDuplicates(arr2) == 7);
    TESTCASE_ASSERT(arr2 == ret2);
}
