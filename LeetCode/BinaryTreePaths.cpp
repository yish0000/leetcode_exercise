#include "TestCase.h"
#include "BinaryTreeCommon.h"
#include <sstream>

using namespace std;

class SolutionBinaryTreePaths : public BinaryTreeCommmon
{
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> paths;
		vector<int> path;
		dfs(root, path, paths);
		return paths;
	}

	void dfs(TreeNode* node, vector<int>& path, vector<string>& out)
	{
		if (!node)
			return;
		path.push_back(node->val);
		if (!node->left && !node->right)
		{
			stringstream ss;
			for (int i = 0; i < path.size(); i++)
			{
				ss << path[i];
				if (i < (int)path.size() - 1)
					ss << "->";
			}
			out.push_back(ss.str());
		}
		else
		{
			if (node->left)
				dfs(node->left, path, out);
			if (node->right)
				dfs(node->right, path, out);
		}
		path.pop_back();
	}
};

RUN_TESTCASE(BinaryTreePaths)
{
	SolutionBinaryTreePaths sln;

	vector<string> arr1 = { "1","2","3","null","5" };
	TreeNode* tr1 = sln.MakeTree(arr1);
	vector<string> ret1 = { "1->2->5","1->3" };
	TESTCASE_ASSERT(sln.binaryTreePaths(tr1) == ret1);
	sln.FreeTree(tr1);
}