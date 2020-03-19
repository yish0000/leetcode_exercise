#include "TestCase.h"
#include "BinaryTreeCommon.h"
#include <stack>
#include <unordered_map>

using namespace std;

class SolutionBinaryTreePostorderTraversal : public BinaryTreeCommmon
{
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> arr;
		bfs(arr, root);
		return arr;
	}

	void dfs(vector<int>& out, TreeNode* node)
	{
		if (!node)
			return;
		dfs(out, node->left);
		dfs(out, node->right);
		out.push_back(node->val);
	}

	void bfs(vector<int>& out, TreeNode* node)
	{
		stack<pair<TreeNode*, bool>> s;
		while (true)
		{
			while (node)
			{
				s.push(std::make_pair(node, node->right == nullptr));
				node = node->left;
			}

			if (s.empty())
				break;

			pair<TreeNode*, bool>& item = s.top();
			if (!item.second)
			{
				node = item.first->right;
				item.second = true;
			}
			else
			{
				out.push_back(item.first->val);
				s.pop();
			}
		}
	}
};

RUN_TESTCASE(BinaryTreePostorderTraversal)
{
	SolutionBinaryTreePostorderTraversal sln;

	vector<string> arr1 = { "1","2","3","4","5","6","7","null","8","9","10","null","11" };
	vector<int> ret1 = { 8,4,9,10,5,2,11,6,7,3,1 };
	TreeNode* tr1 = sln.MakeTree(arr1);
	TESTCASE_ASSERT(sln.postorderTraversal(tr1) == ret1);
	sln.FreeTree(tr1);
}