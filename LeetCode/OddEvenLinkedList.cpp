#include "TestCase.h"
#include "LinkedListCommon.h"

using namespace std;

class SolutionOddEvenLinkedList : public LinkedListCommon
{
public:
	ListNode* oddEvenList(ListNode* head) {
		if (!head) return nullptr;
		ListNode* odd_head = head;
		ListNode* even_head = head->next;
		ListNode* odd = nullptr;
		ListNode* even = nullptr;
		while (head)
		{
			if (!odd)
				odd = head;
			else
			{
				odd->next = head;
				odd = head;
			}
			if (!head->next)
			{
				odd->next = even_head;
				if (even) even->next = nullptr;
				break;
			}
			head = head->next;

			if (!even)
				even = head;
			else
			{
				even->next = head;
				even = head;
			}
			if (!head->next)
			{
				odd->next = even_head;
				if (even) even->next = nullptr;
				break;
			}
			head = head->next;
		}
		return odd_head;
	}
};

RUN_TESTCASE(OddEvenLinkedList)
{
	SolutionOddEvenLinkedList sln;

	vector<int> arr1 = { 1,2,3,4,5 };
	vector<int> ret1 = { 1,3,5,2,4 };
	ListNode* l1 = sln.BuildList(arr1);
	ListNode* r1 = sln.oddEvenList(l1);
	TESTCASE_ASSERT(sln.ListEqual(r1, ret1));
	sln.FreeList(r1);

	vector<int> arr2 = { 2,1,3,5,6,4,7 };
	vector<int> ret2 = { 2,3,6,7,1,5,4 };
	ListNode* l2 = sln.BuildList(arr2);
	ListNode* r2 = sln.oddEvenList(l2);
	TESTCASE_ASSERT(sln.ListEqual(r2, ret2));
	sln.FreeList(r2);

	vector<int> arr3 = { 1 };
	vector<int> ret3 = { 1 };
	ListNode* l3 = sln.BuildList(arr3);
	ListNode* r3 = sln.oddEvenList(l3);
	TESTCASE_ASSERT(sln.ListEqual(r3, ret3));
	sln.FreeList(r3);
}