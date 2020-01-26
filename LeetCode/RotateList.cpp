#include "TestCase.h"
#include "LinkedListCommon.h"

using namespace std;

class SolutionRotateList : public LinkedListCommon
{
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        
        int n = 0;
        ListNode* cur = head;
        ListNode* last = nullptr;
        while (cur)
        {
            ++n;
            if (!cur->next)
                last = cur;
            cur = cur->next;
        }
        
        k = k % n;
        if (k != 0)
        {
            k = n - k;
            cur = head;
            while (cur)
            {
                if (--k == 0)
                {
                    last->next = head;
                    head = cur->next;
                    cur->next = nullptr;
                    break;
                }
                cur = cur->next;
            }
        }
        
        return head;
    }
};

RUN_TESTCASE(RotateList)
{
    SolutionRotateList sln;
    
    vector<int> arr1 = {1,2,3,4,5};
    vector<int> ret1 = {4,5,1,2,3};
    ListNode* l1 = sln.BuildList(arr1);
    l1 = sln.rotateRight(l1, 2);
    TESTCASE_ASSERT(sln.ListEqual(l1, ret1));
    sln.FreeList(l1);
    
    vector<int> arr2 = {0,1,2};
    vector<int> ret2 = {2,0,1};
    ListNode* l2 = sln.BuildList(arr2);
    l2 = sln.rotateRight(l2, 4);
    TESTCASE_ASSERT(sln.ListEqual(l2, ret2));
    sln.FreeList(l2);
}
