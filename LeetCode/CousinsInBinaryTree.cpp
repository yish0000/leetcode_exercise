#include "TestCase.h"
#include "BinaryTreeCommon.h"

using namespace std;

class SolutionCousinsInBinaryTree : public BinaryTreeCommmon
{
public:
	int d1 = 0, d2 = 0;
	TreeNode* p1 = nullptr;
	TreeNode* p2 = nullptr;
	bool isCousins(TreeNode* root, int x, int y) {
		d1 = d2 = 0;
		p1 = p2 = nullptr;
		searchNode(nullptr, root, x, y, 0);
		return d1 == d2 && p1 != p2;
	}

	void searchNode(TreeNode* parent, TreeNode* node, int x, int y, int depth)
	{
		if (!node) return;
		if (!p1 && node->val == x)
		{
			p1 = parent;
			d1 = depth;
		}
		if (!p2 && node->val == y)
		{
			p2 = parent;
			d2 = depth;
		}
		if (p1 && p2)
			return;
		searchNode(node, node->left, x, y, depth + 1);
		searchNode(node, node->right, x, y, depth + 1);
	}
};

RUN_TESTCASE(CousinsInBinaryTree)
{
	SolutionCousinsInBinaryTree sln;

	vector<string> arr1 = { "1","2","3","4" };
	TreeNode* tr1 = sln.MakeTree(arr1);
	TESTCASE_ASSERT(!sln.isCousins(tr1, 4, 3));
	sln.FreeTree(tr1);

	vector<string> arr2 = { "1","2","3","null","4","null","5" };
	TreeNode* tr2 = sln.MakeTree(arr2);
	TESTCASE_ASSERT(sln.isCousins(tr2, 5, 4));
	sln.FreeTree(tr2);

	vector<string> arr3 = { "1","2","3","null","4" };
	TreeNode* tr3 = sln.MakeTree(arr3);
	TESTCASE_ASSERT(!sln.isCousins(tr3, 2, 3));
	sln.FreeTree(tr3);
}