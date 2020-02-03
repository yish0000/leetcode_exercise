#include "TestCase.h"
#include "BinaryTreeCommon.h"

using namespace std;

class SolutionUniqueBinarySearchTreesII : public BinaryTreeCommmon
{
public:
	vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode*> list;
		if (n <= 0) return list;
		genTreesHelper(list, 1, n);
		return list;
	}

	void genTreesHelper(vector<TreeNode*>& list, int s, int e)
	{
		if (s >= e)
		{
			list.push_back(new TreeNode(s));
			return;
		}

		for (int i = s; i <= e; i++)
		{
			vector<TreeNode*> leftList;
			vector<TreeNode*> rightList;

			if (i == s)
				genTreesHelper(rightList, s + 1, e);
			else if (i == e)
				genTreesHelper(leftList, s, e - 1);
			else
			{
				genTreesHelper(leftList, s, i - 1);
				genTreesHelper(rightList, i + 1, e);
			}

			if (leftList.size() && rightList.size())
			{
				for (auto lnode : leftList)
				{
					for (auto rnode : rightList)
					{
						TreeNode* pNode = new TreeNode(i);
						pNode->left = lnode;
						pNode->right = rnode;
						list.emplace_back(pNode);
					}
				}
			}
			else
			{
				for (auto node : leftList)
				{
					TreeNode* pNode = new TreeNode(i);
					pNode->left = node;
					list.emplace_back(pNode);
				}

				for (auto node : rightList)
				{
					TreeNode* pNode = new TreeNode(i);
					pNode->right = node;
					list.emplace_back(pNode);
				}
			}
		}
	}
};

RUN_TESTCASE(UniqueBinarySearchTreesII)
{
	SolutionUniqueBinarySearchTreesII sln;

	vector<vector<string>> res1 = {
		{"1","null","2","null","null","null","3"},
		{"1","null","3","null","null","2","null"},
		{"2","1","3"},
		{"3","1","null","null","2","null","null"},
		{"3","2","null","1","null","null","null"},
	};

	vector<TreeNode*> trees = sln.generateTrees(3);
	TESTCASE_ASSERT(trees.size() == res1.size())
	for (size_t i = 0; i < trees.size(); i++)
	{
		TESTCASE_ASSERT(sln.TreeEqual(trees[i], res1[i]));
	}

	for (auto node : trees)
		sln.FreeTree(node);

	TESTCASE_ASSERT(!"Use DP for this problem again!");
}