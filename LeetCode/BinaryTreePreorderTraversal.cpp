#include "TestCase.h"
#include "BinaryTreeCommon.h"
#include <stack>

using namespace std;

class SolutionBinaryTreePreorderTraversal : public BinaryTreeCommmon
{
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> arr;
		preorderTraversalInner(root, arr);
		return arr;
	}

	void preorderTraversalInner(TreeNode* root, vector<int>& arr)
	{
		if (!root) return;
		arr.push_back(root->val);
		preorderTraversalInner(root->left, arr);
		preorderTraversalInner(root->right, arr);
	}

	vector<int> preorderTraversalIterative(TreeNode* root)
	{
		vector<int> arr;

		stack<TreeNode*> q;
		if (root) q.push(root);
		while (q.size() > 0)
		{
			TreeNode* node = q.top();
			q.pop();

			arr.push_back(node->val);

			if (node->right)
				q.push(node->right);
			if (node->left)
				q.push(node->left);
		}

		return arr;
	}
};

RUN_TESTCASE(BinaryTreePreorderTraversal)
{
	SolutionBinaryTreePreorderTraversal sln;
	vector<string> inputs = { "1","2","3","4","5","6","7","null","null","null","null","8","9","10","11" };
	TreeNode* treeNode = sln.MakeTree(inputs);
	vector<int> results = sln.preorderTraversalIterative(treeNode);
	vector<int> results2 = { 1, 2, 4, 5, 3, 6, 8, 9, 7, 10, 11 };
	TESTCASE_ASSERT(results == results2);
	sln.FreeTree(treeNode);
}