#include "TestCase.h"
#include "BinaryTreeCommon.h"
#include <queue>
#include <stack>

using namespace std;

class SolutionBinaryTreeZigzagLevelOrderTraversal : public BinaryTreeCommmon
{
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> arr;
		bool is_reverse = false;
		queue<TreeNode*> q;
		if (root) q.push(root);
		while (q.size() > 0)
		{
			int count = (int)q.size();
			arr.push_back(vector<int>());
			for (int i = 0; i < count; i++)
			{
				TreeNode* item = q.front();
				q.pop();
				arr.back().push_back(item->val);

				if (item->left)
					q.push(item->left);
				if (item->right)
					q.push(item->right);
			}
			if (is_reverse)
				std::reverse(arr.back().begin(), arr.back().end());
			is_reverse = !is_reverse;
		}
		return arr;
	}
};

RUN_TESTCASE(BinaryTreeZigzagLevelOrderTraversal)
{
	SolutionBinaryTreeZigzagLevelOrderTraversal sln;

	vector<string> arr1 = { "3","9","20","null","null","15","7" };
	vector<vector<int>> ret1 = {
		{3},
		{20,9},
		{15,7}
	};
	TreeNode* tr1 = sln.MakeTree(arr1);
	TESTCASE_ASSERT(sln.zigzagLevelOrder(tr1) == ret1);
	sln.FreeTree(tr1);

	vector<string> arr2 = { "1","2","3","4","null","null","5", "6", "7", "8", "9"};
	vector<vector<int>> ret2 = {
		{1},
		{3,2},
		{4,5},
		{9,8,7,6},
	};
	TreeNode* tr2 = sln.MakeTree(arr2);
	TESTCASE_ASSERT(sln.zigzagLevelOrder(tr2) == ret2);
	sln.FreeTree(tr2);
}