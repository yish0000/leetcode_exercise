#include "TestCase.h"
#include "BinaryTreeCommon.h"

using namespace std;

class SolutionSortedArrayToBST : public BinaryTreeCommmon
{
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		TreeNode* root = nullptr;
		sortedArrayToBST2(root, nums, 0, (int)nums.size() - 1);
		return root;
	}

	void sortedArrayToBST2(TreeNode*& node, vector<int>& nums, int beg, int end)
	{
		if (beg > end)
			return;

		int mid = beg + (end - beg) / 2;
		node = new TreeNode(nums[mid]);
		sortedArrayToBST2(node->left, nums, beg, mid - 1);
		sortedArrayToBST2(node->right, nums, mid + 1, end);
	}
};

RUN_TESTCASE(SortedArrayToBST)
{
	SolutionSortedArrayToBST sln;

	vector<int> arr1 = { -10,-3,0,5,9 };
	vector<string> ret1 = { "0","-10","5","null","-3","null","9" };
	TreeNode* tr1 = sln.sortedArrayToBST(arr1);
	TESTCASE_ASSERT(sln.TreeEqual(tr1, ret1));
	sln.FreeTree(tr1);
}