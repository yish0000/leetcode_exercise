#include "TestCase.h"

using namespace std;

class SolutionRectangleArea
{
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int s1 = (C - A) * (D - B);
		int s2 = (G - E) * (H - F);
		int s3;
		if (C <= E || A >= G || B >= H || D <= F)
			s3 = 0;
		else
		{
			int l = A > E ? A : E;
			int t = D < H ? D : H;
			int r = C < G ? C : G;
			int b = B > F ? B : F;
			s3 = (r - l) * (t - b);
		}
		return s1 + s2 - s3;
	}
};

RUN_TESTCASE(RectangleArea)
{
	SolutionRectangleArea sln;
	TESTCASE_ASSERT(sln.computeArea(-3, 0, 3, 4, 0, -1, 9, 2) == 45);
	TESTCASE_ASSERT(sln.computeArea(0, 0, 0, 0, -1, -1, 1, 1) == 4);
	TESTCASE_ASSERT(sln.computeArea(-2, -2, 2, 2, 3, 3, 4, 4) == 17);
	TESTCASE_ASSERT(sln.computeArea(-5, -5, -4, 0, -3, -3, 3, 3) == 41);
}