#pragma once

#include <string>
#include <vector>

class TestCase
{
public:
	TestCase(const std::string& name);

	virtual void RunTest() = 0;

	const std::string& GetName() const { return Name; }

	void assertTest(bool bValue, const char* message, const char* filename, int line);

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

size_t UnitTestCount();
TestCase* GetTestCase(size_t i);
void CleanTestCase();