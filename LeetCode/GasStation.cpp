#include "TestCase.h"

using namespace std;

class SolutionGasStation
{
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int index = -1;
		int all_cost = 0;
		int cur_cost = 0;
		for (int i = 0; i < gas.size(); i++)
		{
			int cur = (gas[i] - cost[i]);
			if (cur >= 0)
			{
				if (index == -1)
					index = i;
			}
			cur_cost += cur;
			if (cur_cost < 0)
			{
				index = -1;
				cur_cost = 0;
			}
			all_cost += cur;
		}
		return all_cost >= 0 ? index : -1;
	}
};

RUN_TESTCASE(GasStation)
{
	SolutionGasStation sln;

	TESTCASE_ASSERT(sln.canCompleteCircuit(vector<int>({ 1,2,3,4,5 }), vector<int>({ 3,4,5,1,2 })) == 3);
	TESTCASE_ASSERT(sln.canCompleteCircuit(vector<int>({ 2,3,4 }), vector<int>({ 3,4,3 })) == -1);
	TESTCASE_ASSERT(sln.canCompleteCircuit(vector<int>({ 3,1,1 }), vector<int>({ 1,2,2 })) == 0);
	TESTCASE_ASSERT(sln.canCompleteCircuit(vector<int>({ 1,2,3,2,3,4,7,8 }), vector<int>({ 3,4,5,1,5,3,4,5 })) == 5);
	TESTCASE_ASSERT(sln.canCompleteCircuit(vector<int>({ 2 }), vector<int>({ 2 })) == 0);
}