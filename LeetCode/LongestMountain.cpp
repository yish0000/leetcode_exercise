#include "TestCase.h"

using namespace std;

class SolutionLongestMountain
{
public:
	int longestMountain(vector<int>& A) {
		int peak = -1;
		int l = -1, r = -1;
		int max_len = 0;
		for (int i = 0; i < (int)A.size(); i++)
		{
			if (l == -1)
				l = i;
			else
			{
				if (peak == -1)
				{
					if (A[i] > A[l])
						peak = i;
					else
					{
						l = i;
						r = -1;
						peak = -1;
					}
				}
				else
				{
					if (r == -1)
					{
						if (A[i] > A[peak])
							peak = i;
						else if (A[i] < A[peak])
							r = i;
						else
						{
							l = i;
							r = -1;
							peak = -1;
						}
					}
					else
					{
						if (A[i] < A[r])
							r = i;
						else
						{
							int len = r - l + 1;
							max_len = std::max(max_len, len);
                            if (A[r] != A[i])
                                l = r;
                            else
                                l = i;
							peak = i;
							r = -1;
						}
					}
				}
			}
		}
		if (l != -1 && r != -1 && peak != -1)
		{
			int len = r - l + 1;
			max_len = std::max(max_len, len);
			l = r = peak = -1;
		}
		return max_len;
	}
};

RUN_TESTCASE(LongestMountain)
{
	SolutionLongestMountain sln;

	vector<int> arr1 = { 2,1,4,7,3,2,5 };
	TESTCASE_ASSERT(sln.longestMountain(arr1) == 5);

	vector<int> arr2 = { 2,2,2 };
	TESTCASE_ASSERT(sln.longestMountain(arr2) == 0);

	vector<int> arr3 = { 0,1,2,3,4,5,6,4,2,-1,-1,0,2,1,0,3,4,7,3,-2 };
	TESTCASE_ASSERT(sln.longestMountain(arr3) == 10);

	vector<int> arr4 = { 0,1,2,3,4,5,4,3,2,1,0 };
	TESTCASE_ASSERT(sln.longestMountain(arr4) == 11);

	vector<int> arr5 = { 0,2,2 };
	TESTCASE_ASSERT(sln.longestMountain(arr5) == 0);

	vector<int> arr6 = { 875,884,239,731,723,685 };
	TESTCASE_ASSERT(sln.longestMountain(arr6) == 4);

	vector<int> arr7 = { 81,54,72,92,9,86,24,63,28,12 };
	TESTCASE_ASSERT(sln.longestMountain(arr7) == 4);
    
    vector<int> arr8 = {
        0,1,0,0,1,0,0,1,1,0,0,0,1,1,0,1,0,1,0,1,0,0,0,1,0,0,1,1,0,1,1,1,1,1,0,0,1,
        0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,1,0,0,0,1,0,0,1,1,0,0,0,1,0,0,1,1,0,0,0,
        0,1,0,0,1,1,1,1,1,1,1,0,1,1,0,1,1,1,0,0,0,1,0,1,1
    };
    TESTCASE_ASSERT(sln.longestMountain(arr8) == 3);
}
