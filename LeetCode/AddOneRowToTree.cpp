#include "TestCase.h"
#include "BinaryTreeCommon.h"

using namespace std;

class SolutionAddOneRowToTree : public BinaryTreeCommmon
{
public:
	TreeNode* addOneRow(TreeNode* root, int v, int d) {
		if (d == 1)
		{
			TreeNode* newRoot = new TreeNode(v);
			newRoot->left = root;
			return newRoot;
		}
		else
		{
			addOneRowHelper(root, NULL, v, d, false);
			return root;
		}
	}

	void addOneRowHelper(TreeNode* root, TreeNode* parent, int v, int d, bool bLeft)
	{
		if (d > 1)
		{
			if (!root) return;
			addOneRowHelper(root->left, root, v, d - 1, true);
			addOneRowHelper(root->right, root, v, d - 1, false);
		}
		else
		{
			TreeNode* newRoot = new TreeNode(v);
			if (bLeft)
			{
				newRoot->left = root;
				parent->left = newRoot;
			}
			else
			{
				newRoot->right = root;
				parent->right = newRoot;
			}
		}
	}
};

RUN_TESTCASE(AddOneRowToTree)
{
	SolutionAddOneRowToTree sln;

	vector<string> arr1 = { "4","2","6","3","1","5","null" };
	vector<string> res1 = { "4","1","1","2","null","null","6","3","1","null","null","null","null","5","null" };
	TreeNode* tree1 = sln.MakeTree(arr1);
	tree1 = sln.addOneRow(tree1, 1, 2);
	TESTCASE_ASSERT(sln.TreeEqual(tree1, res1));
	sln.FreeTree(tree1);

	vector<string> arr2 = { "4","2","null","3","1","null","null" };
	vector<string> res2 = { "4","2","null","1","1","null","null","3","null","null","1","null","null","null","null" };
	TreeNode* tree2 = sln.MakeTree(arr2);
	tree2 = sln.addOneRow(tree2, 1, 3);
	TESTCASE_ASSERT(sln.TreeEqual(tree2, res2));
	sln.FreeTree(tree2);

	vector<string> arr3 = { "1","2","3","4" };
	vector<string> res3 = { "1","2","3","4","null","null","null","5","5","null","null","null","null","null","null" };
	TreeNode* tree3 = sln.MakeTree(arr3);
	tree3 = sln.addOneRow(tree3, 5, 4);
	TESTCASE_ASSERT(sln.TreeEqual(tree3, res3));
	sln.FreeTree(tree3);
}