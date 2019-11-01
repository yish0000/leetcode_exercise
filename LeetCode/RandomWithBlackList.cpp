#include "TestCase.h"

using namespace std;

class SolutionRandomWithBlackList
{
public:
	SolutionRandomWithBlackList(int N, vector<int>& blacklist) {
		m_N = N - (int)blacklist.size();
		m_blackList = blacklist;
		std::sort(m_blackList.begin(), m_blackList.end());
	}

	int pick() {
		int n = rand() % m_N;
		int bnum = (int)m_blackList.size();
		if (bnum == 0 || m_blackList[0] > n)
			return n;

		int l = 0;
		int r = bnum - 1;
		while (l < r)
		{
			int mid = l + (r - l) / 2;
			if ((n + mid >= m_blackList[mid]) &&
				(mid == bnum - 1 || (mid != bnum - 1 && n + mid + 1 < m_blackList[mid + 1])))
				return n + 1 + mid;
			else if (n + mid < m_blackList[mid])
				r = mid - 1;
			else
				l = mid + 1;
		}

		return -1;
	}

protected:
	int m_N;
	vector<int> m_blackList;
};

RUN_TESTCASE(RandomWithBlackList)
{
	/**
	 * Your Solution object will be instantiated and called as such:
	 * Solution* obj = new Solution(N, blacklist);
	 * int param_1 = obj->pick();
	 */
}