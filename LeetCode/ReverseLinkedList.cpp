#include "TestCase.h"
#include "LinkedListCommon.h"

class SolutionReverseLinkedList : public LinkedListCommon
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
};

RUN_TESTCASE(ReverseLinkedList)
{
	SolutionReverseLinkedList sln;
	ListNode* list = sln.BuildList({1,3,5,7,8,10,12});
	ListNode* reverseList = sln.reverseList(list);
	TESTCASE_ASSERT(sln.ListEqual(reverseList, {12, 10, 8, 7, 5, 3, 1}));
	sln.FreeList(reverseList);
}