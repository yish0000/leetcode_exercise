#include "TestCase.h"
#include "BinaryTreeCommon.h"

using namespace std;

class SolutionRecoverBinarySearchTree : public BinaryTreeCommmon
{
public:
	TreeNode* first = nullptr;
	TreeNode* second = nullptr;
	TreeNode* prev = nullptr;
	void recoverTree(TreeNode* root) {
		first = second = prev = nullptr;
		traverse(root);

		if (first && second)
			std::swap(first->val, second->val);
	}

	void traverse(TreeNode* node)
	{
		if (!node)
			return;

		traverse(node->left);

		if (node && prev && node->val < prev->val)
		{
			if (!first)
			{
				first = prev;
				second = node;
			}
			else
				second = node;
		}

		prev = node;
		traverse(node->right);
	}
};

RUN_TESTCASE(RecoverBinarySearchTree)
{
	SolutionRecoverBinarySearchTree sln;

	vector<string> arr1 = { "1","3","null","null","2" };
	vector<string> ret1 = { "3","1","null","null","2" };
	TreeNode* tr1 = sln.MakeTree(arr1);
	sln.recoverTree(tr1);
	TESTCASE_ASSERT(sln.TreeEqual(tr1, ret1));
	sln.FreeTree(tr1);

	vector<string> arr2 = { "3","1","4","null","null","2" };
	vector<string> ret2 = { "2","1","4","null","null","3","null" };
	TreeNode* tr2 = sln.MakeTree(arr2);
	sln.recoverTree(tr2);
	TESTCASE_ASSERT(sln.TreeEqual(tr2, ret2));
	sln.FreeTree(tr2);
}