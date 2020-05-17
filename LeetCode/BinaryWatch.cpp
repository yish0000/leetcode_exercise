#include "TestCase.h"

using namespace std;

class SolutionBinaryWatch
{
public:
	const int hours[4] = { 1,2,4,8 };
	const int mins[6] = { 1,2,4,8,16,32 };
	vector<string> readBinaryWatch(int num) {
		vector<string> ret;
		dfs(ret, num, 0, 0);
		return ret;
	}

	void dfs(vector<string>& out, int num, int ss, int st)
	{
		if (num == 0)
		{
			int hour = 0, min = 0;
			for (int i = 0; i < 4; i++)
				hour += (ss & (1 << i)) ? hours[i] : 0;
			for (int i = 0; i < 6; i++)
				min += (ss & (1 << (i + 4))) ? mins[i] : 0;

			char szText[10];
			snprintf(szText, 10, "%d:%02d", hour, min);
			out.push_back(szText);
			return;
		}

		for (int i = st; i < 10; i++)
		{
			if (!(ss & (1 << i)))
			{
				ss |= (1 << i);
				if (check(ss))
					dfs(out, num - 1, ss, i + 1);
				ss &= ~(1 << i);
			}
		}
	}

	bool check(int ss)
	{
		int hour = 0;
		int min = 0;
		for (int i = 0; i < 4; i++)
			hour += (ss & (1 << i)) ? (hours[i]) : 0;
		for (int i = 4; i <= 9; i++)
			min += (ss & (1 << i)) ? (mins[i - 4]) : 0;
		return hour < 12 && min < 60;
	}
};

RUN_TESTCASE(BinaryWatch)
{
	SolutionBinaryWatch sln;

	vector<string> ret1 = { "1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32" };
	TESTCASE_ASSERT(vectorComboEqual(sln.readBinaryWatch(1), ret1));

	vector<string> ret2 = { "0:03","0:05","0:06","0:09","0:10","0:12","0:17","0:18","0:20","0:24","0:33","0:34","0:36","0:40","0:48","1:01","1:02","1:04","1:08","1:16","1:32","2:01","2:02","2:04","2:08","2:16","2:32","3:00","4:01","4:02","4:04","4:08","4:16","4:32","5:00","6:00","8:01","8:02","8:04","8:08","8:16","8:32","9:00","10:00" };
	TESTCASE_ASSERT(vectorComboEqual(sln.readBinaryWatch(2), ret2));
}