#include "TestCase.h"
#include "LinkedListCommon.h"

using namespace std;

class SolutionLinkedListCycleII : public LinkedListCommon
{
public:
	ListNode *detectCycle(ListNode *head) {
		bool detect = false;
		ListNode* slow = head;
		ListNode* fast = slow;
		while (fast)
		{
			fast = fast->next;
			if (fast)
				fast = fast->next;
			else
				break;
			slow = slow->next;
			if (fast == slow)
			{
				detect = true;
				break;
			}
		}

		if (detect)
		{
			fast = head;
			while (fast)
			{
				if (fast == slow)
					return fast;

				fast = fast->next;
				slow = slow->next;
			}
		}

		return nullptr;
	}
};

RUN_TESTCASE(LinkedListCycleII)
{
	SolutionLinkedListCycleII sln;

	vector<int> arr1 = { 3,2,0,-4 };
	ListNode* l1 = sln.BuildList(arr1);
	l1->next->next->next->next = l1->next;
	TESTCASE_ASSERT(sln.detectCycle(l1) == l1->next);
	l1->next->next->next->next = nullptr;
	sln.FreeList(l1);

	vector<int> arr2 = { 1,2 };
	ListNode* l2 = sln.BuildList(arr2);
	l2->next->next = l2;
	TESTCASE_ASSERT(sln.detectCycle(l2) == l2);
	l2->next->next = nullptr;
	sln.FreeList(l2);

	vector<int> arr3 = { 1 };
	ListNode* l3 = sln.BuildList(arr3);
	TESTCASE_ASSERT(sln.detectCycle(l3) == nullptr);
	sln.FreeList(l3);
}