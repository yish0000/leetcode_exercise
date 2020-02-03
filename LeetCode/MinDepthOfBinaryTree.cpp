#include "TestCase.h"
#include "BinaryTreeCommon.h"

using namespace std;

class SolutionMinDepthOfBinaryTree : public BinaryTreeCommmon
{
public:
	int minDepth(TreeNode* root) {
		if (!root)
			return 0;

		int depth = INT_MAX;
		minDepth2(root, depth, 1);
		return depth;
	}

	void minDepth2(TreeNode* node, int& min_depth, int depth)
	{
		if (!node->left && !node->right)
		{
			min_depth = std::min(min_depth, depth);
			return;
		}

		if (node->left)
			minDepth2(node->left, min_depth, depth + 1);
		if (node->right)
			minDepth2(node->right, min_depth, depth + 1);
	}
};

RUN_TESTCASE(MinDepthOfBinaryTree)
{
	SolutionMinDepthOfBinaryTree sln;

	vector<string> arr1 = { "3","9","20","null","null","15","7" };
	TreeNode* tr1 = sln.MakeTree(arr1);
	TESTCASE_ASSERT(sln.minDepth(tr1) == 2);
	sln.FreeTree(tr1);

	vector<string> arr2 = { "1","2","3","4","null","null","5" };
	TreeNode* tr2 = sln.MakeTree(arr2);
	TESTCASE_ASSERT(sln.minDepth(tr2) == 3);
	sln.FreeTree(tr2);
}