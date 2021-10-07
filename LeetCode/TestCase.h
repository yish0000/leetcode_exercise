#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#include <math.h>

class TestCase
{
public:
	TestCase(const std::string& name);

    virtual void RunTest() = 0;

	const std::string& GetName() const { return Name; }

	void assertTest(bool bValue, const char* message, const char* filename, int line);

	bool doubleEqual(double d1, double d2) { return abs(d1-d2) < 0.0001; }

	template <class T>
	bool vectorComboEqual(std::vector<T>& v1, std::vector<T>& v2)
	{
		if (v1.size() != v2.size())
			return false;

		std::sort(v1.begin(), v1.end());
		std::sort(v2.begin(), v2.end());
		return v1 == v2;
	}

	template <class T>
    bool vectorComboEqual(std::vector<std::vector<T>>& v1, std::vector<std::vector<T>>& v2)
	{
		if (v1.size() != v2.size())
			return false;

		for (size_t i = 0; i < v1.size(); i++)
		{
			std::sort(v1[i].begin(), v1[i].end());
			std::sort(v2[i].begin(), v2[i].end());
		}

		auto compare_func = [](const std::vector<T>& t1, const std::vector<T>& t2)
		{
			if (t1.empty() && t2.empty())
				return true;
			else if (t1.empty())
				return true;
			else if (t2.empty())
				return false;
			else
			{
				if (t1.size() != t2.size())
					return t1.size() < t2.size();
				else
					return t1[0] < t2[0];
			}
		};

		std::sort(v1.begin(), v1.end(), compare_func);
		std::sort(v2.begin(), v2.end(), compare_func);

		return v1 == v2;
	}

	int randomInt(int low, int high);
	float randomUniform();
	float randomFloat(float low, float high);

	template <class T>
	void printVector(const std::vector<T>& arr)
	{
		for (auto i : arr)
			std::cout << i << " ";
		std::cout << std::endl;
	}

	static bool HaveAssetFailed();
	static void PrintAssetFailed();

protected:
	std::string Name;
};

#define RUN_TESTCASE( _case ) \
    class FTC ## _case : public TestCase \
    { \
    public: \
        FTC ## _case() : TestCase(#_case) {} \
        void RunTest(void); \
    }; \
    static FTC ## _case s_TC ## _case; \
    void FTC ## _case::RunTest(void)

#define TESTCASE_ASSERT(expr) \
	{ \
		bool bVal = (expr); \
		assertTest(bVal, #expr, __FILE__, __LINE__); \
	}
