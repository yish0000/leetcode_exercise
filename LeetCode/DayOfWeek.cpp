#include "TestCase.h"
#include <time.h>

using namespace std;

class SolutionDayOfWeek
{
public:
	const char* strs[7] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
	const int month_days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	string dayOfTheWeek(int day, int month, int year) {
		int days = day;
		for (int y = 1971; y < year; y++)
		{
			days += 365;
			if (is_leap_year(y))
				days++;
		}
		for (int i = 1; i < month; i++)
		{
			days += month_days[i - 1];
			if (i == 2 && is_leap_year(year))
				days++;
		}
		int wday = (days + 3) % 7;
		return strs[wday];
	}
	bool is_leap_year(int year)
	{
		return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	}
};

RUN_TESTCASE(DayOfWeek)
{
	SolutionDayOfWeek sln;
	TESTCASE_ASSERT(sln.dayOfTheWeek(1, 1, 1971) == "Friday");
	TESTCASE_ASSERT(sln.dayOfTheWeek(31, 8, 2019) == "Saturday");
	TESTCASE_ASSERT(sln.dayOfTheWeek(18, 7, 1999) == "Sunday");
	TESTCASE_ASSERT(sln.dayOfTheWeek(15, 8, 1993) == "Sunday");
}