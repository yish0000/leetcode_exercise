#include "TestCase.h"

using namespace std;

class SolutionGasStation
{
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int index = -1;
		int all_cost = 0;
		int cur_cost = 0;
		for (int i = 0; i < (int)gas.size(); i++)
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

    vector<int> gas1({ 1,2,3,4,5 });
    vector<int> cost1({ 3,4,5,1,2 });
	TESTCASE_ASSERT(sln.canCompleteCircuit(gas1, cost1) == 3);
    
    vector<int> gas2({ 2,3,4 });
    vector<int> cost2({ 3,4,3 });
	TESTCASE_ASSERT(sln.canCompleteCircuit(gas2, cost2) == -1);
    
    vector<int> gas3({ 3,1,1 });
    vector<int> cost3({ 1,2,2 });
	TESTCASE_ASSERT(sln.canCompleteCircuit(gas3, cost3) == 0);
    
    vector<int> gas4({ 1,2,3,2,3,4,7,8 });
    vector<int> cost4({ 3,4,5,1,5,3,4,5 });
	TESTCASE_ASSERT(sln.canCompleteCircuit(gas4, cost4) == 5);
    
    vector<int> gas5({ 2 });
    vector<int> cost5({ 2 });
	TESTCASE_ASSERT(sln.canCompleteCircuit(gas5, cost5) == 0);
}
