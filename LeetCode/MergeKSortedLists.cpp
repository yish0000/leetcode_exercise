#include "TestCase.h"
#include "LinkedListCommon.h"

using namespace std;

class SolutionMergeKSortedLists : public LinkedListCommon
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        while(lists.size() > 1)
        {
            int count = (int)lists.size() / 2;
            for (int i=0; i<count; i++)
                lists[i] = mergeTwoLists(lists[i*2], lists[i*2+1]);
            if (lists.size() & 1)
            {
                std::swap(lists[count], lists.back());
                count++;
            }
            lists.erase(lists.begin()+count, lists.end());
        }
        return lists[0];
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (!(l1 && l2))
        {
            if (l1) return l1;
            if (l2) return l2;
            return NULL;
        }
        ListNode* prev = NULL;
        ListNode* newBeg = l1;
        for (bool initLoop = true; ; initLoop = false)
        {
            if (!l1 || !l2)
            {
                if (l1)
                    prev->next = l1;
                else
                    prev->next = l2;
                break;
            }
            
            if (l2->val < l1->val)
            {
                if (initLoop)
                    newBeg = l2;
                ListNode* thisMid = l2;
                l2 = l2->next;
                thisMid->next = l1;
                if (prev)
                    prev->next = thisMid;
                prev = thisMid;
            }
            else
            {
                prev = l1;
                l1 = l1->next;
            }
        }
        return newBeg;
    }
};

RUN_TESTCASE(MergeKSortedLists)
{
    SolutionMergeKSortedLists sln;
    
    {
        vector<ListNode*> lists1;
        vector<int> arr1 = { 1,4,5 };
        vector<int> arr2 = { 1,3,4 };
        vector<int> arr3 = { 2,6 };
        lists1.push_back(sln.BuildList(arr1));
        lists1.push_back(sln.BuildList(arr2));
        lists1.push_back(sln.BuildList(arr3));
        vector<int> res = { 1,1,2,3,4,4,5,6 };
        TESTCASE_ASSERT(sln.ListEqual(sln.mergeKLists(lists1), res));
    }
}
