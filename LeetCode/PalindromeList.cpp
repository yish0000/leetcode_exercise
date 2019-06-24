#include <iostream>
#include <vector>
#include "TestCase.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	bool isPalindrome(ListNode* head) {
		if (!head) return false;
		ListNode* pMiddle = head;
		ListNode* pCur = head;
		while (pCur && pCur->next)
		{
			pCur = pCur->next->next;
			if (!pCur) break;
			pMiddle = pMiddle->next;
		}

		ListNode* ptr1 = pMiddle->next, *ptr2 = pMiddle;
		ptr2->next = NULL;
		while (ptr1)
		{
			ListNode* next = ptr1->next;
			ptr1->next = ptr2;
			ptr2 = ptr1;
			ptr1 = next;
		}

		ptr1 = head;
		while (ptr1)
		{
			if (ptr1->val != ptr2->val)
				return false;
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}

		return true;
	}

	bool isPalindromeNormal(ListNode* head) {
		std::vector<int> arr;
		ListNode* pCur = head;
		while (pCur)
		{
			arr.push_back(pCur->val);
			pCur = pCur->next;
		}
		int s = 0, e = arr.size() - 1;
		while (s < e)
		{
			if (arr[s] != arr[e])
				return false;
			s++;
			e--;
		}
		return true;
	}

	ListNode* BuildList(const std::vector<int>& arr)
	{
		ListNode* pHead = NULL;
		ListNode* pCur = NULL;
		for (int i = 0; i < (int)arr.size(); i++)
		{
			if (!pHead)
			{
				pHead = new ListNode(arr[i]);
				pCur = pHead;
			}
			else
			{
				pCur->next = new ListNode(arr[i]);
				pCur = pCur->next;
			}
		}
		return pHead;
	}

	void FreeList(ListNode* pHead)
	{
		ListNode* pCur = pHead;
		while (pCur)
		{
			ListNode* pNext = pCur->next;
			delete pCur;
			pCur = pNext;
		}
	}
};

RUN_TESTCASE(PalindromeList)
{
	Solution sln;
	ListNode* pList1 = sln.BuildList({ 8,6,7,1,1,7,6,8 });
	TESTCASE_ASSERT(sln.isPalindrome(pList1));
	sln.FreeList(pList1);
	ListNode* pList2 = sln.BuildList({ 8,8,6,6,9,8,3 });
	TESTCASE_ASSERT(!sln.isPalindrome(pList2));
	sln.FreeList(pList2);
	ListNode* pList3 = sln.BuildList({ 8 });
	TESTCASE_ASSERT(sln.isPalindrome(pList3));
	sln.FreeList(pList3);
}