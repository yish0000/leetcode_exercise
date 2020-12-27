#include "TestCase.h"
#include <stack>

using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger
{
protected:
	int value = 0;
	vector<NestedInteger> list;
	bool is_list = false;

public:
	NestedInteger(int val) : value(val) {}
	NestedInteger(vector<NestedInteger>&& arr) : list(arr), is_list(true) {}

	// Return true if this NestedInteger holds a single integer, rather than a nested list.
	bool isInteger() const { return list.empty(); }

	// Return the single integer that this NestedInteger holds, if it holds a single integer
	// The result is undefined if this NestedInteger holds a nested list
	int getInteger() const { return value; }

	// Return the nested list that this NestedInteger holds, if it holds a nested list
	// The result is undefined if this NestedInteger holds a single integer
	const vector<NestedInteger> &getList() const { return list; }
};

class NestedIterator {
	using iterator = vector<NestedInteger>::const_iterator;
public:
	NestedIterator(vector<NestedInteger> &nestedList) {
		handle_list(nestedList);
	}

	void handle_list(const vector<NestedInteger>& list)
	{
		for (auto& i : list)
		{
			if (i.isInteger())
				_list.push_back(i.getInteger());
			else
				handle_list(i.getList());
		}
	}

	int next() {
		return _list[_index++];
	}

	bool hasNext() {
		return _index < _list.size();
	}

private:
	vector<int> _list;
	int _index = 0;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
RUN_TESTCASE(NestedIterator)
{
	vector<NestedInteger> arr1 = {
		NestedInteger({NestedInteger(1), NestedInteger(1)}),
		NestedInteger(2),
		NestedInteger({NestedInteger(1), NestedInteger(1)}),
	};
	NestedIterator i1(arr1);
	while (i1.hasNext()) cout << i1.next() << endl;

	vector<NestedInteger> arr2 = {
		NestedInteger(1),
		NestedInteger(
			{NestedInteger(4), NestedInteger(
				{
					NestedInteger(6)
				})
			}
		),
	};
	NestedIterator i2(arr2);
	while (i2.hasNext()) cout << i2.next() << endl;
}