#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		string C;
		int carry = 0;
		string* A = (num1.length() > num2.length()) ? &num1 : &num2;
		string* B = (num1.length() > num2.length()) ? &num2 : &num1;

		string::reverse_iterator itA = A->rbegin();
		string::reverse_iterator itB = B->rbegin();
		C.reserve(A->size() * B->size());

		for (int i = 0; itB != B->rend(); ++itB, i++)
		{
			string T = "";
			for (int n = 0; n < i; n++)
				T.push_back('0');

			for (itA = A->rbegin(); itA != A->rend(); ++itA)
			{
				int curT = char_to_int(*itA) * char_to_int(*itB) + carry;
				T.insert(T.begin(), int_to_char(curT % 10));
				carry = curT / 10;
			}

			if (carry > 0)
			{
				T.insert(T.begin(), int_to_char(carry));
				carry = 0;
			}

			C = add(C, T);
		}

		size_t firstNoneZero = C.find_first_not_of('0');
		if (firstNoneZero != 0)
		{
			if (firstNoneZero == string::npos)
				C = "0";
			else
				C.erase(0, firstNoneZero);
		}

		return C;
	}

	string add(string num1, string num2)
	{
		string C;
		int carry = 0;
		string* A = (num1.length() > num2.length()) ? &num1 : &num2;
		string* B = (num1.length() > num2.length()) ? &num2 : &num1;

		string::reverse_iterator itA = A->rbegin();
		string::reverse_iterator itB = B->rbegin();
		C.reserve(A->size() + B->size());

		for (; itB != B->rend(); ++itB, ++itA)
		{
			int curC = char_to_int(*itA) + char_to_int(*itB) + carry;
			C.insert(C.begin(), int_to_char(curC % 10));
			carry = curC / 10;
		}

		for (; itA != A->rend(); ++itA)
		{
			int curC = char_to_int(*itA) + carry;
			C.insert(C.begin(), int_to_char(curC % 10));
			carry = curC / 10;
		}

		if (carry > 0)
			C.insert(C.begin(), int_to_char(carry));

		return C;
	}

protected:
	inline int char_to_int(char ch)
	{
		return (int)(ch - 48);
	}

	inline char int_to_char(int val)
	{
		return (char)(val + 48);
	}
};

void Test_MultiplyStrings()
{
	Solution sln;
	string A = "8866983";
	string B = "18612484806";
	string C = sln.add(A, B);
	cout << C << endl;

	A = "91022";
	B = "8866983";
	C = sln.multiply(A, B);
	cout << C << endl;
}