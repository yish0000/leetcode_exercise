#include "TestCase.h"
#include "LinkedListCommon.h"
#include <deque>

using namespace std;

class SolutionReorderList : public LinkedListCommon
{
public:
	void reorderList(ListNode* head) {
		if (!head) return;
		deque<ListNode*> arr;
		ListNode* cur = head;
		while (cur)
		{
			arr.push_back(cur);
			cur = cur->next;
		}
		cur = head;
		while (arr.size() > 0)
		{
			if (arr.size() >= 2)
			{
				ListNode* n1 = arr.front();
				ListNode* n2 = arr.back();
				if (cur != n1)
					cur->next = n1;
				n1->next = n2;
				cur = n2;
				arr.pop_front();
				arr.pop_back();
			}
			else
			{
				ListNode* n1 = arr.back();
				if (cur != n1)
					cur->next = n1;
				cur = n1;
				arr.pop_back();
			}
		}
		cur->next = nullptr;
	}
};

RUN_TESTCASE(ReorderList)
{
	SolutionReorderList sln;

	vector<int> arr1 = { 1,2,3,4,5,6,7,8,9 };
	vector<int> ret1 = { 1,9,2,8,3,7,4,6,5 };
	ListNode* l1 = sln.BuildList(arr1);
	sln.reorderList(l1);
	TESTCASE_ASSERT(sln.ListEqual(l1, ret1));
	sln.FreeList(l1);

	vector<int> arr2 = { 1,2,3,4 };
	vector<int> ret2 = { 1,4,2,3 };
	ListNode* l2 = sln.BuildList(arr2);
	sln.reorderList(l2);
	TESTCASE_ASSERT(sln.ListEqual(l2, ret2));
	sln.FreeList(l2);
}