#include "TestCase.h"

using namespace std;

class MinStack
{
public:
	/** initialize your data structure here. */
	MinStack() {
		min = std::numeric_limits<int>::max();
	}

	void push(int x) {
		c.push_back(x);

		if (x < min)
			min = x;
	}

	void pop() {
		c.pop_back();

		calcMin();
	}

	int top() {
		return c.back();
	}

	int getMin() {
		return min;
	}

protected:
	vector<int> c;
	int min;

	void calcMin()
	{
		min = std::numeric_limits<int>::max();
		for (auto v : c)
		{
			if (v < min)
				min = v;
		}
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
RUN_TESTCASE(MinStack)
{
	MinStack minStack;
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	TESTCASE_ASSERT(minStack.getMin() == -3);   //-- > Returns - 3.
	minStack.pop();
	TESTCASE_ASSERT(minStack.top() == 0);      //-- > Returns 0.
	TESTCASE_ASSERT(minStack.getMin() == -2);   //-- > Returns - 2.
}