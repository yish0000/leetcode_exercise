#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BinaryTreeCommmon
{
public:
    TreeNode* MakeTree(const std::vector<std::string>& arr)
    {
        if (arr.size() <= 0) return nullptr;
        
        std::queue<TreeNode*> queue;
        
        size_t index = 0;
        TreeNode* root = new TreeNode(atoi(arr[index++].c_str()));
        queue.push(root);
        while(queue.size() > 0)
        {
            TreeNode* curNode = queue.front();
            queue.pop();
            
			if (index + 1 <= arr.size())
			{
				std::string curValue = arr[index++];
				if (curValue != "null")
				{
					curNode->left = new TreeNode(atoi(curValue.c_str()));
					queue.push(curNode->left);
				}
			}

			if (index + 1 <= arr.size())
			{
				std::string curValue = arr[index++];
				if (curValue != "null")
				{
					curNode->right = new TreeNode(atoi(curValue.c_str()));
					queue.push(curNode->right);
				}
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
            int count = (int)pow(2, max_depth) - 1;
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
    
    bool isBST(TreeNode* root)
    {
        if (!root) return true;
        if (!root->left && !root->right)
            return true;
        
        int curMax = 0;
        return isBSTHelper(root, curMax);
    }
    
    bool isBSTHelper(TreeNode* root, int& curMax)
    {
        if (!root) return true;
        if (!isBSTHelper(root->left, curMax))
            return false;
        if (root->val > curMax)
            curMax = root->val;
        else
            return false;
        return isBSTHelper(root->right, curMax);
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
