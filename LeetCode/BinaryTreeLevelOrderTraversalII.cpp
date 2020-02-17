#include "TestCase.h"
#include "BinaryTreeCommon.h"

using namespace std;

class SolutionBinaryTreeLevelOrderTraversalII : public BinaryTreeCommmon
{
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> arr;
		levelOrderBottom2(arr, root, 0);

		int l = 0, r = (int)arr.size() - 1;
		while (l < r) std::swap(arr[l++], arr[r--]);
		return arr;
	}

	void levelOrderBottom2(vector<vector<int>>& out, TreeNode* node, int depth)
	{
		if (!node)
			return;

		if (depth >= (int)out.size())
			out.push_back(vector<int>());

		out[depth].push_back(node->val);

		if (node->left)
			levelOrderBottom2(out, node->left, depth + 1);
		if (node->right)
			levelOrderBottom2(out, node->right, depth + 1);
	}
};

RUN_TESTCASE(BinaryTreeLevelOrderTraversalII)
{
	SolutionBinaryTreeLevelOrderTraversalII sln;

	vector<string> arr1 = { "3","9","20","null","null","15","7" };
	vector<vector<int>> ret1 = {
		{15, 7},
		{9, 20},
		{3},
	};
	TreeNode* tr1 = sln.MakeTree(arr1);
	TESTCASE_ASSERT(sln.levelOrderBottom(tr1) == ret1);
	sln.FreeTree(tr1);
}