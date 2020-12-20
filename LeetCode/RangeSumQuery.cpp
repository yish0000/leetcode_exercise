#include "TestCase.h"
#include <math.h>

using namespace std;

class NumArray {
public:
	NumArray(vector<int>& nums) {
		if (nums.size() > 0)
		{
			int n = (int)nums.size();
			int x = (int)ceil((log(n) / log(2)));
			int maxSize = 2 * (int)pow(2, x) - 1;
			_segTree.resize(maxSize);
			_nums = nums;
			buildTree(0, 0, n - 1);
		}
	}

	void buildTree(int idx, int left, int right)
	{
		if (left == right)
		{
			_segTree[idx] = _nums[left];
			return;
		}

		int mid = left + (right - left) / 2;
		buildTree(2 * idx + 1, left, mid);
		buildTree(2 * idx + 2, mid + 1, right);
		_segTree[idx] = _segTree[idx * 2 + 1] + _segTree[idx * 2 + 2];
	}

	void update(int i, int val) {
		int diff = val - _nums[i];
		_nums[i] = val;
		updateRecurse(0, 0, (int)_nums.size() - 1, diff, i);
	}

	void updateRecurse(int idx, int left, int right, int diff, int i)
	{
		if (i < left || i > right) return;
		_segTree[idx] += diff;
		if (left >= right) return;
		int mid = left + (right - left) / 2;
		updateRecurse(idx * 2 + 1, left, mid, diff, i);
		updateRecurse(idx * 2 + 2, mid + 1, right, diff, i);
	}

	int sumRange(int i, int j) {
		return query(0, 0, (int)_nums.size() - 1, i, j);
	}

	int query(int idx, int left, int right, int i, int j)
	{
		if (left >= i && right <= j)
			return _segTree[idx];
		if (right < i || left > j)
			return 0;
		int mid = left + (right - left) / 2;
		int leftSum = query(idx * 2 + 1, left, mid, i, j);
		int rightSum = query(idx * 2 + 2, mid + 1, right, i, j);
		return leftSum + rightSum;
	}

protected:
	vector<int> _nums;
	vector<int> _segTree;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
RUN_TESTCASE(RangeSumQuery)
{
	NumArray nums(vector<int>({ 1,3,5 }));
	TESTCASE_ASSERT(nums.sumRange(0, 2) == 9);
	nums.update(1, 2);
	TESTCASE_ASSERT(nums.sumRange(0, 2) == 8);
}