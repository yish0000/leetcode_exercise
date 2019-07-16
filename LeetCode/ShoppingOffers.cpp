#include "TestCase.h"

using namespace std;

class SolutionShoppingOffers
{
public:
	int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return shopping(price, special, needs);
	}
    
    int shopping(vector<int>& price, vector<vector<int>>& special, vector<int>& needs)
    {
        int res = 0;
        for (size_t i=0;i<price.size();i++)
        {
            res += price[i]*needs[i];
        }
        
        for (size_t i=0;i<special.size();i++)
        {
            vector<int>& offer = special[i];

            size_t j=0;
            vector<int> clone(needs);
            for (;j<needs.size();j++)
            {
                int remain = clone[j] - offer[j];
                if (remain < 0)
                    break;
                clone[j] = remain;
            }
            
            if (j == needs.size())
                res = std::min(res, offer[j] + shopping(price, special, clone));
        }
        
        return res;
    }
};

RUN_TESTCASE(ShoppingOffers)
{
	SolutionShoppingOffers sln;
	vector<int> prices1 = { 2, 5 };
	vector<vector<int>> special1 = { {3, 0, 5}, {1, 2, 10} };
	vector<int> needs1 = { 3, 2 };
	TESTCASE_ASSERT(sln.shoppingOffers(prices1, special1, needs1) == 14);

	vector<int> prices2 = { 2, 3, 4 };
	vector<vector<int>> special2 = { { 1,1,0,4}, {2,2,1,9} };
	vector<int> needs2 = { 1, 2, 1 };
	TESTCASE_ASSERT(sln.shoppingOffers(prices2, special2, needs2) == 11);
}
