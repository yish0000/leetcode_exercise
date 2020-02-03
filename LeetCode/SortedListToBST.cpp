#include "TestCase.h"
#include "BinaryTreeCommon.h"
#include "LinkedListCommon.h"

using namespace std;

class SolutionSortedListToBST : public BinaryTreeCommmon, public LinkedListCommon
{
public:
	TreeNode* sortedListToBST(ListNode* head) {
		int n = count(head);
		TreeNode* root = nullptr;
		sortedListToBST2(root, head, 0, n - 1);
		return root;
	}

	void sortedListToBST2(TreeNode*& node, ListNode* head, int beg, int end)
	{
		if (beg > end)
			return;

		int mid = beg + (end - beg) / 2;
		ListNode* center = next(head, mid);
		node = new TreeNode(center->val);
		sortedListToBST2(node->left, head, beg, mid - 1);
		sortedListToBST2(node->right, center->next, 0, end - mid - 1);
	}

	int count(ListNode* head)
	{
		int count = 0;
		ListNode* end = head;
		while (end)
		{
			count++;
			end = end->next;
		}
		return count;
	}

	ListNode* next(ListNode* node, int count)
	{
		while (node && count > 0)
		{
			node = node->next;
			count--;
		}

		return node;
	}
};

RUN_TESTCASE(SortedListToBST)
{
	SolutionSortedListToBST sln;

	vector<int> arr1 = { -10,-3,0,5,9 };
	vector<string> ret1 = { "0","-10","5","null","-3","null","9" };
	ListNode* l1 = sln.BuildList(arr1);
	TreeNode* tr1 = sln.sortedListToBST(l1);
	TESTCASE_ASSERT(sln.TreeEqual(tr1, ret1));
	sln.FreeTree(tr1);
	sln.FreeList(l1);
}