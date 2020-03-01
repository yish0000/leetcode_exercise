#include "TestCase.h"
#include "BinaryTreeCommon.h"

using namespace std;

class SolutionInvertBinaryTree : public BinaryTreeCommmon
{
public:
	TreeNode* invertTree(TreeNode* root) {
		if (!root)
			return root;

		std::swap(root->left, root->right);

		if (root->left)
			invertTree(root->left);
		if (root->right)
			invertTree(root->right);

		return root;
	}
};

RUN_TESTCASE(InvertBinaryTree)
{
	SolutionInvertBinaryTree sln;

	vector<string> arr1 = { "4","2","7","1","3","6","9" };
	vector<string> ret1 = { "4","7","2","9","6","3","1" };
	TreeNode* tr1 = sln.MakeTree(arr1);
	sln.invertTree(tr1);
	TESTCASE_ASSERT(sln.TreeEqual(tr1, ret1));
	sln.FreeTree(tr1);

	vector<string> arr2 = { "1","2" };
	vector<string> ret2 = { "1","null","2" };
	TreeNode* tr2 = sln.MakeTree(arr2);
	sln.invertTree(tr2);
	TESTCASE_ASSERT(sln.TreeEqual(tr2, ret2));
	sln.FreeTree(tr2);
}