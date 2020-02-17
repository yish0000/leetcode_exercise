#include "TestCase.h"
#include "BinaryTreeCommon.h"

using namespace std;

class SolutionBalancedBinaryTree : public BinaryTreeCommmon
{
public:
	bool isBalanced(TreeNode* root) {
		int depth = 0;
		return isChildBalanced(root, depth);
	}

	bool isChildBalanced(TreeNode* node, int& depth)
	{
		if (!node)
			return true;

		int l_depth = 0;
		if (!isChildBalanced(node->left, l_depth))
			return false;

		int r_depth = 0;
		if (!isChildBalanced(node->right, r_depth))
			return false;

		depth = std::max(l_depth, r_depth) + 1;
		return abs(l_depth - r_depth) <= 1;
	}
};

RUN_TESTCASE(BalancedBinaryTree)
{
	SolutionBalancedBinaryTree sln;

	vector<string> arr1 = { "3","9","20","null","null","15","7" };
	TreeNode* tr1 = sln.MakeTree(arr1);
	TESTCASE_ASSERT(sln.isBalanced(tr1));
	sln.FreeTree(tr1);

	vector<string> arr2 = { "1","2","2","3","3","null","null","4","4","null","null","null","null","null","null" };
	TreeNode* tr2 = sln.MakeTree(arr2);
	TESTCASE_ASSERT(!sln.isBalanced(tr2));
	sln.FreeTree(tr2);
}