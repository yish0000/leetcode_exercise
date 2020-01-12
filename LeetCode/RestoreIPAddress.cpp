#include "TestCase.h"

using namespace std;

class SolutionRestoreIPAddress
{
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> arr;
		vector<string> cur_ip;
		restoreIpHelper(arr, s, 0, cur_ip);
		return arr;
	}

	void restoreIpHelper(vector<string>& out, const string& s, int index, vector<string>& cur_ip)
	{
		if (cur_ip.size() == 4)
		{
			if (index >= s.length())
			{
				string ret;
				for (int i = 0; i < cur_ip.size(); i++)
				{
					ret += cur_ip[i];
					if (i < cur_ip.size() - 1)
						ret += '.';
				}
				out.push_back(ret);
			}

			return;
		}

		for (int i = 1; i <= 3; i++)
		{
			if (index + i > s.length())
				continue;

			if (i > 1)
			{
				if (s[index] == '0')
					continue;

				if (i == 3)
				{
					if (s[index] > '2') continue;
					if (s[index] == '2' && s[index + 1] > '5') continue;
					if (s[index] == '2' && s[index + 1] == '5' && s[index + 2] > '5') continue;
				}
			}

			cur_ip.push_back(s.substr(index, i));
			index += i;
			restoreIpHelper(out, s, index, cur_ip);
			index -= i;
			cur_ip.pop_back();
		}
	}
};

RUN_TESTCASE(RestoreIPAddress)
{
	SolutionRestoreIPAddress sln;

	vector<string> arr1 = { "255.255.11.135", "255.255.111.35" };
	TESTCASE_ASSERT(sln.restoreIpAddresses("25525511135") == arr1);
	TESTCASE_ASSERT(sln.restoreIpAddresses("123") == vector<string>());

	vector<string> arr2 = { "0.10.0.10","0.100.1.0" };
	TESTCASE_ASSERT(sln.restoreIpAddresses("010010") == arr2);
}