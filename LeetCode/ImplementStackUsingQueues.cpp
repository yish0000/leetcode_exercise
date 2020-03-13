#include "TestCase.h"
#include <queue>

using namespace std;

class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		int count = (int)q.size();
		q.push(x);
		while (count > 0)
		{
			int item = q.front();
			q.pop();
			q.push(item);
			count--;
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int item = q.front();
		q.pop();
		return item;
	}

	/** Get the top element. */
	int top() {
		return q.front();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return q.empty();
	}

protected:
	queue<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
RUN_TESTCASE(ImplementStackUsingQueues)
{
	MyStack stack;
	stack.push(1);
	stack.push(2);
	TESTCASE_ASSERT(stack.top() == 2);   // returns 2
	TESTCASE_ASSERT(stack.pop() == 2);   // returns 2
	TESTCASE_ASSERT(!stack.empty()); // returns false
}