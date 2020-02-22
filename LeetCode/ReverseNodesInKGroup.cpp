#include "TestCase.h"
#include "LinkedListCommon.h"

using namespace std;

class SolutionReverseNodesInKGroup : public LinkedListCommon
{
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (!head)
			return head;

		int n = 0;
		ListNode* prev = nullptr;
		ListNode* next = head;
		ListNode* p1;
		ListNode* p2;
		ListNode* tail;
		while (next)
		{
			n++;
			next = next->next;

			if (n >= k)
			{
				p1 = prev ? prev->next : head;
				p2 = p1->next;
				tail = p1;

				p1->next = next;
				while (p2 && --n > 0)
				{
					ListNode* tmp = p2->next;
					p2->next = p1;
					p1 = p2;
					p2 = tmp;
				}

				if (prev)
					prev->next = p1;
				else
					head = p1;

				prev = tail;
			}
		}

		return head;
	}
};

RUN_TESTCASE(ReverseNodesInKGroup)
{
	SolutionReverseNodesInKGroup sln;

	vector<int> arr1 = { 1,2,3,4,5 };
	ListNode* l1 = sln.BuildList(arr1);
	ListNode* l2 = sln.BuildList(arr1);

	vector<int> ret1 = { 2,1,4,3,5 };
	l1 = sln.reverseKGroup(l1, 2);
	TESTCASE_ASSERT(sln.ListEqual(l1, ret1));
	sln.FreeList(l1);

	vector<int> ret2 = { 3,2,1,4,5 };
	l2 = sln.reverseKGroup(l2, 3);
	TESTCASE_ASSERT(sln.ListEqual(l2, ret2));
	sln.FreeList(l2);
}