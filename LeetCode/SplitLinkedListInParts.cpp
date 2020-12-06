#include "TestCase.h"
#include "LinkedListCommon.h"

using namespace std;

class SolutionSplitLinkedListInParts : public LinkedListCommon
{
public:
	vector<ListNode*> splitListToParts(ListNode* root, int k) {
		int n = 0;
		ListNode* cur = root;
		while (cur)
		{
			n++;
			cur = cur->next;
		}

		vector<ListNode*> l;
		int num = n / k;
		int remain = n % k;
		cur = root;
		for (int i = 0; i < k; i++)
		{
			int c = num;
			if (remain > 0)
			{
				c++;
				remain--;
			}

			l.push_back(cur);
			while (cur && c > 0)
			{
				if (--c == 0)
				{
					ListNode* next = cur->next;
					cur->next = nullptr;
					cur = next;
				}
				else
					cur = cur->next;
			}
		}

		return l;
	}
};

RUN_TESTCASE(SplitLinkedListInParts)
{
	SolutionSplitLinkedListInParts sln;

	vector<int> arr1 = { 1,2,3 };
	vector<vector<int>> ret1 = {
		{1},
		{2},
		{3},
		{},
		{}
	};
	ListNode* l1 = sln.BuildList(arr1);
	vector<ListNode*> larr1 = sln.splitListToParts(l1, 5);
	TESTCASE_ASSERT(larr1.size() == ret1.size());
	for (int i = 0; i < larr1.size(); i++)
	{
		TESTCASE_ASSERT(sln.ListEqual(larr1[i], ret1[i]));
		sln.FreeList(larr1[i]);
	}

	vector<int> arr2 = { 1,2,3,4,5,6,7,8,9,10 };
	vector<vector<int>> ret2 = {
		{1,2,3,4},
		{5,6,7},
		{8,9,10},
	};
	ListNode* l2 = sln.BuildList(arr2);
	vector<ListNode*> larr2 = sln.splitListToParts(l2, 3);
	TESTCASE_ASSERT(larr2.size() == ret2.size());
	for (int i = 0; i < larr2.size(); i++)
	{
		TESTCASE_ASSERT(sln.ListEqual(larr2[i], ret2[i]));
		sln.FreeList(larr2[i]);
	}

	vector<int> arr3 = {};
	vector<vector<int>> ret3 = {
		{},
		{},
		{},
	};
	ListNode* l3 = sln.BuildList(arr3);
	vector<ListNode*> larr3 = sln.splitListToParts(l3, 3);
	TESTCASE_ASSERT(larr3.size() == ret3.size());
	for (int i = 0; i < larr3.size(); i++)
	{
		TESTCASE_ASSERT(sln.ListEqual(larr3[i], ret3[i]));
		sln.FreeList(larr3[i]);
	}
}