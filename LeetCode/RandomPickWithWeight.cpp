#include "TestCase.h"

using namespace std;

class SolutionRandomPickWithWeight
{
public:
	SolutionRandomPickWithWeight(vector<int>& w) {
		int all = 0;
		for (auto i : w)
			all += i;
		for (auto i : w)
		{
			float last = 0.0f;
			if (probs.size() > 0)
				last = probs.back();
			probs.push_back(last + (float)i / all);
		}
	}

	int pickIndex() {
		float u = (float)rand() / RAND_MAX;
		int l = 0, r = (int)probs.size() - 1;
		while (l < r)
		{
			int mid = l + (r - l) / 2;
			if (u <= probs[mid])
			{
				if (mid == 0 || u > probs[mid - 1])
					return mid;
				else
					r = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}
		return l;
	}

protected:
	vector<float> probs;
};

/**
* Your Solution object will be instantiated and called as such:
* Solution* obj = new Solution(w);
* int param_1 = obj->pickIndex();
*/
RUN_TESTCASE(RandomPickWithWeight)
{
	vector<int> weights = {
		22, 33333, 100, 700, 1000,
	};

	SolutionRandomPickWithWeight sln(weights);
	for (int i = 0; i < 20; i++)
		std::cout << sln.pickIndex() << std::endl;
}