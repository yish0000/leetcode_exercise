#include "TestCase.h"
#include <stack>

using namespace std;

class MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		a.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		if (b.empty())
			transfer();
		int item = b.top();
		b.pop();
		return item;
	}

	/** Get the front element. */
	int peek() {
		if (b.empty())
			transfer();
		return b.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return a.empty() && b.empty();
	}

protected:
	stack<int> a;
	stack<int> b;

	void transfer()
	{
		while (a.size() > 0)
		{
			int item = a.top();
			a.pop();
			b.push(item);
		}
	}
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
RUN_TESTCASE(ImplementQueueUsingStacks)
{
	MyQueue queue;
	queue.push(1);
	queue.push(2);
	TESTCASE_ASSERT(queue.peek() == 1);  // returns 1
	TESTCASE_ASSERT(queue.pop() == 1);   // returns 1
	TESTCASE_ASSERT(!queue.empty()); // returns false
}