#include "TestCase.h"
#include "BinaryTreeCommon.h"

using namespace std;

class SolutionConstructBinaryTreeFromPreIn : public BinaryTreeCommmon
{
public:
	int pre;
	int in;

public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.empty() || inorder.empty())
			return nullptr;

		pre = 0;
		in = 0;

		TreeNode* root = buildTreeHelper(preorder, inorder, std::numeric_limits<int>::min());
		return root;
	}

	TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int stop)
	{
		if (pre >= preorder.size())
			return nullptr;

		if (stop == inorder[in])
		{
			in++;
			return nullptr;
		}

		TreeNode* root = new TreeNode(preorder[pre++]);
		root->left = buildTreeHelper(preorder, inorder, root->val);
		root->right = buildTreeHelper(preorder, inorder, stop);
		return root;
	}
};

RUN_TESTCASE(ConstructBinaryTreeFromPreIn)
{
	SolutionConstructBinaryTreeFromPreIn sln;

	vector<int> preorder = { 3,9,20,15,7 };
	vector<int> inorder = { 9,3,15,20,7 };
	vector<string> ret = { "3","9","20","null","null","15","7" };
	TreeNode* tr1 = sln.buildTree(preorder, inorder);
	TESTCASE_ASSERT(sln.TreeEqual(tr1, ret));
	sln.FreeTree(tr1);
}