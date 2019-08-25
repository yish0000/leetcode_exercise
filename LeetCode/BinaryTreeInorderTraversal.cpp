#include "TestCase.h"
#include "BinaryTreeCommon.h"

using namespace std;

class SolutionBinaryTreeInorderTraversal : public BinaryTreeCommmon
{
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> arr;
		inorderTraversalInner(root, arr);
		return arr;
	}

	void inorderTraversalInner(TreeNode* root, vector<int>& arr)
	{
		if (!root) return;
		inorderTraversalInner(root->left, arr);
		arr.push_back(root->val);
		inorderTraversalInner(root->right, arr);
	}
};

RUN_TESTCASE(BinaryTreeInorderTraversal)
{
	SolutionBinaryTreeInorderTraversal sln;
	vector<int> inputs = {1,2,3,4,5,6,7,-1,-1,-1,-1,8,9,10,11};
	TreeNode* treeNode = sln.MakeTree(inputs);
	vector<int> results = sln.inorderTraversal(treeNode);
	vector<int> results2 = { 4,2,5,1,8,6,9,3,10,7,11 };
	TESTCASE_ASSERT(results == results2);
	sln.FreeTree(treeNode);
}
