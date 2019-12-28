#include "TestCase.h"
#include "BinaryTreeCommon.h"

using namespace std;

class SolutionBinaryTreeMaxPathSum : public BinaryTreeCommmon
{
public:
	int maxPathSum(TreeNode* root) {
		int max_value = std::numeric_limits<int>::min();
		maxPathSumHelper(root, max_value);
		return max_value;
	}

	int maxPathSumHelper(TreeNode* root, int& max_value)
	{
		if (!root)
		{
			max_value = std::max(max_value, 0);
			return 0;
		}

		max_value = std::max(max_value, root->val);

		if (!root->left && !root->right)
			return root->val;

		int l_max = std::numeric_limits<int>::min();
		if (root->left)
		{
			l_max = maxPathSumHelper(root->left, max_value);
			max_value = std::max({
				max_value,
				(root->val > 0 ? root->val : 0) + l_max,
				});
		}

		int r_max = std::numeric_limits<int>::min();
		if (root->right)
		{
			r_max = maxPathSumHelper(root->right, max_value);
			max_value = std::max({
				max_value,
				(root->val > 0 ? root->val : 0) + r_max,
				});
		}

		if (root->left && root->right)
		{
			max_value = std::max({
				max_value,
				root->val + l_max + r_max
				});
		}

		return std::max({
			root->val,
			root->val + (root->left ? l_max : 0),
			root->val + (root->right ? r_max : 0)
		});
	}
};

RUN_TESTCASE(BinaryTreeMaxPathSum)
{
	SolutionBinaryTreeMaxPathSum sln;

	vector<string> arr1 = { "1","2","3" };
	TreeNode* tr1 = sln.MakeTree(arr1);
	TESTCASE_ASSERT(sln.maxPathSum(tr1) == 6);
	sln.FreeTree(tr1);

	vector<string> arr2 = { "-10","9","20","null","null","15","7" };
	TreeNode* tr2 = sln.MakeTree(arr2);
	TESTCASE_ASSERT(sln.maxPathSum(tr2) == 42);
	sln.FreeTree(tr2);

	vector<string> arr3 = { "1","2" };
	TreeNode* tr3 = sln.MakeTree(arr3);
	TESTCASE_ASSERT(sln.maxPathSum(tr3) == 3);
	sln.FreeTree(tr3);

	vector<string> arr4 = { "-2","-1" };
	TreeNode* tr4 = sln.MakeTree(arr4);
	TESTCASE_ASSERT(sln.maxPathSum(tr4) == -1);
	sln.FreeTree(tr4);

	vector<string> arr5 = { "-2","1" };
	TreeNode* tr5 = sln.MakeTree(arr5);
	TESTCASE_ASSERT(sln.maxPathSum(tr5) == 1);
	sln.FreeTree(tr5);
}