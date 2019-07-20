#include "TestCase.h"

using namespace std;

class SolutionRemoveElement
{
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) return 0;
        int r = (int)nums.size() - 1;
        int l = 0;
        while(l < r)
        {
            if (nums[r] == val)
                r--;
            else
            {
                if (nums[l] == val)
                    std::swap(nums[l], nums[r]);
                l++;
            }
        }
        if (nums[r] == val)
            r--;
        return r + 1;
    }
};

RUN_TESTCASE(RemoveElement)
{
    SolutionRemoveElement sln;
    vector<int> arr1 = {3,2,2,3};
    vector<int> res1 = {2,2,3,3};
    TESTCASE_ASSERT(sln.removeElement(arr1, 3) == 2);
    TESTCASE_ASSERT(arr1 == res1);
    
    vector<int> arr2 = {0,1,2,2,3,0,4,2};
    vector<int> res2 = {0,1,4,0,3,2,2,2};
    TESTCASE_ASSERT(sln.removeElement(arr2, 2) == 5);
    TESTCASE_ASSERT(arr2 == res2);
    
    vector<int> arr3 = {2,1};
    TESTCASE_ASSERT(sln.removeElement(arr3, 0) == 2);
    
    vector<int> arr4 = {};
    TESTCASE_ASSERT(sln.removeElement(arr4, 0) == 0);
}
