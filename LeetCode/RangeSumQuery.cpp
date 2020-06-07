//
//  RangeSumQuery.cpp
//  leetcode_exercise
//
//  Created by zhouchu hou on 2020/6/7.
//  Copyright © 2020 侯周楚. All rights reserved.
//

#include "TestCase.h"

using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        sums.resize(nums.size()+1);
        for (int i=0; i<nums.size(); i++)
            sums[i+1] = sums[i] + nums[i];
    }
    
    int sumRange(int i, int j) {
        return sums[j+1] - sums[i];
    }
    
protected:
    vector<int> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
RUN_TESTCASE(RangeSumQuery)
{
    vector<int> arr = {-2, 0, 3, -5, 2, -1};
    NumArray sln(arr);
    TESTCASE_ASSERT(sln.sumRange(0, 2) == 1);
    TESTCASE_ASSERT(sln.sumRange(2, 5) == -1);
    TESTCASE_ASSERT(sln.sumRange(0, 5) == -3);
}
