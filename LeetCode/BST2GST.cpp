#include "TestCase.h"
#include "BinaryTreeCommon.h"

class SolutionBST2GST : public BinaryTreeCommmon
{
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
};

RUN_TESTCASE(BST2GST)
{
    SolutionBST2GST sln;
    std::vector<int> arr = {4,1,6,0,2,5,7,-1,-1,-1,3,-1,-1,-1,8};
    TreeNode* tree = sln.MakeTree(arr);
    sln.PrintTree(tree);
    sln.bstToGst(tree);
    sln.PrintTree(tree);
    TESTCASE_ASSERT(sln.TreeEqual(tree, {30,36,21,36,35,26,15,-1,-1,-1,33,-1,-1,-1,8}))
    sln.FreeTree(tree);
}
