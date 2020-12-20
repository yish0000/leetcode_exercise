#include "TestCase.h"
#include "BinaryTreeCommon.h"
#include <unordered_map>
#include <queue>

using namespace std;

class SolutionHouseRobberIII : public BinaryTreeCommmon
{
public:
	unordered_map<TreeNode*, int> h;
	int rob(TreeNode* root) {
		//h.clear();
		//return maxValue(root);
		return rob_dp(root);
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

	int rob_dp(TreeNode* root)
	{
		unordered_map<TreeNode*, int> node2Index;
		vector<TreeNode*> nodeList;
		queue<TreeNode*> q;
		q.push(root);
		while (q.size() > 0)
		{
			TreeNode* child = q.front();
			q.pop();
			node2Index[child] = (int)nodeList.size();
			nodeList.push_back(child);
			if (child->left)
				q.push(child->left);
			if (child->right)
				q.push(child->right);
		}

		vector<int> dp_rob(node2Index.size(), 0);
		vector<int> dp_not_rob(node2Index.size(), 0);
		for (int i = (int)node2Index.size() - 1; i >= 0; i--)
		{
			TreeNode* node = nodeList[i];
			if (!node->left && !node->right)
			{
				dp_rob[i] = node->val;
				dp_not_rob[i] = 0;
			}
			else
			{
				dp_rob[i] = node->val;
				if (node->left)
				{
					int index = node2Index[node->left];
					dp_rob[i] += dp_not_rob[index];
					dp_not_rob[i] += std::max(dp_rob[index], dp_not_rob[index]);
				}
				if (node->right)
				{
					int index = node2Index[node->right];
					dp_rob[i] += dp_not_rob[index];
					dp_not_rob[i] += std::max(dp_rob[index], dp_not_rob[index]);
				}
			}
		}

		return std::max(dp_rob[0], dp_not_rob[0]);
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