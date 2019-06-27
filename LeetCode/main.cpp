#include <iostream>
#include "TestCase.h"

int main(int argc, char* argv[])
{
	for (size_t i = 0; i < UnitTestCount(); i++)
	{
		TestCase* pTestCase = GetTestCase(i);
		std::cout << "--------------------------------------------------------------------" << std::endl;
		std::cout << "TestCase: " << pTestCase->GetName() << " Start." << std::endl;
		pTestCase->RunTest();
		std::cout << "--------------------------------------------------------------------" << std::endl;
	}

	std::cout << "--------------------------------------------------------------------" << std::endl;
	std::cout << "All assert failed messages:" << std::endl;
	TestCase::PrintAssetFailed();
	std::cout << "--------------------------------------------------------------------" << std::endl;

	CleanTestCase();
	return std::cin.get();
}
