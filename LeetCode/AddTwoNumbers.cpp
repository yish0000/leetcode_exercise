#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
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
			return new ListNode(0);
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

		return first;
	}

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
};

void Test_AddTwoNumbers()
{
	Solution sln;
	int num1 = 786;
	int num2 = 823;
	ListNode* l1 = sln.BuildList(num1);
	ListNode* l2 = sln.BuildList(num2);
	ListNode* ret = sln.addTwoNumbers(l1, l2);
	sln.FreeList(l1);
	sln.FreeList(l2);
	sln.FreeList(ret);
}