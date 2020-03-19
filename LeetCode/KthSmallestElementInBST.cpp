#include "TestCase.h"
#include "BinaryTreeCommon.h"

using namespace std;

class SolutionKthSmallestElementInBST : public BinaryTreeCommmon
{
public:
	int kthSmallest(TreeNode* root, int k) {
		int ret = 0;
		dfs(root, k, ret);
		return ret;
	}

	bool dfs(TreeNode* node, int& k, int& val)
	{
		if (!node)
			return false;

		if (dfs(node->left, k, val))
			return true;
		if (--k == 0)
		{
			val = node->val;
			return true;
		}
		return dfs(node->right, k, val);
	}
};

RUN_TESTCASE(KthSmallestElementInBST)
{
	SolutionKthSmallestElementInBST sln;

	vector<string> arr1 = { "3","1","4","null","2" };
	TreeNode* tr1 = sln.MakeTree(arr1);
	TESTCASE_ASSERT(sln.kthSmallest(tr1, 1) == 1);
	sln.FreeTree(tr1);

	vector<string> arr2 = { "5","3","6","2","4","null","null","1" };
	TreeNode* tr2 = sln.MakeTree(arr2);
	TESTCASE_ASSERT(sln.kthSmallest(tr2, 3) == 3);
	sln.FreeTree(tr2);
}