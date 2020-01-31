#include "TestCase.h"
#include "BinaryTreeCommon.h"

using namespace std;

class SolutionMaxDepthOfBinaryTree : public BinaryTreeCommmon
{
public:
	int maxDepth(TreeNode* root) {
		if (!root)
			return 0;

		int l_depth = maxDepth(root->left);
		int r_depth = maxDepth(root->right);
		return std::max(l_depth, r_depth) + 1;
	}
};

RUN_TESTCASE(MaxDepthOfBinaryTree)
{
	SolutionMaxDepthOfBinaryTree sln;

	vector<string> arr1 = { "3","9","20","null","null","15","7" };
	TreeNode* tr1 = sln.MakeTree(arr1);
	TESTCASE_ASSERT(sln.maxDepth(tr1) == 3);
	sln.FreeTree(tr1);
}