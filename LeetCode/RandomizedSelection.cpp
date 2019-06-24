#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <assert.h>
#include "TestCase.h"

class Solution
{
public:
    Solution()
    {
        srand((unsigned int)time(NULL));
    }
    
    int RandomSelect(std::vector<int>& arr, int k)
    {
        return RandomSelect(arr, 0, (int)arr.size()-1, k);
    }
    
protected:
    int RandomSelect(std::vector<int>& arr, int beg, int end, int k)
    {
        if (beg == end)
            return arr[beg];
        
        if (beg < end)
        {
            int part = RandomPartion(arr, beg, end);
            if (part == k-1)
                return arr[part];
            else if (part < k-1)
                return RandomSelect(arr, part+1, end, k);
            else
                return RandomSelect(arr, beg, part-1, k);
        }
        else
        {
            assert(false);
            return -1;
        }
    }
    
    int RandomPartion(std::vector<int>& arr, int beg, int end)
    {
        int rnd = beg + rand() % (end - beg + 1);
        int pivot = arr[rnd];
        int j = beg - 1;
        std::swap(arr[rnd], arr[end]);
        for (int i=beg; i<=end-1; i++)
        {
            if (arr[i] < pivot)
            {
                ++j;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[j+1], arr[end]);
        return j+1;
    }
};

RUN_TESTCASE(RandomizedSelection)
{
    Solution sln;
    std::vector<int> arr = {5,7,9,1,2,4,8};
    TESTCASE_ASSERT(sln.RandomSelect(arr, 3) == 4);
    TESTCASE_ASSERT(sln.RandomSelect(arr, 6) == 8);
}
