#include <iostream>
#include <vector>
#include "TestCase.h"
#include <time.h>
#include <assert.h>

class PriorityQueue
{
public:
    void Push(int num)
    {
        c.push_back(num);
        SiftUp();
    }
    
    void Pop()
    {
        SiftDown();
        c.pop_back();
    }
    
    int Top() const
    {
        assert(c.size() > 0);
        return c[0];
    }
    
    int Size() const { return (int)c.size(); }
    
protected:
    std::vector<int> c;
    
    void SiftUp()
    {
        int curIndex = (int)c.size();
        while (curIndex > 1)
        {
            int parentIndex = curIndex / 2;
            if (c[curIndex - 1] < c[parentIndex - 1])
                std::swap(c[curIndex - 1], c[parentIndex - 1]);
            curIndex = parentIndex;
        }
    }
    
    void SiftDown()
    {
        if (c.size() <= 1)
            return;
        
        std::swap(c[0], c[c.size()-1]);
        
        int curIndex = 1;
        while(curIndex * 2 < (int)c.size())
        {
            int selChild = 0;
            int leftChild = curIndex * 2;
            int rightChild = curIndex * 2 + 1;
            if (rightChild < (int)c.size())
            {
                if (c[leftChild-1] < c[rightChild-1])
                    selChild = leftChild;
                else
                    selChild = rightChild;
            }
            else
                selChild = leftChild;
            if (c[curIndex-1] > c[selChild-1])
                std::swap(c[curIndex-1], c[selChild-1]);
            curIndex = selChild;
        }
    }
};

RUN_TESTCASE(PriorityQueue)
{
    PriorityQueue queue;
    std::vector<int> nums = {82, 97, 34, 14, 15, 80, 5, 35, 19, 73};
    for (int i=0; i<10; i++)
    {
        queue.Push(nums[i]);
    }
    
    std::vector<int> nums2;
    while(queue.Size() > 0)
    {
        nums2.push_back(queue.Top());
        queue.Pop();
    }
    
    for (size_t i=0;i<nums2.size(); ++i)
    {
        std::cout << nums2[i] << ",";
    }
    std::cout << std::endl;
}
