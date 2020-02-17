#include "TestCase.h"
#include "LinkedListCommon.h"

using namespace std;

class SolutionLinkedListCycle : public LinkedListCommon
{
public:
	bool hasCycle(ListNode *head) {
		ListNode* slow = head;
		ListNode* fast = slow;
		while (fast)
		{
			fast = fast->next;
			if (fast)
				fast = fast->next;
			else
				return false;
			slow = slow->next;
			if (fast == slow)
				return true;
		}

		return false;
	}
};

RUN_TESTCASE(LinkedListCycle)
{
	SolutionLinkedListCycle sln;

	vector<int> arr1 = { 3,2,0,-4 };
	ListNode* l1 = sln.BuildList(arr1);
	l1->next->next->next->next = l1->next;
	TESTCASE_ASSERT(sln.hasCycle(l1));
	l1->next->next->next->next = nullptr;
	sln.FreeList(l1);

	vector<int> arr2 = { 1,2 };
	ListNode* l2 = sln.BuildList(arr2);
	l2->next->next = l2;
	TESTCASE_ASSERT(sln.hasCycle(l2));
	l2->next->next = nullptr;
	sln.FreeList(l2);

	vector<int> arr3 = { 1 };
	ListNode* l3 = sln.BuildList(arr3);
	TESTCASE_ASSERT(!sln.hasCycle(l3));
	sln.FreeList(l3);
}