#include "TestCase.h"
#include "BinaryTreeCommon.h"
#include <queue>

using namespace std;

class SolutionBinaryTreeRightSideView : public BinaryTreeCommmon
{
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> arr;
		if (!root) return arr;

		queue<TreeNode*> q;
		q.push(root);
		while (q.size() > 0)
		{
			int count = (int)q.size();
			for (int i = 0; i < count; i++)
			{
				TreeNode* item = q.front();
				q.pop();

				if (i == count - 1)
					arr.push_back(item->val);

				if (item->left)
					q.push(item->left);
				if (item->right)
					q.push(item->right);
			}
		}

		return arr;
	}

	vector<int> rightSideViewDFS(TreeNode* root) {
		vector<int> arr;
		dfs(root, arr, 0);
		return arr;
	}

	void dfs(TreeNode* node, vector<int>& arr, int level)
	{
		if (!node)
			return;

		if (level == (int)arr.size())
			arr.push_back(node->val);

		dfs(node->right, arr, level + 1);
		dfs(node->left, arr, level + 1);
	}
};

RUN_TESTCASE(BinaryTreeRightSideView)
{
	SolutionBinaryTreeRightSideView sln;

	vector<string> arr1 = { "1","2","3","null","5","null","4" };
	vector<int> ret1 = { 1,3,4 };
	TreeNode* tr1 = sln.MakeTree(arr1);
	TESTCASE_ASSERT(sln.rightSideViewDFS(tr1) == ret1);
	sln.FreeTree(tr1);
}