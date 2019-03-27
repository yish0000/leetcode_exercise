#include "TestCase.h"
#include <vector>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
protected:
	std::vector<ListNode*> lists;

	void FreeList(ListNode* l)
	{
		ListNode* cur = l;
		while (cur)
		{
			ListNode* next = cur->next;
			free(cur);
			cur = next;
		}
	}

public:
	~Solution()
	{
		std::vector<ListNode*>::iterator it;
		for (it = lists.begin(); it != lists.end(); ++it)
			FreeList(*it);
	}

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int carry = 0;
		ListNode* ret = NULL;
		ListNode* cur1 = l1;
		ListNode* cur2 = l2;
		ListNode* cur = NULL;

		while (cur1 || cur2)
		{
			int curNum = (cur1 ? cur1->val : 0) + (cur2 ? cur2->val : 0) + carry;
			if (curNum >= 10)
			{
				carry = 1;
				curNum -= 10;
			}
			else
				carry = 0;

			ListNode* newNode = new ListNode(curNum);
			if (!cur)
			{
				ret = newNode;
				cur = newNode;
			}
			else
			{
				cur->next = newNode;
				cur = newNode;
			}

			cur1 = cur1 ? cur1->next : NULL;
			cur2 = cur2 ? cur2->next : NULL;
		}

		if (carry > 0)
		{
			ListNode* newNode = new ListNode(carry);
			if (!cur)
			{
				ret = newNode;
				cur = newNode;
			}
			else
			{
				cur->next = newNode;
				cur = newNode;
			}
		}

		return ret;
	}

	ListNode* BuildList(int number)
	{
		ListNode* first = NULL;
		ListNode* cur = NULL;
		if (number == 0)
			first = new ListNode(0);

		while (number > 0)
		{
			int curNum = number % 10;
			ListNode* newNode = new ListNode(curNum);
			if (!cur)
			{
				first = newNode;
				cur = newNode;
			}
			else
			{
				cur->next = newNode;
				cur = newNode;
			}

			number = number / 10;
		}

		lists.push_back(first);
		return first;
	}

	bool ListEqual(ListNode* l, int arr[])
	{
		int i = 0;
		ListNode* cur = l;
		while (cur)
		{
			if (cur->val != arr[i])
				return false;

			i++;
			cur = cur->next;
		}

		return true;
	}
};

RUN_TESTCASE(AddTwoNumbers)
{
	Solution sln;
	int num1 = 786;
	int num2 = 823;
	int result[] = { 9, 0, 6, 1 };
	ListNode* l1 = sln.BuildList(num1);
	ListNode* l2 = sln.BuildList(num2);
	ListNode* ret = sln.addTwoNumbers(l1, l2);
	TESTCASE_ASSERT(sln.ListEqual(ret, result));
}