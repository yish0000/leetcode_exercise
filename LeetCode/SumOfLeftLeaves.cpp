//
//  SumOfLeftLeaves.cpp
//  leetcode_exercise
//
//  Created by zhouchu hou on 2021/10/3.
//  Copyright © 2021 侯周楚. All rights reserved.
//

#include "TestCase.h"
#include "BinaryTreeCommon.h"

using namespace std;

class SolutionSumOfLeftLeaves : public BinaryTreeCommmon
{
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        dfs(root, false, sum);
        return sum;
    }
    
    void dfs(TreeNode* node, bool left, int& sum)
    {
        if (!node)
            return;
        if (left && !node->left && !node->right)
            sum += node->val;
        dfs(node->left, true, sum);
        dfs(node->right, false, sum);
    }
};

RUN_TESTCASE(SumOfLeftLeaves)
{
    SolutionSumOfLeftLeaves sln;
    vector<string> arr1 = {"3","9","20","null","null","15","7"};
    TreeNode* tr1 = sln.MakeTree(arr1);
    TESTCASE_ASSERT(sln.sumOfLeftLeaves(tr1) == 24);
    sln.FreeTree(tr1);
    
    vector<string> arr2 = {"1"};
    TreeNode* tr2 = sln.MakeTree(arr2);
    TESTCASE_ASSERT(sln.sumOfLeftLeaves(tr2) == 0);
    sln.FreeTree(tr2);
    
    vector<string> arr3 = {"1","2","3","4","5"};
    TreeNode* tr3 = sln.MakeTree(arr3);
    TESTCASE_ASSERT(sln.sumOfLeftLeaves(tr3) == 4);
    sln.FreeTree(tr3);
}
