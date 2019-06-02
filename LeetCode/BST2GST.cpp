#include <iostream>
#include "TestCase.h"
#include <vector>
#include <queue>
#include <math.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int CalcNode(TreeNode* node, int value)
    {
        if (!node)
            return 0;
        
        int curValue = value;
        if (node->right)
        {
            curValue = CalcNode(node->right, value);
        }
        
        curValue += node->val;
        node->val = curValue;
        
        if (node->left)
        {
            curValue = CalcNode(node->left, curValue);
        }
        
        return curValue;
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        CalcNode(root, 0);
        return root;
    }
    
    TreeNode* MakeTree(const std::vector<int>& arr)
    {
        if (arr.size() <= 0) return nullptr;
        
        std::queue<TreeNode*> queue;

        size_t index = 0;
        TreeNode* root = new TreeNode(arr[index++]);
        queue.push(root);
        while(queue.size() > 0 && index + 2 <= arr.size())
        {
            TreeNode* curNode = queue.front();
            queue.pop();
            
            int curValue = arr[index++];
            if (curValue != -1)
            {
                curNode->left = new TreeNode(curValue);
                queue.push(curNode->left);
            }

            curValue = arr[index++];
            if (curValue != -1)
            {
                curNode->right = new TreeNode(curValue);
                queue.push(curNode->right);
            }
        }
        
        return root;
    }
    
    void FreeTree(TreeNode* root)
    {
        if (!root) return;
        FreeTree(root->left);
        FreeTree(root->right);
        delete root;
    }
    
    int CalcDepth(TreeNode* root)
    {
        if (!root)
            return 0;
        
        if (!root->left && !root->right)
            return 1;
        
        int leftDepth = 0;
        int rightDepth = 0;
        if (root->left)
            leftDepth = CalcDepth(root->left) + 1;
        if (root->right)
            rightDepth = CalcDepth(root->right) + 1;
        return std::max(leftDepth, rightDepth);
    }
    
    void Tree2Vector(TreeNode* root, std::vector<int>& out)
    {
        std::queue<TreeNode*> queue;
        if (root)
        {
            int max_depth = CalcDepth(root);
            int count = pow(2, max_depth) - 1;
            queue.push(root);
            while (queue.size() > 0 && count > 0)
            {
                TreeNode* curNode = queue.front();
                queue.pop();
                count -= 1;
                if (curNode)
                    out.push_back(curNode->val);
                else
                {
                    out.push_back(-1);
                }
                
                if (curNode && curNode->left)
                    queue.push(curNode->left);
                else
                    queue.push(nullptr);
                if (curNode && curNode->right)
                    queue.push(curNode->right);
                else
                    queue.push(nullptr);
            }
        }
    }
    
    bool TreeEqual(TreeNode* root, const std::vector<int>& result)
    {
        std::vector<int> out;
        Tree2Vector(root, out);
        return out == result;
    }
    
    void PrintTree(TreeNode* root)
    {
        std::vector<int> out;
        Tree2Vector(root, out);
        std::cout << "[";
        for (size_t i=0; i<out.size(); i++)
        {
            if (out[i] >= 0)
                std::cout << out[i] << ",";
            else
                std::cout << "null,";
        }
        std::cout << "]" << std::endl;
    }
};

RUN_TESTCASE(BST2GST)
{
    Solution sln;
    std::vector<int> arr = {4,1,6,0,2,5,7,-1,-1,-1,3,-1,-1,-1,8};
    TreeNode* tree = sln.MakeTree(arr);
    sln.PrintTree(tree);
    sln.bstToGst(tree);
    sln.PrintTree(tree);
    TESTCASE_ASSERT(sln.TreeEqual(tree, {30,36,21,36,35,26,15,-1,-1,-1,33,-1,-1,-1,8}))
    sln.FreeTree(tree);
}
