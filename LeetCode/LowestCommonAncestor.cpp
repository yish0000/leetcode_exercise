#include "TestCase.h"
#include "BinaryTreeCommon.h"
#include <set>

using namespace std;

class SolutionLowestCommonAncestor : public BinaryTreeCommmon
{
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (checkNode(root, p, q))
			return res;
		else
			return nullptr;
	}

	bool checkNode(TreeNode* node, TreeNode* p, TreeNode* q)
	{
		if (!node) return false;
		int l = checkNode(node->left, p, q) ? 1 : 0;
		int r = checkNode(node->right, p, q) ? 1 : 0;
		int mid = (node == p || node == q) ? 1 : 0;
		if (mid + l + r >= 2)
			res = node;
		return mid + l + r > 0;
	}

	TreeNode* res = nullptr;
};

RUN_TESTCASE(LowestCommonAncestor)
{
	SolutionLowestCommonAncestor sln;

	vector<string> arr = { "3","5","1","6","2","0","8","null","null","7","4" };
	TreeNode* root = sln.MakeTree(arr);
	TESTCASE_ASSERT(sln.lowestCommonAncestor(root, root->left, root->right) == root);

	TreeNode* p = root->left;
	TreeNode* q = p->right->right;
	TESTCASE_ASSERT(sln.lowestCommonAncestor(root, p, q) == p);

	p = root->left->left;
	q = root->left->right->right;
	TESTCASE_ASSERT(sln.lowestCommonAncestor(root, p, q) == root->left);
}