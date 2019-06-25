#include "TestCase.h"
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class SolutionReverseLinkedList
{
public:
	ListNode* reverseList(ListNode* head) {
		if (!head) return NULL;
		ListNode *ptr1 = head, *ptr2 = head->next;
		ptr1->next = NULL;
		while (ptr2)
		{
			ListNode* next = ptr2->next;
			ptr2->next = ptr1;
			ptr1 = ptr2;
			ptr2 = next;
		}
		return ptr1;
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

	bool ListEqual(ListNode* pHead, const std::vector<int>& arr)
	{
		size_t idx = 0;
		ListNode* pCur = pHead;
		while (pCur)
		{
			if (idx >= arr.size())
				return false;

			if (pCur->val != arr[idx])
				return false;
			pCur = pCur->next;
			idx++;
		}
		return idx == arr.size();
	}
};

RUN_TESTCASE(ReverseLinkedList)
{
	SolutionReverseLinkedList sln;
	ListNode* list = sln.BuildList({1,3,5,7,8,10,12});
	ListNode* reverseList = sln.reverseList(list);
	TESTCASE_ASSERT(sln.ListEqual(reverseList, {12, 10, 8, 7, 5, 3, 1}));
	sln.FreeList(reverseList);
}