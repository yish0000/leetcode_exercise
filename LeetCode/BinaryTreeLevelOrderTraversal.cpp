#include "TestCase.h"
#include "BinaryTreeCommon.h"

using namespace std;

class SolutionBinaryTreeLevelOrderTraversal : public BinaryTreeCommmon
{
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> arr;
		levelOrder2(arr, root, 0);
		return arr;
	}

	void levelOrder2(vector<vector<int>>& out, TreeNode* node, int depth)
	{
		if (!node)
			return;

		if (depth >= (int)out.size())
			out.push_back(vector<int>());

		out[depth].push_back(node->val);

		if (node->left)
			levelOrder2(out, node->left, depth + 1);
		if (node->right)
			levelOrder2(out, node->right, depth + 1);
	}
};

RUN_TESTCASE(BinaryTreeLevelOrderTraversal)
{
	SolutionBinaryTreeLevelOrderTraversal sln;

	vector<string> arr1 = { "3","9","20","null","null","15","7" };
	vector<vector<int>> ret1 = {
		{3},
		{9, 20},
		{15, 7},
	};
	TreeNode* tr1 = sln.MakeTree(arr1);
	TESTCASE_ASSERT(sln.levelOrder(tr1) == ret1);
	sln.FreeTree(tr1);
}