#include "TestCase.h"
#include "BinaryTreeCommon.h"
#include <stack>
#include <map>

using namespace std;

class BSTIterator
{
public:
	BSTIterator(TreeNode* root)
	{
		TreeNode* cur = root;
		while (cur)
		{
			nodes.push(cur);
			cur = cur->left;
		}
	}

	/** @return the next smallest number */
	int next() {
		TreeNode* node = nodes.top();
		nodes.pop();

		TreeNode* cur = node->right;
		while (cur)
		{
			nodes.push(cur);
			cur = cur->left;
		}

		return node->val;
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return nodes.size() > 0;
	}

private:
	stack<TreeNode*> nodes;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
RUN_TESTCASE(BinarySearchTreeIterator)
{
	BinaryTreeCommmon sln;
	vector<string> arr1 = { "7","3","15","null","null","9","20" };
	TreeNode* tr1 = sln.MakeTree(arr1);
	BSTIterator iterator(tr1);
	TESTCASE_ASSERT(iterator.next() == 3);    // return 3
	TESTCASE_ASSERT(iterator.next() == 7);    // return 7
	TESTCASE_ASSERT(iterator.hasNext()); // return true
	TESTCASE_ASSERT(iterator.next() == 9);    // return 9
	TESTCASE_ASSERT(iterator.hasNext()); // return true
	TESTCASE_ASSERT(iterator.next() == 15);    // return 15
	TESTCASE_ASSERT(iterator.hasNext()); // return true
	TESTCASE_ASSERT(iterator.next() == 20);    // return 20
	TESTCASE_ASSERT(!iterator.hasNext()); // return false
	sln.FreeTree(tr1);
}