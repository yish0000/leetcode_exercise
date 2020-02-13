#include "TestCase.h"

using namespace std;

class SolutionReverseBits
{
public:
	uint32_t reverseBits(uint32_t n) {
		int l = 0, r = 31;
		while (l < r)
		{
			uint32_t lv = n & (1 << l);
			uint32_t rv = n & (1 << r);
			if ((lv ^ rv) != 0)
			{
				lv >>= l;
				rv >>= r;
				n &= ~(1 << l);
				n &= ~(1 << r);
				n |= (lv << r);
				n |= (rv << l);
			}
			l++;
			r--;
		}
		return n;
	}
};

RUN_TESTCASE(ReverseBits)
{
	SolutionReverseBits sln;
	TESTCASE_ASSERT(sln.reverseBits(0x2941e9c) == 0x39782940);
	TESTCASE_ASSERT(sln.reverseBits(0xfffffffd) == 0xbfffffff);
}