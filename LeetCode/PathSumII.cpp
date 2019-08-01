#include "TestCase.h"
#include "BinaryTreeCommon.h"

using namespace std;

class SolutionPathSumII : public BinaryTreeCommmon
{
public:
	int target;
	vector<vector<int>> result;

	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<int> path;
		if (!root) return result;
		target = sum;

		int cur = root->val;
		path.push_back(root->val);
		pathSumBacktrace(path, root, cur);
		return result;
	}

	void pathSumBacktrace(vector<int>& path, TreeNode* node, int& cur)
	{
		if (!node)
			return;

		if (!node->left && !node->right)
		{
			if (cur == target)
				result.push_back(path);
			return;
		}

		if (node->left)
		{
			path.push_back(node->left->val);
			cur += node->left->val;
			pathSumBacktrace(path, node->left, cur);
			cur -= node->left->val;
			path.pop_back();
		}

		if (node->right)
		{
			path.push_back(node->right->val);
			cur += node->right->val;
			pathSumBacktrace(path, node->right, cur);
			cur -= node->right->val;
			path.pop_back();
		}
	}
};

RUN_TESTCASE(PathSumII)
{
	SolutionPathSumII sln;

	vector<int> tree = { 5,4,8,11,-1,13,4,7,2,-1,-1,5,1 };
	TreeNode* root = sln.MakeTree(tree);
	vector<vector<int>> res = {
		{5,4,11,2},
		{5,8,4,5},
	};
	vector<vector<int>> ret = sln.pathSum(root, 22);
	TESTCASE_ASSERT(ret == res);
	sln.FreeTree(root);
}