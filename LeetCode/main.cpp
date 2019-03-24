#include <iostream>

extern void Test_AddTwoNumbers();
extern void Test_MultiplyStrings();
extern void Test_TwoSum();

void main()
{
	Test_AddTwoNumbers();
	Test_MultiplyStrings();
	Test_TwoSum();

	std::cin.get();
}