#include "TestCase.h"

using namespace std;

class SolutionRemoveSubFoldersFromFS
{
public:
	vector<string> removeSubfolders(vector<string>& folder) {
		std::sort(folder.begin(), folder.end());

		vector<string> ret;
		string curPrefix = folder.front();
		ret.push_back(curPrefix);
		for (vector<string>::iterator it = folder.begin() + 1; it != folder.end(); ++it)
		{
			if (it->find(curPrefix + '/') == string::npos)
			{
				curPrefix = *it;
				ret.push_back(curPrefix);
			}
		}
		return ret;
	}
};

RUN_TESTCASE(RemoveSubFoldersFromFS)
{
	SolutionRemoveSubFoldersFromFS sln;

	vector<string> arr1 = { "/a","/a/b","/c/d","/c/d/e","/c/f" };
	vector<string> ret1 = { "/a","/c/d","/c/f" };
	TESTCASE_ASSERT(sln.removeSubfolders(arr1) == ret1);

	vector<string> arr2 = { "/a","/a/b/c","/a/b/d" };
	vector<string> ret2 = { "/a" };
	TESTCASE_ASSERT(sln.removeSubfolders(arr2) == ret2);

	vector<string> arr3 = { "/a/b/c","/a/b/ca","/a/b/d" };
	vector<string> ret3 = { "/a/b/c","/a/b/ca","/a/b/d" };
	TESTCASE_ASSERT(sln.removeSubfolders(arr3) == ret3);
}