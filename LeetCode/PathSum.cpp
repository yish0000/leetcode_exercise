#include "TestCase.h"
#include "BinaryTreeCommon.h"

using namespace std;

class SolutionPathSum : public BinaryTreeCommmon
{
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (!root)
			return false;

		int num = 0;
		return hasPathSum2(root, num, sum);
	}

	bool hasPathSum2(TreeNode* root, int& sum, int target)
	{
		sum += root->val;
		if (!root->left && !root->right)
		{
			if (sum == target)
				return true;
		}
		if (root->left)
		{
			if (hasPathSum2(root->left, sum, target))
				return true;
		}
		if (root->right)
		{
			if (hasPathSum2(root->right, sum, target))
				return true;
		}
		sum -= root->val;
		return false;
	}
};

RUN_TESTCASE(PathSum)
{
	SolutionPathSum sln;

	vector<string> arr1 = { "5","4","8","11","null","13","4","7","2","null","null","null","1" };
	TreeNode* tr1 = sln.MakeTree(arr1);
	TESTCASE_ASSERT(sln.hasPathSum(tr1, 22));
	sln.FreeTree(tr1);

	vector<string> arr2 = { "1","2","3","4","null","null","5" };
	TreeNode* tr2 = sln.MakeTree(arr2);
	TESTCASE_ASSERT(sln.hasPathSum(tr2, 7));
	sln.FreeTree(tr2);
}