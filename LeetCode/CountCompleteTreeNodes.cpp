#include "TestCase.h"
#include "BinaryTreeCommon.h"

using namespace std;

class SolutionCountCompleteTreeNodes : public BinaryTreeCommmon
{
public:
    int countNodes(TreeNode* root) {
        int count = 0;
        helper(root, count);
        return count;
    }
    
    void helper(TreeNode* root, int& count)
    {
        if (!root)
            return;
        
        count++;
        
        if (root->left)
            helper(root->left, count);
        if (root->right)
            helper(root->right, count);
    }
};

RUN_TESTCASE(CountCompleteTreeNodes)
{
    SolutionCountCompleteTreeNodes sln;
    
    vector<string> arr1 = {"1","2","3","4","5","6"};
    TreeNode* tr1 = sln.MakeTree(arr1);
    TESTCASE_ASSERT(sln.countNodes(tr1) == 6);
    sln.FreeTree(tr1);
}
