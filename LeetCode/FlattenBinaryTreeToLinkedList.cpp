#include "TestCase.h"
#include "BinaryTreeCommon.h"

using namespace std;

class SolutionFlattenBinaryTreeToLinkedList : public BinaryTreeCommmon
{
public:
	void flatten(TreeNode* root) {
		TreeNode* last;
		flattenNode(root, last);
	}

	void flattenNode(TreeNode* root, TreeNode*& last)
	{
		if (!root)
			return;

		TreeNode* lastL = nullptr;
		if (root->left)
			flattenNode(root->left, lastL);
		
		TreeNode* lastR = nullptr;
		if (root->right)
			flattenNode(root->right, lastR);

		if (root->left)
		{
			TreeNode* rightTmp = root->right;
			root->right = root->left;
			root->left = nullptr;
			lastL->right = rightTmp;
		}

		if (lastR)
			last = lastR;
		else if (lastL)
			last = lastL;
		else
			last = root;
	}
};

RUN_TESTCASE(FlattenBinaryTreeToLinkedList)
{
	SolutionFlattenBinaryTreeToLinkedList sln;

	vector<string> arr1 = { "1","2","5","3","4","null","6" };
	vector<string> ret1 = { "1","null","2","null","3","null","4","null","5","null","6" };
	TreeNode* tr1 = sln.MakeTree(arr1);
	sln.flatten(tr1);
	sln.PrintTree(tr1);
	TESTCASE_ASSERT(sln.TreeEqual(tr1, ret1));
	sln.FreeTree(tr1);
}