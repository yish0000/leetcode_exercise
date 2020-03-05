#include "TestCase.h"
#include "BinaryTreeCommon.h"

using namespace std;

class SolutionRecoverBinarySearchTree : public BinaryTreeCommmon
{
public:
	void recoverTree(TreeNode* root) {
		vector<TreeNode*> v;
		traverse(v, root);

		int first = -1, second = -1;
		for (int i = 0; i < v.size(); i++)
		{
			if (i + 1 < v.size() && v[i + 1]->val < v[i]->val)
			{
				if (first == -1)
				{
					first = i;
					second = i + 1;
				}
				else
				{
					second = i + 1;
					break;
				}
			}
		}

		std::swap(v[first]->val, v[second]->val);
	}

	void traverse(vector<TreeNode*>& arr, TreeNode* node)
	{
		if (!node) return;
		traverse(arr, node->left);
		arr.push_back(node);
		traverse(arr, node->right);
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