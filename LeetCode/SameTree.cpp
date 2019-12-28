#include "TestCase.h"
#include "BinaryTreeCommon.h"

using namespace std;

class SolutionSameTree : public BinaryTreeCommmon
{
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

RUN_TESTCASE(SameTree)
{
    SolutionSameTree sln;
    
	vector<string> arr1 = { "1","2","3" };
    TreeNode* t1 = sln.MakeTree(arr1);
    TreeNode* t2 = sln.MakeTree(arr1);
    TESTCASE_ASSERT(sln.isSameTree(t1, t2));
    sln.FreeTree(t1);
    sln.FreeTree(t2);
    
	vector<string> arr2 = { "1","2" };
    TreeNode* t3 = sln.MakeTree(arr2);
	vector<string> arr3 = { "1","-2","2" };
    TreeNode* t4 = sln.MakeTree(arr3);
    TESTCASE_ASSERT(!sln.isSameTree(t3, t4));
    sln.FreeTree(t3);
    sln.FreeTree(t4);
}
