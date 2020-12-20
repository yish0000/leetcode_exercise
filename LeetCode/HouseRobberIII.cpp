#include "TestCase.h"
#include "BinaryTreeCommon.h"
#include <unordered_map>

using namespace std;

class SolutionHouseRobberIII : public BinaryTreeCommmon
{
public:
	unordered_map<TreeNode*, int> h;
	int rob(TreeNode* root) {
		h.clear();
		return maxValue(root);
	}

	int maxValue(TreeNode* node)
	{
		if (!node)
			return 0;

		if (h.find(node) != h.end())
			return h[node];

		// 包含根节点
		int v1 = node->val + 
			(node->left ? (maxValue(node->left->left) + maxValue(node->left->right)) : 0) +
			(node->right ? (maxValue(node->right->left) + maxValue(node->right->right)) : 0);
		// 不包含根节点
		int v2 = maxValue(node->left) + maxValue(node->right);
		h[node] = std::max(v1, v2);
		return h[node];
	}
};

RUN_TESTCASE(HouseRobberIII)
{
	SolutionHouseRobberIII sln;

	vector<string> arr1 = { "3","2","3","null","3","null","1" };
	TreeNode* tr1 = sln.MakeTree(arr1);
	TESTCASE_ASSERT(sln.rob(tr1) == 7);
	sln.FreeTree(tr1);

	vector<string> arr2 = { "3","4","5","1","3","null","1" };
	TreeNode* tr2 = sln.MakeTree(arr2);
	TESTCASE_ASSERT(sln.rob(tr2) == 9);
	sln.FreeTree(tr2);

	vector<string> arr3 = { "4","2","null","1","3" };
	TreeNode* tr3 = sln.MakeTree(arr3);
	TESTCASE_ASSERT(sln.rob(tr3) == 8);
	sln.FreeTree(tr3);
}