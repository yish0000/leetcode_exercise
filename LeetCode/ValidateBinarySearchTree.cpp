#include "TestCase.h"
#include "BinaryTreeCommon.h"

using namespace std;

class SolutionValidateBinarySearchTree : public BinaryTreeCommmon
{
public:
	bool isValidBST(TreeNode* root) {
		if (!root) return true;
		if (!root->left && !root->right) return true;

		int64_t maxValue = std::numeric_limits<int64_t>::min();
		return isValidBSTHelper(root, maxValue);
	}

	bool isValidBSTHelper(TreeNode* root, int64_t& maxValue)
	{
		if (!root) return true;
		if (!isValidBSTHelper(root->left, maxValue))
			return false;
		if (root->val > maxValue)
			maxValue = root->val;
		else
			return false;
		return isValidBSTHelper(root->right, maxValue);
	}
};

RUN_TESTCASE(ValidateBinarySearchTree)
{
	SolutionValidateBinarySearchTree sln;

	vector<string> arr1 = { "3","1","5","null","null","4","6" };
	TreeNode* tr1 = sln.MakeTree(arr1);
	TESTCASE_ASSERT(sln.isValidBST(tr1));
	sln.FreeTree(tr1);

	vector<string> arr2 = { "5","1","4","null","null","3","6" };
	TreeNode* tr2 = sln.MakeTree(arr2);
	TESTCASE_ASSERT(!sln.isValidBST(tr2));
	sln.FreeTree(tr2);

	vector<string> arr3 = { "-2147483648","null","2147483647" };
	TreeNode* tr3 = sln.MakeTree(arr3);
	TESTCASE_ASSERT(sln.isValidBST(tr3));
	sln.FreeTree(tr3);
}