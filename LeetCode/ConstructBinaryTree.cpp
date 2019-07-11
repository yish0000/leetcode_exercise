#include "TestCase.h"
#include "BinaryTreeCommon.h"

using namespace std;

class SolutionConstructBinaryTree : public BinaryTreeCommmon
{
public:
    int post, in;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.empty() || inorder.empty())
            return nullptr;
        
        post = (int)postorder.size() - 1;
        in = (int)inorder.size() - 1;
        TreeNode* root = buildTreeHelper(inorder, postorder, std::numeric_limits<int>::min());
        return root;
    }
    
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int stop)
    {
        if (post < 0)
            return nullptr;

        if (stop == inorder[in])
        {
            in--;
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(postorder[post--]);
        root->right = buildTreeHelper(inorder, postorder, root->val);
        root->left = buildTreeHelper(inorder, postorder, stop);
        return root;
    }
};

RUN_TESTCASE(ConstructBinaryTree)
{
    SolutionConstructBinaryTree sln;
    std::vector<int> arr1 = {9,3,15,20,7};
    std::vector<int> arr2 = {9,15,7,20,3};
    std::vector<int> result = {3,9,20,-1,-1,15,7};
    TreeNode* tree = sln.buildTree(arr1, arr2);
    sln.PrintTree(tree);
    TESTCASE_ASSERT(sln.TreeEqual(tree, result));
    sln.FreeTree(tree);
}
