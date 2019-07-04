#include "TestCase.h"
#include "LinkedListCommon.h"

class SolutionReverseLinkedListII : public LinkedListCommon
{
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (!head) return NULL;
		int idx = 1;
		bool reverse = false;
		ListNode *ptr = head, *ptr1 = NULL, *ptr2 = NULL, *prev = NULL, *reverse_end = NULL;
		while ((reverse ? ptr2 : ptr) != NULL)
		{
			if (idx >= m && idx < n)
			{
				if (!reverse)
				{
					ptr1 = ptr;
					ptr2 = ptr->next;
					ptr1->next = NULL;
					reverse_end = ptr1;
					reverse = true;
					if (idx == 1) head = NULL;
				}

				ListNode* next = ptr2->next;
				ptr2->next = ptr1;
				ptr1 = ptr2;
				ptr2 = next;
				if (prev) prev->next = ptr1;
			}
			else
			{
				if (reverse)
				{
					reverse = false;
					reverse_end->next = ptr2;
					ptr = ptr2;
					if (!head) head = ptr1;
				}
				else
				{
					prev = ptr;
					ptr = ptr->next;
				}
			}

			idx++;
		}

		if (reverse)
		{
			reverse = false;
			reverse_end->next = ptr2;
			if (!head) head = ptr1;
		}

		return head;
	}
};

RUN_TESTCASE(ReverseLinkedListII)
{
	SolutionReverseLinkedListII sln;
	ListNode* list = sln.BuildList({ 1,3,5,7,8,10,12 });
	ListNode* reverseList = sln.reverseBetween(list, 3, 5);
	TESTCASE_ASSERT(sln.ListEqual(reverseList, { 1, 3, 8, 7, 5, 10, 12 }));
	sln.FreeList(reverseList);
	ListNode* list2 = sln.BuildList({ 3,5 });
	ListNode* reverseList2 = sln.reverseBetween(list2, 1, 2);
	sln.FreeList(reverseList2);
}