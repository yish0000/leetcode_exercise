#include "TestCase.h"
#include "BinaryTreeCommon.h"

using namespace std;

class SolutionSumRootToLeafNumbers : public BinaryTreeCommmon
{
public:
	int sumNumbers(TreeNode* root) {
		int sum = 0;
		vector<int> path;
		sumNumbers(root, sum, path);
		return sum;
	}

	void sumNumbers(TreeNode* node, int& sum, vector<int>& path)
	{
		if (!node)
			return;

		path.push_back(node->val);

		if (!node->left && !node->right)
		{
			int num = 0;
			int ten = 1;
			for (int i = 0; i < (int)path.size(); i++)
			{
				num += path[path.size() - 1 - i] * ten;
				if (i < 9) ten *= 10;
			}
			sum += num;
		}

		if (node->left)
			sumNumbers(node->left, sum, path);
		if (node->right)
			sumNumbers(node->right, sum, path);

		path.pop_back();
	}
};

RUN_TESTCASE(SumRootToLeafNumbers)
{
	SolutionSumRootToLeafNumbers sln;

	vector<string> arr1 = { "1","2","3" };
	TreeNode* tr1 = sln.MakeTree(arr1);
	TESTCASE_ASSERT(sln.sumNumbers(tr1) == 25);
	sln.FreeTree(tr1);

	vector<string> arr2 = { "4","9","0","5","1" };
	TreeNode* tr2 = sln.MakeTree(arr2);
	TESTCASE_ASSERT(sln.sumNumbers(tr2) == 1026);
	sln.FreeTree(tr2);
}