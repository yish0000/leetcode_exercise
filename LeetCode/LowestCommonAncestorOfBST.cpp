#include "TestCase.h"
#include "BinaryTreeCommon.h"
#include <stack>

using namespace std;

class SolutionLowestCommonAncestorOfBST : public BinaryTreeCommmon
{
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		TreeNode* lca = nullptr;
		searchNode(root, p, q, lca);
		return lca;
	}

	void searchNode(TreeNode* node, TreeNode* p, TreeNode* q, TreeNode*& lca)
	{
		if (!node)
			return;
		if (lca)
			return;

		if (p->val > node->val && q->val > node->val)
			searchNode(node->right, p, q, lca);
		if (p->val < node->val && q->val < node->val)
			searchNode(node->left, p, q, lca);
		if (!lca)
			lca = node;
	}
};

RUN_TESTCASE(LowestCommonAncestorOfBST)
{
	SolutionLowestCommonAncestorOfBST sln;

	vector<string> arr1 = { "6","2","8","0","4","7","9","null","null","3","5" };
	TreeNode* tr1 = sln.MakeTree(arr1);
	TESTCASE_ASSERT(sln.lowestCommonAncestor(tr1, tr1->left, tr1->right) == tr1);
	TESTCASE_ASSERT(sln.lowestCommonAncestor(tr1, tr1->left, tr1->left->right) == tr1->left);
	TESTCASE_ASSERT(sln.lowestCommonAncestor(tr1, tr1->left->left, tr1->left->right->left) == tr1->left);
	sln.FreeTree(tr1);
}