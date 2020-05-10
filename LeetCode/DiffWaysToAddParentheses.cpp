//
//  DiffWaysToAddParentheses.cpp
//  leetcode_exercise
//
//  Created by zhouchu hou on 2020/5/3.
//  Copyright © 2020 侯周楚. All rights reserved.
//

#include "TestCase.h"

using namespace std;

class SolutionDiffWaysToAddParentheses
{
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> nums;
        vector<char> op;
        int num = 0;
        bool bHaveNum = false;
        for (string::iterator it=input.begin(); it!=input.end(); ++it)
        {
            if (isdigit(*it))
            {
                num = num * 10 + (*it - '0');
                bHaveNum = true;
            }
            else
            {
                nums.push_back(num);
                num = 0;
                bHaveNum = false;
                op.push_back(*it);
            }
        }
        if (bHaveNum)
        {
            nums.push_back(num);
            num = 0;
            bHaveNum = false;
        }
        
        vector<int> result;
        DivideAndConquer(nums, op, result);
        return result;
    }
    
    void DivideAndConquer(vector<int>& nums, vector<char>& op, vector<int>& result)
    {
        if (nums.size() == 1)
        {
            result.push_back(nums[0]);
            return;
        }
        else if (nums.size() == 2)
        {
            if (op[0] == '+')
                result.push_back(nums[0]+nums[1]);
            else if (op[0] == '-')
                result.push_back(nums[0]-nums[1]);
            else if (op[0] == '*')
                result.push_back(nums[0]*nums[1]);
            else if (op[0] == '/')
                result.push_back(nums[0]/nums[1]);
            return;
        }
        
        for (int i = 0; i<op.size(); i++)
        {
            vector<int> lnums(nums.begin(), nums.begin() + i + 1);
            vector<char> lop(op.begin(), op.begin() + i);
            vector<int> lresult;
            DivideAndConquer(lnums, lop, lresult);
            
            vector<int> rnums(nums.begin() + i + 1, nums.end());
            vector<char> rop(op.begin() + i + 1, op.end());
            vector<int> rresult;
            DivideAndConquer(rnums, rop, rresult);
            
            for (auto l : lresult)
            {
                for (auto r : rresult)
                {
                    if (op[i] == '+')
                        result.push_back(l + r);
                    else if (op[i] == '-')
                        result.push_back(l - r);
                    else if (op[i] == '*')
                        result.push_back(l * r);
                    else if (op[i] == '/')
                        result.push_back(l / r);
                }
            }
        }
    }
};

RUN_TESTCASE(DiffWaysToAddParentheses)
{
    SolutionDiffWaysToAddParentheses sln;
    
    vector<int> arr1 = {0, 2};
    vector<int> ret1 = sln.diffWaysToCompute("2-1-1");
    TESTCASE_ASSERT(vectorComboEqual(arr1, ret1));
    
    vector<int> arr2 = {-34, -14, -10, -10, 10};
    vector<int> ret2 =sln.diffWaysToCompute("2*3-4*5");
    TESTCASE_ASSERT(vectorComboEqual(arr2, ret2));
    
    vector<int> ret3 = {0};
    TESTCASE_ASSERT(sln.diffWaysToCompute("0") == ret3);
}
