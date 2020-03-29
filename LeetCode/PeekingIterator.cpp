#include "TestCase.h"

using namespace std;

class Iterator {
public:
	Iterator(const vector<int>& nums) {
		it = nums.begin();
		end = nums.end();
		first = true;
	}
	Iterator(const Iterator& iter) : it(iter.it), first(iter.first), end(iter.end) {}
	virtual ~Iterator() {}

	// Returns the next element in the iteration.
	int next()
	{
		if (first)
		{
			first = false;
			return *it;
		}
		else
			return *(++it);
	}

	// Returns true if the iteration has more elements.
	bool hasNext() const { return (it + 1) != end; }

protected:
	vector<int>::const_iterator end;
	vector<int>::const_iterator it;
	bool first = false;
};


class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
		// Initialize any member here.
		// **DO NOT** save a copy of nums and manipulate it directly.
		// You should only use the Iterator interface methods.

	}

	// Returns the next element in the iteration without advancing the iterator.
	int peek() {
		Iterator bak(*this);
		return bak.next();
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
		return Iterator::next();
	}

	bool hasNext() const {
		return Iterator::hasNext();
	}

protected:

};

RUN_TESTCASE(PeekingIterator)
{
	vector<int> arr1 = { 1,2,3 };
	PeekingIterator it(arr1);
	TESTCASE_ASSERT(it.next() == 1);
	TESTCASE_ASSERT(it.peek() == 2);
	TESTCASE_ASSERT(it.next() == 2);
	TESTCASE_ASSERT(it.next() == 3);
	TESTCASE_ASSERT(!it.hasNext());
}