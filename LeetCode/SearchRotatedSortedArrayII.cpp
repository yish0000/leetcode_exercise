#include "TestCase.h"

using namespace std;

class SolutionSearchRotatedSortedArrayII
{
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty())
            return false;
        
        int pilot = -1;
        int l = 0;
        int r = (int)nums.size() - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[mid] > nums[mid+1])
            {
                pilot = mid;
                break;
            }
            //1，3，1，1，1
            if (nums[mid] > nums.back())
                l = mid + 1;
            else if (nums[mid] < nums.front())
                r = mid - 1;
            else
            {
                int t = 1;
                while(mid - t >= l || mid + t <= r)
                {
                    if (mid - t >= l && nums[mid-t] != nums[mid])
                    {
                        pilot = mid - t;
                        break;
                    }
                    if (mid + t <= r && nums[mid+t] != nums[mid])
                    {
                        pilot = mid + t;
                        break;
                    }
                    t++;
                }
                break;
            }
        }
        
        if (pilot < 0)
        {
            pilot = l;
            if (pilot >= (int)nums.size())
                pilot = (int)nums.size() - 1;
        }
        
        if (searchRecurse(nums, target, 0, pilot))
            return true;
        return searchRecurse(nums, target, pilot+1, (int)nums.size()-1);
    }
    
    bool searchRecurse(vector<int>& nums, int target, int beg, int end)
    {
        while(beg <= end)
        {
            int mid = beg + (end - beg) / 2;
            if (nums[mid] == target)
                return true;
            else if (nums[mid] > target)
                end = mid - 1;
            else
                beg = mid + 1;
        }
        
        return false;
    }
};

RUN_TESTCASE(SearchRotatedSortedArrayII)
{
    SolutionSearchRotatedSortedArrayII sln;
    
    vector<int> arr1 = {2,5,6,0,0,1,2};
    TESTCASE_ASSERT(sln.search(arr1, 0));
    TESTCASE_ASSERT(!sln.search(arr1, 3));
    
    vector<int> arr2 = {1};
    TESTCASE_ASSERT(sln.search(arr2, 1));
    
    vector<int> arr3 = {1,3,1,1,1};
    TESTCASE_ASSERT(sln.search(arr3, 3));
}
