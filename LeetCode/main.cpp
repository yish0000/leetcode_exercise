#include <iostream>
#include "TestCase.h"

void main()
{
	for (size_t i = 0; i < UnitTestCount(); i++)
	{
		TestCase* pTestCase = GetTestCase(i);
		std::cout << "--------------------------------------------------------------------" << std::endl;
		std::cout << "TestCase: " << pTestCase->GetName() << " Start." << std::endl;
		pTestCase->RunTest();
		std::cout << "--------------------------------------------------------------------" << std::endl;
	}

	CleanTestCase();
	std::cin.get();
}