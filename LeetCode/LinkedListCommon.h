#pragma once

#include <vector>
#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class LinkedListCommon
{
public:
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

	void PrintList(ListNode* pHead)
	{
		while (pHead)
		{
			std::cout << pHead->val << ",";
			pHead = pHead->next;
		}

		std::cout << std::endl;
	}
};